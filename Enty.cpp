#include "Enty.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Enty::Enty()
{
/*Construtora da classe Enty
- Faz o ponteiro da janela apontar para aquela cujo qual o objeto fará parte
*/
    pGM = Managers::Graphic_Manager::getGraphic_Manager();
}

Enty::~Enty()
{

}

/*SETTERS & GETTERS*/
Managers::Graphic_Manager* Enty::getGraphicManager() const{
    return pGM;
}