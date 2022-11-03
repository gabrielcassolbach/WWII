#pragma once
#include "../MovingEntity.hpp"


class Character : public MovingEntity
/*Classe que cria personagens*/
{
protected:
    int health;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Character (int ident=-4, double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f, int hp=10, int dam=2);
    virtual ~Character();
    virtual void init () = 0; //Função que inicializa os retangulos

/*SETTERS & GETTERS*/
    void receiveDamage (int dam);
    int getHealth ();

/*METHODS*/
    virtual void update(double timeFraction)=0;
    virtual void collide (Entity* ent2, double inter_x, double inter_y)=0;
};
