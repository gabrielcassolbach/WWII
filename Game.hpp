#pragma once
#include "Menus/Menu.hpp"
#include "Menus/PauseMenu.hpp"
#include "Levels/Level.hpp"
#include "Game_State.hpp"
#include <stack>
#define FRAME_RATE 0.01

/*Classe responsável pela mecânica geral do jogo*/

namespace Levels {class Level;}

namespace Menus {class Menu;}

class Game
{  
private:
    Levels::Level* level;    
    Menus::Menu* menu; 
    std::stack <Game_State*> game_states;

    Managers::Graphic_Manager* pGM;
    sf::Clock clock;
    double dt;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/

/*METHODS*/
    void initGame_States();
    void execute();
    void pushState(Game_State* state);
    void popState();
    void screenFPS();
    Game_State* CurrentState();
};


