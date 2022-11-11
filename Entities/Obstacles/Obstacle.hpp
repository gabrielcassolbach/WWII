#pragma once
#include "../StaticEntity.hpp"

class Obstacle : public StaticEntity
{ 
protected:
public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Obstacle(int ident = -6, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    ~Obstacle();
    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void update(double timeFraction) = 0;
    virtual void init() = 0;
    virtual void collide(Entity *ent2, double inter_x, double inter_y) = 0;

    virtual void receiveDamage (int dam);
};