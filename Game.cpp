#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
#include "Levels/FirstLevel.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game() : menu(this)
{
    clock.restart();
    dt = 0.0;
    
    pGM = Graphic_Manager::getGraphic_Manager();
    execLevelOne();
    //execMenu(); // eu mando acessar o loop executar();
}

Game::~Game()
{
    pGM = nullptr;
}

/*METHODS*/

void Game::execute()
{
    if(menu.getMenuState())
    {
        execMenu();
    }




}


void Game::chooseLevel(int level_path)
{
    if (level_path == 1)
        level = new FirstLevel();
    //else
    // level = new SecondLevel
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

void Game::setBackground(string path)
{
    backgroundTexture.loadFromFile(path);
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);
}

// Criar uma única função principal de execução.
// verifico se o Menu está pausado, qual fase eu estou jogando,... dentre outras coisas.

void Game::execMenu()
{
    setBackground("Images/backgroundMenu.jpg");

    while ((pGM->getWindow())->isOpen())
    {
        GetInput();
        (pGM->getWindow())->clear();

        if (dt < FRAME_RATE)
        {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else
        {
            dt -= FRAME_RATE;
        }

        pGM->getWindow()->draw(backgroundSprite);

        menu.drawThis(pGM);

        (pGM->getWindow())->display();
    }

    // pGM->deleteInstance(); -> Aqui está ocorrendo um segmentation Fault.
}

void Game::execLevelOne()
{
    setBackground("Images/background.jpg");

    while ((pGM->getWindow())->isOpen())
    {
        GetInput();
        (pGM->getWindow())->clear();

        if (dt < FRAME_RATE)
        {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else
        {
            level->update(0.0166);
            dt -= FRAME_RATE;
        }

        pGM->getWindow()->draw(backgroundSprite);
        level->render();

        (pGM->getWindow())->display();
    }

    // pGM->deleteInstance(); -> Aqui está ocorrendo um segmentation Fault. -> preciso pensar melhor nesta função.
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
    case sf::Keyboard::Num1:
    {
        if(menu.getMenuState()){
            chooseLevel(1);
            execLevelOne();
        }
    }
    break;
    case sf::Keyboard::Num2:
    {
        if(menu.getMenuState()){
            chooseLevel(2);
            execLevelTwo();
        }
    }
    break;
    }
}
