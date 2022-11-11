#include "Entity.hpp"
#include "../Enty.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
/*
- Posição inicial será (px, py)
- A posição inicial possui como valor default (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial defautl como (0, 0)
*/
Entity::Entity(int ident, double px, double py, double sx, double sy, double vx, double vy) : Enty()
{
    id = ident;
    position_x = px;
    position_y = py;
    size_x = sx;
    size_y = sy;
    velocity_x=vx;
    velocity_y=vy;
}
Entity::~Entity()
{
}

/*SETTERS & GETTERS*/
double Entity::getPosition_x() const
{
    return position_x;
}

double Entity::getPosition_y() const
{
    return position_y;
}

double Entity::getSize_x() const
{
    return size_x;
}

double Entity::getSize_y() const
{
    return size_y;
}

const int Entity::getId() const
{
    return id;
}

double Entity::getVelocity_x() const
{
    return velocity_x; 
}

double Entity::getVelocity_y() const
{
    return velocity_y; 
}

sf::RectangleShape Entity::getRectangleShape() const
{
    return retangulo;
}

void Entity::setPosition_x(double px)
{
    position_x = px;
}

void Entity::setPosition_y(double py)
{
    position_y = py;
}

void Entity::setVelocity_x(double vx){
    velocity_x=vx;
}

void Entity::setVelocity_y(double vy){
    velocity_y=vy;
}


/*METHODS*/
void Entity::drawThis(Graphic_Manager *pGM)
{
    pGM->draw(dynamic_cast<Enty *>(this));
}
