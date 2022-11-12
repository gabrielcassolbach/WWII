#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game():
menu(this)
{
    clock.restart();
    dt = 0.0;

    pGM = Graphic_Manager::getGraphic_Manager();
    execMenu();

    runningMenu=false;
    runningLevelOne=false;
    runningLevelTwo=false;
}
Game::~Game()
{
    pGM = nullptr;
}

/*SETTERS & GETTERS*/
void Game::setRunningMenu (bool m){
    runningMenu=m;
}
void Game::setRunningLevelOne (bool l1){
    runningLevelOne=l1;
}
void Game::setRunningLevelTwo (bool l2){
    runningLevelTwo=l2;
}
bool Game::getRunningLevelOne (){
    return runningLevelOne;
}
bool Game::getRunningLevelTwo (){
    return runningLevelTwo;
}
bool Game::getRunningMenu(){
    return runningMenu;
}

/*METHODS*/
void Game::execLevelOne()
{
    runningLevelOne=true;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.jpg");
    sf::Sprite backgroundSprite;
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
                   keyPressedActionLevel(event);
                }
                case sf::Event::MouseButtonPressed:
                {
                   mousePressedActionLevel(event);
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
    pGM->deleteInstance();
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
                   keyPressedActionLevel(event);
                }
                case sf::Event::MouseButtonPressed:
                {
                   mousePressedActionLevel(event);
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
void Game::keyPressedActionLevel(sf::Event event)
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
void Game::mousePressedActionLevel(sf::Event event){
    switch(event.key.code){
        case sf::Mouse::Left:
        {
            if (runningLevelOne)
                levelOne.getPlayerOne()->attack(levelOne.getCollisionManager());
        }break;
    }
}
void Game::execMenu(){
{
    sf::RectangleShape backgroundMenu;
    backgroundMenu = sf::RectangleShape(sf::Vector2f(1280, 720));
    backgroundMenu.setFillColor(sf::Color::Black);
    backgroundMenu.setPosition(sf::Vector2f(0, 0));
    

    while ((pGM->getWindow())->isOpen())
    {
        runningMenu=true;

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
                   keyPressedActionMenu(event);
                }

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
            //menu.update(0.0166);
            dt -= FRAME_RATE;
        }

        pGM->getWindow()->draw(backgroundMenu);
        //menu.render();

        (pGM->getWindow())->display(); // mostra na tela.
    }

    // deleção do graphic manager ocorrerá aqui.
    pGM -> deleteInstance();
}



}
void Game::keyPressedActionMenu(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Num1:
    {
        runningMenu=false;
        execLevelOne();
    }
    break;
    case sf::Keyboard::Num2:
    {
        runningMenu=0;
        execLevelTwo();
    }
    break;
    }
}



