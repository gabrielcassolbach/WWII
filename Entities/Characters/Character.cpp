#include "Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Character::~Character()
{
/*Destrutora da classe Character
*/

}
Character::Character(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp):
MovingEntity(ident, px, py, sx, sy, vx, vy)
{
/*Construtora da classe character
- Posição inicial será (px, py)
- Posição como default é (0, 0)
- Velocidade inicial será (vx, vy)
- Velocidade como default é (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial default como (0, 0)
*/
    health=hp;
}

/*SETTERS & GETTERS*/

/*METHODS*/

