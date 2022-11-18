#pragma once
#include "Levels.hpp"
#include "../GameOverMenu.hpp"

class SecondLevel : public Levels
{
private:
    // Boss boss;
    Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
    int* entitiesQuantity;

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
        void keyPressedAction(sf::Event event);
        void CheckPlayerState();
        void endCurrentState();
        /*------------------------------------------------*/
        void init () {} // pensar!!
        void drawThis(Graphic_Manager* pGM) {} // pensar!!
        /*------------------------------------------------*/
        void createEnemies();
        void createPlatforms();
        void createTrenchs();
        void createCannons();
        void createBoxes();
        void createSnipers();
        void createPlayers();

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const { } // pensar sobre essa função

};