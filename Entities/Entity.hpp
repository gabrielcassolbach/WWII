#pragma once
#include "../Object.hpp"

class Entity : public Object
{
protected:
    double position_x, position_y;
    double size_x, size_y;
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Entity(double px = 0.0f, double py = 0.0f, double sx=0.0f, double sy=0.0f);
    virtual ~Entity();
    virtual void init() = 0;

/*SETTERS & GETTERS*/
    virtual sf::RectangleShape getRectangleShape() = 0;
    double getPosition_x();
    double getPosition_y();
    double getSize_x();
    double getSize_y();

/*METHODS*/
    virtual void drawThis(Graphic_Manager *pGM) = 0;
    virtual void update() = 0;
};
