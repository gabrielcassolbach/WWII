#pragma once
#include "Entity.hpp"

class StaticEntity: public Entity{
//Todos os objetos serão derivados desta classe
protected:
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    StaticEntity(double px = 0.0f, double py = 0.0f, double sx= 0.0f, double sy=0.0f);
    ~StaticEntity();

/*SETTERS & GETTERS*/

/*METHODS*/
};