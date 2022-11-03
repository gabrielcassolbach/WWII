#pragma once
#include "Character.hpp"

class Enemy: public Character{
private:

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Enemy(int ident=-5, double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f, int hp=5, int dam=2);
    ~Enemy();

/*SETTERS & GETTERS*/

/*METHODS*/
    virtual void update(double timeFraction) = 0;
    virtual void init() = 0;
};