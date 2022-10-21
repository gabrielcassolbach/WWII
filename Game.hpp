#pragma once
#include "Graphic_Manager.hpp"

class Character;

class Game
{
    private:
        // Characters List.
        Character* pBloco;
        Graphic_Manager* pGM;
        
    public:
        Game();
        ~Game();
        void executar();
};