#pragma once
#include <list>
#include <vector>
#include "../Entities/Characters/Character.hpp"
#include "../Entities/Obstacles/Obstacle.hpp"

class Entity;
class EntityList;

class Collision_Manager{
private:
    std::vector<Entity*> movingEntitiesList;
    std::list<Entity*> staticEntitiesList;

public:
    Collision_Manager ();
    ~Collision_Manager();
    void init(EntityList *lMoving, EntityList *lStatic);

/*SETTERS & GETTERS*/
    void collision();
};