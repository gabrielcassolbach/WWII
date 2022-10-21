#include "Object.hpp"

Object::Object()
{
    pGM = Graphic_Manager::getGraphic_Manager();
    retangulo = sf::RectangleShape(sf::Vector2f(100, 100));
    retangulo.setFillColor(sf::Color::Blue);
}

Object::~Object()
{

}

sf::RectangleShape Object::getRectangleShape()
{
    return retangulo;
}