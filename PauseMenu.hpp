#pragma once
#include "Enty.hpp"
#include "Game_State.hpp"
#include "Levels/FirstLevel.hpp"

class SecondLevel;

#define ITENS_PAUSE_MENU 3

class PauseMenu: public Enty, public Game_State
{
private:
    Game* pGame;
    sf::Text text[ITENS_PAUSE_MENU];
    sf::Font font;
    sf::RectangleShape backgroundRectangle;
    sf::Texture backgroundTexture;
    int level;
    FirstLevel* levelOne;
    SecondLevel* levelTwo;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    PauseMenu(Game *pg, FirstLevel* lvl);
    PauseMenu(Game *pg, SecondLevel* level);
    ~PauseMenu();

    /*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape() const;
    void setText();
    void setMenuState(bool menu_state);
    bool getMenuState() const;
    void setBackground();
    void setLevel(int lvl);
    void getLevel();
    
    /*METHODS*/
    void drawThis(Graphic_Manager *pGM); // drawItself() -> talvez seja um nome melhor!
    void init();
    void keyPressedAction(sf::Event event);
    void save_game();

    // Polimorfismo Game_State()!
    /*---------------------------*/
    void draw();
    void update(double timeFraction);
    void input();
};