#pragma once
#include <list>
#include <vector>
#include "../Entities/Characters/Character.hpp"
#include "../Entities/Obstacles/Obstacle.hpp"

namespace Entities
{
    class Entity;
}

namespace Lists
{
    class EntityList;
}

namespace Managers
{

    class Collision_Manager
    {
    private:
        std::vector<Entities::Entity *> movingEntitiesList;
        std::list<Entities::Entity *> staticEntitiesList;

    public:
        Collision_Manager();
        ~Collision_Manager();
        void init(Lists::EntityList *lMoving, Lists::EntityList *lStatic);

        /*SETTERS & GETTERS*/
        void collision();
    };

}