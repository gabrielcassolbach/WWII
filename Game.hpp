#pragma once
#include "Managers/Graphic_Manager.hpp"

class Character;

class Game
{
    private:
        // Characters List.
        Character* pBloco;
        Graphic_Manager* pGM;
        sf::RenderWindow *window;
        
    public:
        Game();
        ~Game();
        void executar();
};