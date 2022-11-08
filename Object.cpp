#include "Object.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Object::Object()
{
/*Construtora da classe Object
- Faz o ponteiro da janela apontar para aquela cujo qual o objetio fará parte
*/
    pGM = Graphic_Manager::getGraphic_Manager();
}
Object::~Object()
{

}

/*SETTERS & GETTERS*/
Graphic_Manager* Object::getGraphicManager() const{
    return pGM;
}