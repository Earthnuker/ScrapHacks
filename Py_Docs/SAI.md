# SAI

- *GetStateChar*: `<built-in function GetStateChar>`
```
GetStateChar(string nameEntity) : Devuelve el estado de la IA del personaje.

```
- *AddVehicleRace*: `<built-in function AddVehicleRace>`
```
bool AddVehicleRace(cWithLifeEntity *entidad) : Asigna entidad como perteneciente a carrera.
```
- *SetStateVehicle*: `<built-in function SetStateVehicle>`
```
SetStateVehicle(0, string nameAgent) : Estado sin movimiento ni disparo.
 SetStateVehicle(1, float posObjX, float posObjY, float posObjZ, radiusObj, string nameAgent) : Estado alcanzar posici�n.
 SetStateVehicle(2, string nameObjectiveDin, string nameAgent) : Estado persecuci�n enemigo.
 SetStateVehicle(3, string nameAgent) : Estado en ruta.
 SetStateVehicle(4, string nameAgent) : Estado tr�fico.
 SetStateVehicle(5, string nameAgent, float distStop) : Estado hu�da con parada.
 SetStateVehicle(6, float posObjX, float posObjY, float posObjZ, radiusObj, string nameAgent) : Estado alcanzar meta en carrera.
 SetStateVehicle(7, string nameObjectiveDin, string nameAgent) : Estado persecuci�n.
 SetStateVehicle(8, string nameObjectiveDin, string nameAgent) : Estado persecuci�n enemigo con uso de hook.

```
- *EnableAIChar*: `<built-in function EnableAIChar>`
```
EnableAIChar(string nameEntity, int enable, int stupidPathfinding) : Habilita la IA del personaje indicando caracter�sticas asociadas al movimiento).
```
- *BuildGraph*: `<built-in function BuildGraph>`
```
BuildGraph(int numNodesRadius, float sizeNodeX, float sizeNodeY, float sizeNodeZ) : Crea el Grafo asociado al Pathfinding
```
- *AnalizeMap*: `<built-in function AnalizeMap>`
```
AnalizeMap(float sizeNode) : Analiza caracter�sticas mapa.
```
- *SetStateChar*: `<built-in function SetStateChar>`
```
SetStateChar(0, string nameAgent) : Estado sin movimiento ni disparo.
 SetStateChar(1, string nameAgent, float vel, int withStopTemp) : Estado en ruta.
 SetStateChar(2, string nameAgent, string nameObjective, float vel) : Estado en persecuci�n objetivo con acci�n.
 SetStateChar(3, string nameAgent, string nameObjective, float vel) : Estado en persecuci�n objetivo sin acci�n.
 SetStateChar(4, string nameAgent, float posObjX, float posObjY, float posObjZ, float orientX, float orientY, float orientZ, float radiusObj, float velObj) : Estado ir a un punto con orientaci�n final.
 SetStateChar(5, string nameAgent, string nameObjective, float vel) : Estado hu�da de otro personaje.
 SetStateChar(6, string nameAgent, float centerPatrolZone.x, float centerPatrolZone.y, float centerPatrolZone.z, float radiusPatrolZone, float vel, int withStopTemp) : Estado patrulla de zona.
 SetStateChar(7, string nameAgent, string nameObjective, float vel) : Estado en persecuci�n objetivo con acci�n.
```
- *AnalizeGraph2D*: `<built-in function AnalizeGraph2D>`
```
AnalizeGraph2D() : Analiza caracter�sticas grafo 2D.
```
- *GetNextRacePoint*: `<built-in function GetNextRacePoint>`
```
(point) GetNextRacePoint(initialPoint, minDist, maxDist) : A partir de un punto inicial 'initialPoint', una distancia m�nima 'minDist' y una distancia m�xima 'maxDist', devuelve un punto aleatorio a partir del grafo 3D de la IA en el interior actual.
```
- *GetOD*: `<built-in function GetOD>`
- *SetRotStaticObj*: `<built-in function SetRotStaticObj>`
```
bool SetRotStaticObj(float maxVelRot, float limIncVelRot) : Asigna rotaciones para movimiento hacia objetivo est�tico.
```
- *IniAI*: `<built-in function IniAI>`
```
IniAI(levelPath) : Inicializa AI para un nivel.
```
- *GetStateVehicle*: `<built-in function GetStateVehicle>`
```
GetStateVehicle(string nameEntity) : Devuelve el estado de la IA del veh�culo.
 0 : Estado sin movimiento ni disparo.
 1 : Estado alcanzar posici�n.
 2 : Estado persecuci�n enemigo.
 3 : Estado en ruta.
 4 : Estado tr�fico.
 5 : Estado hu�da con parada.
 6 : Estado alcanzar meta en carrera.
 7 : Estado persecuci�n.
 8 : Estado persecuci�n enemigo con uso de hook.
 9 : Estado sin movimiento ni disparo por estar objetivo en posici�n inv�lida.

```
- *BuildGraph2D*: `<built-in function BuildGraph2D>`
```
BuildGraph2D(int numNodesRadius, float sizeNodeX, float sizeNodeY, float sizeNodeZ) : Crea el Grafo asociado al Pathfinding 2D
```
- *AnalizeTraffic*: `<built-in function AnalizeTraffic>`
```
AnalizeTraffic() : Analiza caracter�sticas tr�fico.
```
- *SetInertia*: `<built-in function SetInertia>`
```
void SetInertia(bool inertia) : Indica si la nave tiene inercia.
```
- *InitVehicleRace*: `<built-in function InitVehicleRace>`
```
InitVehicleRace() : Inicializa carrera de veh�culos.
```
- *GetNearestItemLife*: `<built-in function GetNearestItemLife>`
```
(itemName) GetNearestItemLife(vehicleName)) : Devuelve el item de vida m�s cercano a una nave dada.
```
- *EnableAIVehicle*: `<built-in function EnableAIVehicle>`
```
EnableAIVehicle(string nameEntity, int enable, int controlStrafe, int controlBrake, int stupidPathfinding) : Habilita la IA del veh�culo indicando caracter�sticas asociadas al movimiento).
```
- *AnalizeGraph*: `<built-in function AnalizeGraph>`
```
AnalizeGraph() : Analiza caracter�sticas grafo.
```
- *GetRandomVisibilityPoint*: `<built-in function GetRandomVisibilityPoint>`
```
(point) GetRandomVisibilityPoint() : Devuelve un punto aleatorio del grafo de puntos de visibilidad.
```
- *GetReposCharPos*: `<built-in function GetReposCharPos>`
```
(x,y,z) GetReposCharPos((x,y,z) ,EntityClass,[,EntityName]) : Obtiene un punto de reposicion de personaje (si entidad, se asigna).
 Retorna (None) si falla
```


