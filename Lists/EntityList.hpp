#pragma once
#include "List.hpp"
#include "../Entities/Entity.hpp"

namespace Lists
{
    class EntityList
    {
    private:
        List<Entities::Entity *> EntitiesList;

    public:
        /*CONSTRUCTOS & DESTRUCTORS*/
        EntityList();
        ~EntityList();

        /*SETTERS & GETTERS*/
        int getSize();

        /*METHODS*/
        void includeEntity(Entities::Entity *p);
        void drawAll();
        void updateAll(double timeFraction);
        void initAll();
        void destroyAll();
        Entities::Entity *operator[](int index);
    };
}