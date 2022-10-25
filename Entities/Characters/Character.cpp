#include "Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Character::~Character()
{
/*Destrutora da classe Character
*/

}
Character::Character(double px, double py, double vx, double vy, double sx, double sy):
Entity(px, py, vx, vy, sx, sy){
/*Construtora da classe character
- Posição inicial será (px, py)
- Posição como default é (0, 0)
- Velocidade inicial será (vx, vy)
- Velocidade como default é (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial default como (0, 0)
*/
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
