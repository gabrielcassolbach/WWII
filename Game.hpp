#pragma once
#include "Managers/Graphic_Manager.hpp"
#include "Entities/Characters/Player.hpp"
#include "Lists/CharacterList.hpp"

class Character;

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
    private:
        CharacterList PlayersList;
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