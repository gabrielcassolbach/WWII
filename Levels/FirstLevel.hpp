#pragma once 
#include "Levels.hpp"

class FirstLevel : public Levels
{
    private:
        Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum.
         
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel();
        ~FirstLevel();

    /*SETTERS & GETTERS*/
        Player* getPlayerOne () const;

    /*METHODS*/
        void update (double timeFraction);
        void render ();
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
