#pragma once
#include "Game_State.hpp"
#include "Enty.hpp"

#define MAX_NUMBER_OF_RANKEDS 28

class LeaderBoard: public Game_State, public Enty{
    private:
        sf::Text text[MAX_NUMBER_OF_RANKEDS];
        sf::RectangleShape backgroundRectangle;
        sf::Texture backgroundTexture;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        LeaderBoard();
        ~LeaderBoard();

    /*SETTERS & GETTERS*/

    /*METHODS*/
};  