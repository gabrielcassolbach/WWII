#include "FirstLevel.hpp"
#include "../Game.hpp"
#include "../Menu.hpp"

FirstLevel::FirstLevel(Game* pg) : CM(),
Levels(pg)
{
    createPlayers();
    createEnemies();
    createPlatforms();
    createTrenchs();
    createCannons();
    createBoxes();
    createSnipers();

    StaticEntityList.initAll();
    MovingEntityList.initAll();
    
    CM.init(&MovingEntityList, &StaticEntityList);
}

FirstLevel::~FirstLevel()
{
    MovingEntityList.destroyAll();
    StaticEntityList.destroyAll();
}

/*SETTERS & GETTERS*/

/*METHODS*/

void FirstLevel::input()
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

void FirstLevel::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Right:
    {
        if (getPlayer(1)->getLeftDirection())
            getPlayer(1)->setLeftDirection(false);
    }
    break;
    case sf::Keyboard::Left:
    {
        getPlayer(1)->setLeftDirection(true);
    }
    break;
    case sf::Keyboard::Up:
    {
        getPlayer(1)->jump(0.01666);
    }
    break;
    case sf::Keyboard::Space:
    {
        getPlayer(1)->attack();
    }
    break;
    }
}

void FirstLevel::update(double timeFraction)
{
    MovingEntityList.updateAll(timeFraction);
    StaticEntityList.updateAll(timeFraction);
    CM.collision();
    //CheckPlayerState();
}

void FirstLevel::CheckPlayerState()
{
    if(getPlayer(1) -> getPlayerState()) // adicionar verificação para o player 2.
        endCurrentState();     
}

void FirstLevel::endCurrentState()
{   
    if(pGame)
        pGame -> popState();
}

void FirstLevel::draw()
{
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}

void FirstLevel::createEnemies()
{
    MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, 400.0, 600.0, 30.0, 40.0, 0.0, 0.0, 6, 2, 1, pPlayersList[0]))); // Samurai 1.
    MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, 800.0, 600.0, 30.0, 40.0, 0.0, 0.0, 6, 2, 1, pPlayersList[0]))); // Samurai 2.
    MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, 900.0, 600.0, 30.0, 40.0, 0.0, 0.0, 6, 2, 1, pPlayersList[0]))); // Samurai 3.
}


void FirstLevel::createPlatforms()
{
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 640.0, 1280.0, 80.0)));  // Floor
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 0.0, 1280.0, 5.0)));     // Ceil
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 5.0, 5.0, 635.0)));      // LeftWall
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 1275.0, 5.0, 5.0, 635.0)));   // RightWall

    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 200.0, 540.0, 200.0, 20.0))); // Plataforma 1
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 400.0, 440.0, 200.0, 20.0))); // Plataforma 2
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 600.0, 340.0, 200.0, 20.0))); // Plataforma 3
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 800.0, 240.0, 200.0, 20.0))); // Plataforma 4
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 1100.0, 140.0, 200.0, 20.0))); // Plataforma 4
}


void FirstLevel::createTrenchs()
{
    StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, 900.00, 580.00, 50.0, 10.0))); // Trincheira 1
    StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, 1000.00, 580.00, 50.0, 10.0)));  // Trincheira 2
    StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, 800.00, 100.00, 50.0, 10.0)));  // Trincheira 3    
}


void FirstLevel::createCannons()
{
    StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, 450.00, 530.00, 30.0, 30.0))); // Canhão 1
    StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, 600.00, 430.00, 30.0, 30.0)));  // Canhão 2
    StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, 950.00, 230.00, 30.0, 30.0)));  // Canhão 3   
}


void FirstLevel::createBoxes()
{
    StaticEntityList.includeEntity(static_cast<Entity *>(new Box(2, 100.00, 590.00, 50.0, 50.0)));  // Caixa 1
    StaticEntityList.includeEntity(static_cast<Entity *>(new Box(2, 700.00, 590.00, 50.0, 50.0))); // Caixa 2
    StaticEntityList.includeEntity(static_cast<Entity *>(new Box(2, 700.00, 200.00, 50.0, 50.0)));  // Caixa 3
}


void FirstLevel::createSnipers()
{
    pSniperList.push_back(new Sniper(5, 300.0, 500.0, 40.00, 40.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));
    pSniperList.push_back(new Sniper(5, 460.0, 400.0, 40.00, 40.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));
    pSniperList.push_back(new Sniper(5, 600.0, 300.0, 40.00, 40.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));
    pSniperList.push_back(new Sniper(5, 860.0, 200.0, 40.00, 40.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));

    for(int i = 0; i < pSniperList.size(); i++)
    {
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i])); 
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i]->getBullet())); 
    }
}

void FirstLevel::createPlayers()
{
    pPlayersList.push_back(new Player(0, 20.0, 40.0, 30.00, 40.0, 0.0, 0.0, 10, 2));

    for(int i = 0; i < pPlayersList.size(); i++)
    {
        MovingEntityList.includeEntity(static_cast<Entity *>(pPlayersList[i])); 
        MovingEntityList.includeEntity(static_cast<Entity *>(pPlayersList[i]-> getBullet())); 
    }
}
