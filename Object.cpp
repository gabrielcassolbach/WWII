#include "Object.hpp"
#include "../Graphic_Manager.hpp"

Object::Object()
{
    pGM = Managers::Graphic_Manager::getGraphic_Manager();
}

Object::~Object()
{

}

sf::RectangleShape Object::getRectangleShape()
{
    return retangulo;
}