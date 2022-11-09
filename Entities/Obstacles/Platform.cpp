#include "Platform.hpp"

Platform::Platform(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
Obstacle(ident, px, py, sx, sy, vx, vy)
{  
}

Platform::~Platform()
{
}

void Platform::update(double timeFraction)
{
    // Empty!
}

void Platform::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Black);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Platform::collide(Entity *ent2, double inter_x, double inter_y)
{
    
}