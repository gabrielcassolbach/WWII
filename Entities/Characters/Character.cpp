#include "Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Character::Character()
{  

}
Character::~Character()
{

}

/*SETTERS & GETTERS*/

/*METHODS*/
void Character::drawThis(Graphic_Manager *pGM)
{
/*Função que desenha o objeto atual na tela
- Proveniente da função abstrata do "objeto".
- Chama uma função mais específica que designa a "tela" na qual o desenho será feito
*/
    pGM -> draw(dynamic_cast<Object*>(this)); 
}
void Character::update()
{
    
}