#pragma once
#include "Entity.hpp"

class MovingEntity : public Entity
{
    // Todos os characters vão ser derivados desta classe
protected:
    double velocity_x, velocity_y;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    MovingEntity(int ident=-2, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    virtual ~MovingEntity();
    
    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void collide(Entity* ent2, double inter_x, double inter_y)=0;
    void collisionMovement(Entity* ent2, double intersection_x, double intersection_y);
};