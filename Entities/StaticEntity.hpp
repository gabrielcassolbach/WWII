#pragma once
#include "Entity.hpp"

namespace Entities
{
    // Todos os obstáculos serão derivados desta classe
    class StaticEntity : public Entity
    {
    protected:
    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        StaticEntity(int ident = -3, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
        ~StaticEntity();

        /*SETTERS & GETTERS*/
        int getDamage() const;

        /*METHODS*/
        virtual void collide(Entity *ent2, double inter_x, double inter_y) = 0;
        virtual void update(double timeFraction) = 0;
        virtual void init() = 0;
        void collisionMovement(Entity *ent2, double intersection_x, double intersection_y);
    };
}