#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{  
    clock.restart();
    dt=0.0;

    pGM = Graphic_Manager::getGraphic_Manager();
    execLevelOne();
}
Game::~Game() {
    pGM=nullptr;
}

/*METHODS*/
void Game::execLevelOne() {

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background1.png");
    sf::Sprite backgroundSprite;
    sf::Vector2u size=backgroundTexture.getSize();
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);

    while((pGM ->getWindow()) -> isOpen()){ 
        sf::Event event;
        while ((pGM ->getWindow())-> pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:{
                    (pGM ->getWindow())->close();  
                } break;
                case sf::Event::KeyPressed:{
                    keyPressedAction(event);
                }

                default:{
                }break;
            }  
        }
        
        (pGM ->getWindow()) -> clear();

        if (dt<TICK_RATE){
            dt+=clock.getElapsedTime().asSeconds();
            clock.restart();
        }
        else{
            levelOne.update(TICK_RATE);
            dt-=TICK_RATE;
        }

        pGM->getWindow()->draw(backgroundSprite);
        levelOne.render();
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}
void Game::keyPressedAction (sf::Event event){
    switch(event.key.code){
        case sf::Keyboard::Right:{
            levelOne.getPlayerOne()->setVelocity(1.0, 0.0);
        }break;
        case sf::Keyboard::Left:{
            levelOne.getPlayerOne()->setVelocity(-1.0, 0.0);
        }break;
        case sf::Keyboard::Down:{
            levelOne.getPlayerOne()->setVelocity(0.0, 1.0);
        }break;
        case sf::Keyboard::Up:{
            levelOne.getPlayerOne()->setVelocity(0.0, -1.0);
        }break;
    }
}