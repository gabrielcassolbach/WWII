#pragma once
#include "Levels.hpp"
#include "../Menus/GameOverMenu.hpp"

class Boss;

class SecondLevel : public Levels
{
private:
    std::vector<Boss*> pBossList;
    Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
    int* entitiesQuantity;
    
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        SecondLevel(Game* pg);
        SecondLevel(Game* pg, int* qtd);
        ~SecondLevel();

    /*SETTERS & GETTERS*/
        int* getEntitiesQuantity();

    /*METHODS*/
        void update (double timeFraction);
        void input();
        void draw();
        void keyPressedAction(sf::Event event);
        void CheckPlayerState();
        void endCurrentState();
        /*------------------------------------------------*/
        void init () {} // pensar!!
        void drawThis(Graphic_Manager* pGM) {} // pensar!!
        /*------------------------------------------------*/
        void createBoss();
        void createEnemies();
        void createPlatforms();
        void createTrenchs();
        void createCannons();
        void createBoxes();
        void createSnipers();
        void createPlayers();
        void setBackground();

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const { } // pensar sobre essa função
        void CheckLevelEnd();

};