#pragma once
#include "Graphic_Manager.cpp"


class Game
{
    private:
        // Objects List.
        Graphic_Manager* pGM;
        
    public:
        Game();
        ~Game();
        void executar();
};