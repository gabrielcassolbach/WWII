#pragma once
#include "../Enty.hpp"
#include <string>

#define GRAVITY 9.8f

class Entity : public Enty
{
protected:
    int id;
    double position_x, position_y;
    double size_x, size_y;
    double velocity_x, velocity_y;
    sf::RectangleShape retangulo;

    sf::Texture text;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Entity(int ident = -1, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx=0.0, double vy=0.0);
    virtual ~Entity();

    /*SETTERS & GETTERS*/
    const int getId() const;
    sf::RectangleShape getRectangleShape() const;
    double getPosition_x() const;
    double getPosition_y() const;
    double getSize_x() const;
    double getSize_y() const;
    double getVelocity_x() const;
    double getVelocity_y() const;

    void setPosition_x(double px);
    void setPosition_y(double py);
    void setVelocity_x(double vx);
    void setVelocity_y(double vy);

    virtual int getDamage() const=0;
    virtual int getHealth(){}

    /*METHODS*/
    void drawThis(Graphic_Manager *pGM);
    virtual void update(double timeFraction) = 0;
    virtual void init() = 0;
    virtual void collide(Entity *ent2, double inter_x, double inter_y) = 0;
};
