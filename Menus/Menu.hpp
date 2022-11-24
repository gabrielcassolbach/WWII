#pragma once
#include "../Enty.hpp"
#include "../Levels/FirstLevel.hpp"
#include "../Levels/SecondLevel.hpp"
#include "../Game_State.hpp"
#include "Leaderboard.hpp"
#include "MenuCore.hpp"
#define MAX_NUMBER_OF_ITENS 7

class Game;

class Menu : public MenuCore
{
private:
    sf::Text text[MAX_NUMBER_OF_ITENS];
    sf::Text Title;
    sf::Font font;
    sf::RectangleShape backgroundRectangle;
    sf::Texture backgroundTexture;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Menu(Game *pg);
    ~Menu();

    /*SETTERS & GETTERS*/
    void setText();
    void setMenuState(bool menu_state);
    bool getMenuState() const;
    void setBackground();
    
    /*METHODS*/
    void keyPressedAction(sf::Event event);
    void load_game();

    // Polimorfismo Game_State()!
    /*---------------------------*/
    void drawThis(Graphic_Manager *pGM);
    void draw();
    void update(double timeFraction);
    void input();
    void recover();
};