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

        Platform* pFloor;
        Platform* pCeiling;
        Platform* pRightLimit;
        Platform* pLeftLimit;


        Platform* pPlat1;
        Platform* pPlat2;
        Platform* pPlat3;

        Graphic_Manager* pGM;
        Collision_Manager CM;
         
    public:
/*CONSTRUCTORS & DESTRUCTORS*/
        FirstLevel();
        ~FirstLevel();

/*SETTERS & GETTERS*/

/*METHODS*/
        void update ();
        void render ();
};
