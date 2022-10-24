#include "Character.hpp"
#pragma once

class Player: public Character{
private:
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Player(double px=0, double py=0, double vx=0, double vy=0);
    ~Player();
    void init ();

/*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape();

/*METHODS*/

};