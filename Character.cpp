#include "Character.hpp"

Character::Character()
{
    
}

Character::~Character()
{

}

void Character::imprimir_se(Graphic_Manager *pGM)
{
    pGM -> draw(dynamic_cast<Object*>(this)); 
    // observação:
    /*
        por causa do polimorfismo, é necessário o dynamic cast.
        se eu não derivasse nada da classe -> static_cast
    */
}