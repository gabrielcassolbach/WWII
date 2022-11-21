#pragma once 
#include "Levels.hpp"

class FirstLevel : public Levels
{
    private:
        Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
        int* entitiesQuantity;
        int difficulty;

        int nPlayers;

        sf::Sprite backgroundSprite;
        sf::Texture backgroundTexture;
         
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel(Game* pg, int diff, int np);
        FirstLevel(Game* pg, int* qtd, int diff, int np);
        ~FirstLevel();

    /*SETTERS & GETTERS*/
        int* getEntitiesQuantity();
        int getDifficulty();
        void setBackground();

    /*METHODS*/
        void update (double timeFraction);
        void input();
        void draw(); // Implementar
        void keyPressedAction(sf::Event event);
        void CheckPlayerState();
        void endCurrentState();
        void CheckLevelEnd();
        void goToLevel2();
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
