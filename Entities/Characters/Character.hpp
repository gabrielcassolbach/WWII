#pragma once
#include "../MovingEntity.hpp"


class Character : public MovingEntity
/*Classe que cria personagens*/
{
protected:
    int health;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Character (double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f);
    virtual ~Character();
    virtual void init () = 0; //Função que inicializa os retangulos

/*SETTERS & GETTERS*/

/*METHODS*/
    virtual void update()=0;
};
