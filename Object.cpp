#include "Object.hpp"

Object::Object()
{
    pGM = Graphic_Manager::getGraphic_Manager();
}

Object::~Object()
{

}

sf::RectangleShape Object::getRectangleShape()
{
    return retangulo;
}