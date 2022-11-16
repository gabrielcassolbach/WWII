#include "Platform.hpp"

Platform::Platform(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
Obstacle(ident, px, py, sx, sy, vx, vy)
{
    floatabily_constant = -9.8; 
    velocity_x=vx;
    velocity_y=vx; 
}

Platform::~Platform()
{
}

void Platform::update(double timeFraction)
{
    velocity_y+= GRAVITY + floatabily_constant;

    position_x+=velocity_x;
    position_y+=velocity_y;
}

void Platform::init()
{
    text.loadFromFile("Images/Platform.png");
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setTexture(&text);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Platform::collide(Entity *ent2, double inter_x, double inter_y)
{
    
}