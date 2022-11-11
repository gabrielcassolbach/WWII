#include "Character.hpp"
#include "../Obstacles/Box.hpp"
#include <math.h>
#pragma once

class Player : public Character
{
private:
    const int attackRange;
    double damageCooldownTimer;
    double aceleration;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Player(int ident = 0, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int hp = 10, int dam = 2, const float atkCooldown = 0.0);
    ~Player();

    /*SETTERS & GETTERS*/
    void setVelocity(double vx, double vy);
    double getVelocity_y();
    double getVelocity_x();
    void setVelocity_x(double vx);
    void setVelocity_y(double vy);
    void receiveDamage(int dam);

    /*METHODS*/
    void init();
    void update(double timeFraction);
    void collide(Entity *ent2, double inter_x, double inter_y);
    void jump(double timeFraction);
};