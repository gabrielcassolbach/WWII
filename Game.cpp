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
        GetInput();
        CurrentState() -> update(0.0166);
        (pGM->getWindow())->clear();
        CurrentState() -> draw();
        (pGM->getWindow())->display();
    }
}

void Game::GetInput()
{
    sf::Event event;
    while ((pGM->getWindow())->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            (pGM->getWindow())->close();
        }
        break;

        case sf::Event::KeyPressed:
        {
            keyPressedAction(event);
        }
        break;

        default:
        {
        }
        break;
        }
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
        dt -= FRAME_RATE;
    }
}

void Game::pushState(Game_State *state)
{
    game_states.push(state);
}

void Game::popState()
{
    this->game_states.top();
    this->game_states.pop();
}

Game_State *Game::CurrentState()
{
    if (game_states.empty())
        return nullptr;
    else
        return game_states.top();
}

void Game::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Right:
    {
        if (level->getPlayer(1)->getLeftDirection())
            level->getPlayer(1)->setLeftDirection(false);
    }
    break;
    case sf::Keyboard::Left:
    {
        level->getPlayer(1)->setLeftDirection(true);
    }
    break;
    case sf::Keyboard::Up:
    {
        level->getPlayer(1)->jump(0.01666);
    }
    break;
    }
}
