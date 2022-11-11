#include "Levels.hpp"

class SecondLevel : public Levels
{
    private:
        Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum.
         
    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        SecondLevel();
        ~SecondLevel();

    /*SETTERS & GETTERS*/
        Player* getPlayerOne () const;
        Collision_Manager* getCollisionManager();

    /*METHODS*/
        void update (double timeFraction);
        void render ();
        void init () {}

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const { } // pensar sobre essa função
        
    /*METHODS*/
        void drawThis(Graphic_Manager* pGM) {}
};