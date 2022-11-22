#pragma once
#include "../Enty.hpp"
#include "../Levels/FirstLevel.hpp"
#include "../Levels/SecondLevel.hpp"
#include "../Game_State.hpp"
#include "Leaderboard.hpp"
#define MAX_NUMBER_OF_ITENS 7

class Game;

class Menu : public Enty, public Game_State
{
private:
    Game* pGame;
    sf::Text text[MAX_NUMBER_OF_ITENS];
    sf::Text Title;
    sf::Font font;
    sf::RectangleShape backgroundRectangle;
    sf::Texture backgroundTexture;
    int level;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Menu(Game *pg);
    ~Menu();

    /*SETTERS & GETTERS*/
    sf::RectangleShape getRectangleShape() const;
    void setText();
    void setMenuState(bool menu_state);
    bool getMenuState() const;
    void setBackground();
    
    /*METHODS*/
    void drawThis(Graphic_Manager *pGM); // drawItself() -> talvez seja um nome melhor!
    void init();
    void keyPressedAction(sf::Event event);
    void load_game();

    // Polimorfismo Game_State()!
    /*---------------------------*/
    void draw();
    void update(double timeFraction);
    void input();
};