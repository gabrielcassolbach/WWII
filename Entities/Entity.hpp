#pragma once

#include "../Object.hpp"

class Entity : public Object
{
protected:
    double x, y;
    double velocity_x, velocity_y;
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Entity(double px = 0.0f, double py = 0.0f, double vx = 0.0f, double vy = 0.0f);
    virtual ~Entity();
    void init() = 0;

/*SETTERS & GETTERS*/
    virtual sf::RectangleShape getRectangleShape() = 0;

/*METHODS*/
    void drawThis(Graphic_Manager *pGM) = 0;
    virtual void update() = 0;
};
