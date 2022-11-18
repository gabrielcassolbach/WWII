#pragma once
#include "Levels.hpp"

class SecondLevel : public Levels
{
private:
    // Boss boss;
    Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
    int* entitiesQuantity;
    int difficulty;

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        SecondLevel(Game* pg, int diff);
        SecondLevel(Game* pg, int* qtd, int diff);
        ~SecondLevel();

    /*SETTERS & GETTERS*/
        int* getEntitiesQuantity();
        int getDifficulty();

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