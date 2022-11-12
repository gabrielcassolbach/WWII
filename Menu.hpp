#pragma once
#include "Enty.hpp"

class Game;

class Menu: public Enty{
private:
    Game* pGame;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Menu(Game* pg);
    ~Menu();
    void init ();

    /*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape() const;

    /*METHODS*/
    void drawThis(Graphic_Manager* pGM);
};