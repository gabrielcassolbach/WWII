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
    sf::RectangleShape getRectangleShape() const;
    double getPosition_x() const;
    double getPosition_y() const;
    double getSize_x() const;
    double getSize_y() const;

/*METHODS*/
    void drawThis(Graphic_Manager *pGM);
    virtual void update() = 0;
};
