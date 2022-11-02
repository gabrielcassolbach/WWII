#include "Box.hpp"

Box::Box(int ident, double px, double py, double sx, double sy):
Obstacle(ident, px, py, sx, sy)
{

}

Box::~Box()
{

}

void Box::update()
{
    // Empty!
}

void Box::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Yellow);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}