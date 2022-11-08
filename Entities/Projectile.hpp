#pragma once
#include "Characters/Character.hpp"

class Projectile : public MovingEntity
{
private:
    bool active;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Projectile(int ident = 4, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int dam = 1.0);
    ~Projectile();

    /*SETTERS & GETTERS*/
    bool getActive();
    void setActive(bool ac);

    /*METHODS*/
    void projectileReset(double px, double py, double vx, double vy);
    void update(double timeFraction);
    void init();
    void collide(Entity *ent2, double inter_x, double inter_y);
};