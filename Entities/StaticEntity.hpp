#pragma once
#include "Entity.hpp"

class StaticEntity : public Entity
{
    // Todos os obstáculos serão derivados desta classe
protected:
    // Empty!

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    StaticEntity(int ident=-3, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f);
    ~StaticEntity();

    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void collide(Entity* ent2, double inter_x, double inter_y){ };
    virtual void update(double timeFraction) = 0;
    virtual void init() = 0;
};