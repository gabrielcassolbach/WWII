#include "Cannon.hpp"

#define CANNON_ACELERATION 2

Cannon::Cannon(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
Obstacle(ident, px, py, sx, sy, vx, vy)
{
    acceleration=CANNON_ACELERATION;
    crossable=1;
}
Cannon::~Cannon()
{
}

double Cannon::getAcceleration(){
    return acceleration;
}

void Cannon::update(double timeFraction)
{    
    velocity_x = 0.0f;
    velocity_y += 9.8f * timeFraction;
    position_x += (velocity_x);
    position_y += (velocity_y);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Cannon::init()
{
    text.loadFromFile("Images/Cannon.png");
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setTexture(&text);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Cannon::collide(Entity *ent2, double inter_x, double inter_y)
{
    int id = ent2 -> getId();      
       
    if(id == 3)
        collisionMovement(ent2, inter_x, inter_y); 

}