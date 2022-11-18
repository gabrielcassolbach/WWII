#pragma once 
#include "Levels.hpp"

class FirstLevel : public Levels
{
    private:
        Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
        int* entitiesQuantity;
        int difficulty;
         
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel(Game* pg, int diff);
        FirstLevel(Game* pg, int* qtd, int diff);
        ~FirstLevel();

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
