#include "Graphic_Manager.hpp"
#include "../Object.hpp"


void Graphic_Manager::draw(Object *pObject)
{
    window->draw(pObject->getRectangleShape());

}


Graphic_Manager* Graphic_Manager::instance = nullptr;


