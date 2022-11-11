#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{
    clock.restart();
    dt = 0.0;

    pGM = Graphic_Manager::getGraphic_Manager();
    execLevelTwo();

    runningLevelOne=false;
    runningLevelTwo=false;
}

Game::~Game()
{
    pGM = nullptr;
}

/*METHODS*/
void Game::execLevelOne()
{
    runningLevelOne=true;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    sf::Sprite backgroundSprite;
    sf::Vector2u size = backgroundTexture.getSize();
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);

    while ((pGM->getWindow())->isOpen())
    {
        sf::Event event;
        while ((pGM->getWindow())->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    (pGM->getWindow())->close();
                    return;
                } break;
                case sf::Event::KeyPressed:
                {
                   keyPressedAction(event);
                }
                case sf::Event::MouseButtonPressed:
                {
                   mousePressedAction(event);
                }break;

                default:
                {
                }
                break;
                }
        }

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

        (pGM->getWindow())->display(); // mostra na tela.
    }

    // deleção do graphic manager ocorrerá aqui.
    pGM -> deleteInstance();
}

void Game::execLevelTwo()
{
    runningLevelOne=true;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    sf::Sprite backgroundSprite;
    sf::Vector2u size = backgroundTexture.getSize();
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);

    while ((pGM->getWindow())->isOpen())
    {
        runningLevelTwo=true;

        sf::Event event;
        while ((pGM->getWindow())->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    (pGM->getWindow())->close();
                    return;
                } break;
                case sf::Event::KeyPressed:
                {
                   keyPressedAction(event);
                }
                case sf::Event::MouseButtonPressed:
                {
                   mousePressedAction(event);
                }break;

                default:
                {
                }
                break;
                }
        }

        (pGM->getWindow())->clear();

        if (dt < FRAME_RATE)
        {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else
        {
            levelTwo.update(0.0166);
            dt -= FRAME_RATE;
        }

        pGM->getWindow()->draw(backgroundSprite);
        levelTwo.render();

        (pGM->getWindow())->display(); // mostra na tela.
    }

    // deleção do graphic manager ocorrerá aqui.
    pGM -> deleteInstance();
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

void Game::mousePressedAction(sf::Event event){
    switch(event.key.code){
        case sf::Mouse::Left:
        {
            if (runningLevelOne)
                levelOne.getPlayerOne()->attack(levelOne.getCollisionManager());
        }break;
    }
}


