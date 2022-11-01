#pragma once
#include "../StaticEntity.hpp"

class Obstacle : public StaticEntity
{
protected:

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Obstacle(double px = 0.0f, double py = 0.0f, double sx=0.0f, double sy=0.0f);
    ~Obstacle();
    /*SETTERS & GETTERS*/

    /*METHODS*/
    virtual void update() = 0;
    virtual void init() = 0;
};