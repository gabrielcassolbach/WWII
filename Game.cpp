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
        cout << "after update" << endl;
        CurrentState() -> input();
        cout << "after input" << endl;
        (pGM->getWindow())->clear();
        cout << "after clear" << endl;
        CurrentState() -> draw();
        cout << "after draw" << endl;
        (pGM->getWindow())->display();
        cout << "after display" << endl;
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
        cout << "before update" << endl;   
        CurrentState() -> update(0.0166); 
        cout << "after update" << endl; 
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
        this->game_states.pop();
}

Game_State *Game::CurrentState()
{
    if (game_states.empty())
        return nullptr;
    else
        return game_states.top();
}
