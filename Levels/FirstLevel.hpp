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
        void init () {}

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const { } // pensar sobre essa função
        
    /*METHODS*/
        void drawThis(Graphic_Manager* pGM) {}
};
