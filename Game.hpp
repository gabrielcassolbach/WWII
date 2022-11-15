#pragma once
#include "Menu.hpp"
#include "Levels/Levels.hpp"
#include "Game_State.hpp"
#include <stack>
#define FRAME_RATE 0.01

/*Classe responsável pela mecânica geral do jogo*/

class Game
{
private:
    Levels* level;    
    Menu* menu; 
    std::stack <Game_State*> game_states;
    Graphic_Manager* pGM;
    sf::Clock clock;
    double dt;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/
    void setBackground(string path);

/*METHODS*/
    void initGame_States();
    void chooseLevel(int level_path);
    void execute();
    void GetInput();
    void pushState(Game_State* state);
    void popState();
    Game_State* CurrentState();
    void keyPressedAction (sf::Event event);
    void screenFPS();
};