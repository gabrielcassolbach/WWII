#pragma once 
#include "Levels.hpp"

class FirstLevel : public Levels
{
    private:
        EntityList MovingEntityList;
        EntityList StaticEntityList;
        Player* pBloco;
        Box* pBloco2;
        Samurai* pBloco3;
        Graphic_Manager* pGM;
        Collision_Manager CM;

        Platform* floor;
        Platform* ceiling;
        Platform* leftWall;
        Platform* rightWall;

        double gravity;
         
    public:
/*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel();
        ~FirstLevel();

/*SETTERS & GETTERS*/
        Player* getPlayerOne () const;

/*METHODS*/
        void update (double timeFraction);
        void render ();
};
