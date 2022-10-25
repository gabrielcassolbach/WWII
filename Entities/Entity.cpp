#include "Entity.hpp"
#include "../Object.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Entity::Entity(double px, double py, double sx, double sy) : Object()
{
/*Construtora da classe Entity
- Posição inicial será (px, py)
- A posição inicial possui como valor default (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial defautl como (0, 0)
*/
    x=px;
    y=py;
    size_x=sx;
    size_y=sy;
}
Entity::~Entity()
{

}

/*SETTERS & GETTERS*/
double Entity::get_x(){
    return x;
}
double Entity::get_y(){
    return y;
}
double Entity::getSize_x(){
    return size_x;
}
double Entity::getSize_y(){
    return size_y;
}
/*METHODS*/