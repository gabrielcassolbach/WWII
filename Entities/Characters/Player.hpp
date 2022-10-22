#include "Character.hpp"
#pragma once

class Player: public Character{
private:
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Player();
    ~Player();
    void init ();

/*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape();

/*METHODS*/

};