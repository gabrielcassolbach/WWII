#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()
{  
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
        levelOne.update();
        sf::Event event;
        while ((pGM ->getWindow())-> pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                (pGM ->getWindow())->close();
            else if (event.key.code==sf::Keyboard::Escape)
                (pGM ->getWindow())->close();
        }
        
        (pGM ->getWindow()) -> clear();

        pGM->getWindow()->draw(backgroundSprite);
        levelOne.render();
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}