#pragma once
#include "List.hpp"
#include "../Entities/Entity.hpp"

class EntityList{
private:
    List<Entity*> EntitiesList;

public:
/*CONSTRUCTOS & DESTRUCTORS*/
    EntityList();
    ~EntityList();

/*SETTERS & GETTERS*/
    int getSize ();

/*METHODS*/
    void includeEntity(Entity* p);
    void drawAll();
    void updateAll();
    void initAll();
    void destroyAll();
    Entity* operator[](int index);
};
