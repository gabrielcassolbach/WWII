#pragma once

class Entity;
class EntityList;

class Collision_Manager{
private:
    EntityList *pMovingEntitiesList;
    EntityList *pStaticEntitiesList;

public:
    Collision_Manager (EntityList *lMoving, EntityList *lStatic);
    ~Collision_Manager();

/*SETTERS & GETTERS*/
    bool checkCollision(Entity* ent1, Entity* ent2);
    void collision();
};