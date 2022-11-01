#pragma once
#include "Character.hpp"

class Enemy: public Character{
private:

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Enemy(double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f);
    ~Enemy();

/*SETTERS & GETTERS*/

/*METHODS*/
    virtual void update() = 0;
    virtual void init() = 0;
};