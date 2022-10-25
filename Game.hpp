#pragma once
#include "Lists/EntityList.hpp"
#include "Managers/Graphic_Manager.hpp"
#include "Entities/Characters/Player.hpp"

class Character;

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
    private:
        EntityList MovingEntityList;
        EntityList StaticEntityList;
        Player* pBloco;
        Player* pBloco2;
        Player* pBloco3;
        Graphic_Manager* pGM;
        
    public:
/*CONSTRUCTORS & DESTRUCTORS*/
        Game();
        ~Game();

/*SETTERS & GETTERS*/

/*METHODS*/
        void exec();
};