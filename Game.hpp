#pragma once
//#include "../Graphic_Manager.hpp"

class Game
{
    private:
        // Objects List.
        Managers::Graphic_Manager* pGM;
        
    public:
        Game();
        ~Game();
        void executar();
};