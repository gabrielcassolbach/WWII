#pragma once
#include "Entity.hpp"

class MovingEntity : public Entity
{
    // Todos os characters vão ser derivados desta classe
protected:
    double velocity_x, velocity_y;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    MovingEntity(double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    virtual ~MovingEntity();
    
    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void update() = 0;
    virtual void init() = 0;
};