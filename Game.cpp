#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{
    clock.restart();
    dt = 0.0;

    pGM = Graphic_Manager::getGraphic_Manager();
    execLevelOne();
}

Game::~Game()
{
    pGM = nullptr;
}

/*METHODS*/

void Game::waitForInput()
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

void Game::setBackground(string path)
{
    backgroundTexture.loadFromFile(path);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);
}

void Game::execLevelOne()
{

    setBackground("background.jpg");

    while ((pGM->getWindow())->isOpen())
    {
        waitForInput();

        (pGM->getWindow())->clear();

        if (dt < FRAME_RATE)
        {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else
        {
            levelOne.update(0.0166);
            dt -= FRAME_RATE;
        }

        pGM->getWindow()->draw(backgroundSprite);
        levelOne.render();

        (pGM->getWindow())->display(); 
    }

    pGM->deleteInstance();
}

void Game::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Right:
    {
        if (levelOne.getPlayerOne()->getLeftDirection())
            levelOne.getPlayerOne()->setLeftDirection(false);
    }
    break;
    case sf::Keyboard::Left:
    {
        levelOne.getPlayerOne()->setLeftDirection(true);
    }
    break;
    case sf::Keyboard::Up:
    {
        levelOne.getPlayerOne()->jump(0.01666);
    }
    break;
    }
}
