#include "Character.hpp"
#pragma once

class Player: public Character{
private:
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Player(double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f);
    ~Player();
    void init ();

/*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape();

/*METHODS*/
    void update ();
};