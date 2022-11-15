#pragma once
#include "Enty.hpp"
#include "Game_State.hpp"
#define MAX_NUMBER_OF_ITENS 4

class Game;

class Menu : public Enty, public Game_State
{
private:
    Game *pGame;
    sf::Text text[MAX_NUMBER_OF_ITENS];
    sf::Text Title;
    sf::Font font;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Menu(Game *pg);
    ~Menu();

    /*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape() const;
    void setText();
    void setMenuState(bool menu_state);
    bool getMenuState() const;
    
    /*METHODS*/
    void drawThis(Graphic_Manager *pGM); // drawItself() -> talvez seja um nome melhor!
    void init();
    void moveUp();
    void moveDown();
};