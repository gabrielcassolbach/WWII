#pragma once 
#include "Levels.hpp"

class FirstLevel : public Levels
{
    private:
        Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum.
        int* entitiesQuantity;
         
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel(Game* pg);
        FirstLevel(Game* pg, int* qtd);
        ~FirstLevel();

    /*SETTERS & GETTERS*/
        int* getEntitiesQuantity();

    /*METHODS*/
        void update (double timeFraction);
        void draw ();
        void input();
        void keyPressedAction(sf::Event event);
        void CheckPlayerState();
        void endCurrentState();
        /*------------------------------------------------*/
        void init () {} // pensar!!
        void drawThis(Graphic_Manager* pGM) {} // pensar!!
        /*------------------------------------------------*/
        void createPlayers();
        void createEnemies();
        void createPlatforms();
        void createTrenchs();
        void createCannons();
        void createBoxes();
        void createSnipers();

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const { } // pensar sobre essa função
        
};
