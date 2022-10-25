#pragma once
#include "List.hpp"
#include "../Entities/Entity.hpp"
#include "../Object.hpp"

class EntityList{
private:
    List<Entity*> EntitiesList;

public:
/*CONSTRUCTOS & DESTRUCTORS*/
    EntityList();
    ~EntityList();

/*SETTERS & GETTERS*/

/*METHODS*/
    void includeEntity(Entity* p);
    void drawAll();
    void updateAll();
    void initAll();
    void destroyAll();
};
