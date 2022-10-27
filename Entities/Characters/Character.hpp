#pragma once
#include "../MovingEntity.hpp"


class Character : public MovingEntity
/*Classe que cria personagens*/
{
protected:
    int health;
    int damage;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Character (double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f);
    virtual ~Character();
    virtual void init () = 0; //Função que inicializa os retangulos

/*SETTERS & GETTERS*/
    virtual sf::RectangleShape getRectangleShape() = 0;

/*METHODS*/
    void drawThis(Graphic_Manager *pGM);
    virtual void update()=0;
};
