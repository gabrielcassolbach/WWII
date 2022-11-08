#pragma once
#include "Player.hpp"

class Enemy : public Character
{
protected:
    Player *pPlayer;
    double playerDistance;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Enemy(int ident = -5, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int hp = 5, int dam = 2, const float atkCooldown = 0.0, Player *pP = nullptr);
    ~Enemy();

    /*SETTERS & GETTERS*/
    void setPPlayer(Player *pP);

    /*METHODS*/
    virtual void update(double timeFraction) = 0;
    virtual void init() = 0;
};