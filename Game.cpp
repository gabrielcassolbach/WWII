#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
#include "Levels/FirstLevel.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{
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
        screenFPS();
        CurrentState() -> input();
        (pGM->getWindow())->clear();
        CurrentState() -> draw();
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
    //this->game_states.top();
    if(!game_states.empty()) 
    {  
        Game_State* wantToDel=NULL;
        wantToDel=game_states.top();
        this->game_states.pop();
        delete(wantToDel);
    }
}

Game_State *Game::CurrentState()
{
    if (game_states.empty())
        return nullptr;
    else
        return game_states.top();
}
