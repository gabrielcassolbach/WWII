#pragma once
#include "../Entity.hpp"


class Character : public Entity
/*Classe que cria personagens*/
{
protected:
    int health;
    int damage;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Character();
    ~Character();
    void init () = 0; //Função que inicializa os retangulos

/*SETTERS & GETTERS*/
    virtual sf::RectangleShape getRectangleShape() = 0;

/*METHODS*/
    void drawThis(Graphic_Manager *pGM);
    void update();
};
