#include "Character.hpp"
using namespace Entities;

Character::Character(int vida = 0, int dano = 0) : 
Entity()
{
    
}

Character::~Character()
{

}

void Character::imprimir_se(Managers::Graphic_Manager *pGM)
{
    pGM -> draw(dynamic_cast<Object*>(this)); 
    // observação:
    /*
        por causa do polimorfismo, é necessário o dynamic cast.
        se eu não derivasse nada da classe -> static_cast
    */
}