#include "Entity.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Entity::Entity(double px, double py, double vx, double vy) : Object()
{
/*Construtora da classe Entity
- Posição inicial será (px, py)
- A posição inicial possui como valor default (0, 0)
- Velocidade inicial será dada por (vx, vy)
- A velocidade inicial default é (0, 0)
*/

    x=px;
    y=py;
    velocity_x=vx;
    velocity_y=vy;
}
Entity::~Entity()
{

}

/*SETTERS & GETTERS*/

/*METHODS*/