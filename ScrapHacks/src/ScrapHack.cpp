
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>
#include <fstream>
// #include <Python.h>
#include <Windows.h>

using namespace std;

#include "D3D8_Hook.hpp"
#include "Hook.hpp"
#include "Py_Utils.hpp"
#include "REPL.hpp"
#include "Scrapland.hpp"
#include "Structures.hpp"
#include "Util.hpp"
#include "Py_Mod.hpp"

bool initialized = false;
bool running = true;

HMODULE hMod = nullptr;

void DllUnload();
int hooked_console(const char *);
void hook_exit();

void setup_hooks()
{
    Hook::addr(P_SCRAP_EXIT, hook_exit);
    Hook::addr(P_CON_HANDLER, hooked_console);
}

void MainLoop()
{
    setup_hooks();
    overlay = true;
    cout << "[*] Starting main Loop" << endl;
    cout << endl;
    cout << "[F2 ] Redirect game console to ScapHacks console" << endl;
    cout << "[F3 ] Unload ScrapHacks" << endl;
    cout << "[F5 ] Show Overlay" << endl;
    cout << "[F6 ] Show Alarm status" << endl;
    cout << "[F7 ] Set Money to 0x7fffffff" << endl;
    cout << "[F8 ] Dump python modules" << endl;
    cout << "[F9 ] Dump Entity hashtable" << endl;
    cout << "[F10] Enable python tracing" << endl;
    cout << "[ F ] \"Handbrake\" (*Will* crash the game after some time!)"
         << endl;

    while (running)
    {
        Sleep(100);
        while (key_down('F'))
        {
            scrap_exec("dbg.brake()");
        }
        if (key_down_norepeat(VK_F3))
        {
            break;
        }

        if (key_down_norepeat(VK_F7))
        {
            int32_t *money = ptr<int32_t>(P_WORLD, O_MONEY);
            money[0] = 0x7fffffff;
        }

        if (key_down_norepeat(VK_F8))
        {
            cout << "Not yet implemented" << endl;
        }

        if (key_down_norepeat(VK_F9))
        {
            cout << "Entities:" << endl;
            dump_ht(ptr<HashTable<Entity>>(P_WORLD, O_ENTS));
            cout << "Entity Lists:" << endl;
            dump_ht(ptr<HashTable<EntityList>>(P_WORLD, O_ENTLISTS));
        }
        if (key_down_norepeat(VK_F10))
        {
            scrap_exec("dbg.settrace()");
        }
    }
    FreeLibraryAndExitThread(hMod, 0);
}

void InitConsole()
{
    char me[1024];
    GetModuleFileNameA(hMod, me, 1024);
    SetupConsole(me);
}

int hooked_console(const char *cmd)
{
    typedef decltype(&hooked_console) t_func;
    if (cmd[0] == '$')
    {
        handle_command(++cmd);
        return 0;
    }
    shared_ptr<Hook> hook = Hook::get(hooked_console);
    int ret = hook->func<t_func>(cmd);
    return ret;
}

void hook_exit()
{
    typedef decltype(&hook_exit) t_func;
    shared_ptr<Hook> hook = Hook::get(hook_exit);
    DllUnload();
    HWND hMainWindow = ptr<HWND>(0x7FA830, 0x7c)[0];
    SendMessage(hMainWindow, WM_CLOSE, 0, 0);
    return;
}

void DllInit(HMODULE mod)
{
    hMod = mod;
    char mfn[1024];
    GetModuleFileNameA(0, mfn, 1024);
    Py = get_modules(P_PY_MODS);
    cout << "[+] ScrapHacks v0.1 Loaded in " << mfn << " (PID: " << std::hex
         << GetCurrentProcessId() << std::dec << ")" << endl;

    initialized = true;
    cout << "[*] World: " << ptr<void>(P_WORLD, 0) << endl;
    cout << "[*] Importing python dbg module" << endl;
    scrap_exec("import dbg");
    scrap_log(INFO_COLOR, "=== ScrapHacks loaded! ===\n");
    scrap_log(INFO_COLOR, "=== Use '$help' for help! ===\n");
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainLoop, NULL, 0, 0);
    cout << "[*] Starting message pump" << endl;
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return;
}

void DllPreInit()
{
    Sleep(100);
    InitConsole();
    InitPyMod();
}

void DllUnload()
{
    SetConsoleCtrlHandler(NULL, false);
    unhook_d3d8();
    Hook::clear();
    scrap_log(0xff0000, "ScrapHacks unloaded!\n");
    cout << "[+] ScrapHacks unloaded, you can now close the console!" << endl;
    FreeConsole();
    DestroyWindow(GetConsoleWindow());
    return;
}