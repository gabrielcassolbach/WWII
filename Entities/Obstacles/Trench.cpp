#include "Trench.hpp"

Trench::Trench(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
Obstacle(ident, px, py, sx, sy, vx, vy)
{
}

Trench::~Trench()
{
}

void Trench::update(double timeFraction)
{    
    velocity_x = 0.0f;
    velocity_y += 9.8f * timeFraction;
    position_x += (velocity_x);
    position_y += (velocity_y);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Trench::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Magenta);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Trench::collide(Entity *ent2, double inter_x, double inter_y)
{
    int id = ent2 -> getId();      
       
    if(id == 3)
        collisionMovement(ent2, inter_x, inter_y); 

}