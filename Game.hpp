#pragma once
#include "Lists/EntityList.hpp"
#include "Managers/Graphic_Manager.hpp"
#include "Managers/Collision_Manager.hpp"
#include "Entities/Characters/Player.hpp"
#include "Entities/Obstacles/Box.hpp"
#include "Entities/Characters/Samurai.hpp"


class Character;

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
    private:
        EntityList MovingEntityList;
        EntityList StaticEntityList;
        Player* pBloco;
        Box* pBloco2;
        Samurai* pBloco3;


        Graphic_Manager* pGM;
        Collision_Manager CM;
        
    public:
/*CONSTRUCTORS & DESTRUCTORS*/
        Game();
        ~Game();

/*SETTERS & GETTERS*/

/*METHODS*/
        void exec();
        void update();
};