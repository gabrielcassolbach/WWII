#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
#include "Levels/FirstLevel.hpp"
#include "time.h"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{
    srand(time(nullptr));
    clock.restart();
    dt = 0.0;

    initGame_States();
    pGM = Graphic_Manager::getGraphic_Manager();
    execute();
}

Game::~Game()
{
    pGM = nullptr;
}

/*METHODS*/
void Game::initGame_States()
{
    game_states.push(new Menu(this));
}

void Game::execute()
{
    while ((pGM->getWindow())->isOpen())
    {
        screenFPS(); cout << "UPDATE" << endl;
        CurrentState() -> input(); cout << "INPUT" << endl;
        (pGM->getWindow())->clear();
        CurrentState() -> draw(); cout << "DRAW" << endl;
        (pGM->getWindow())->display();
    }
}

void Game::screenFPS()
{
    if (dt < FRAME_RATE)
    {
        dt += clock.getElapsedTime().asSeconds();
        clock.restart();
    }
    else
    {
        CurrentState() -> update(0.0166);     
        dt -= FRAME_RATE;
    }
}

void Game::pushState(Game_State *state)
{
    game_states.push(state);
}

void Game::popState()
{
    if(!game_states.empty()) 
        this->game_states.pop();
}

Game_State *Game::CurrentState()
{
    if (game_states.empty())
        return nullptr;
    else
        return game_states.top();
}
