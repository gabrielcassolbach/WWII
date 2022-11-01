#pragma once
#include "Entity.hpp"

class StaticEntity : public Entity
{
    // Todos os obstáculos serão derivados desta classe
protected:
    // Empty!

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    StaticEntity(double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f);
    ~StaticEntity();

    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void update() = 0;
    virtual void init() = 0;

};