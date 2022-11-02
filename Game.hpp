#pragma once
#include "Levels/FirstLevel.hpp"

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
private:
    FirstLevel levelOne;
    Graphic_Manager* pGM;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/

/*METHODS*/
    //void execMenu ();
    //void execPause ();
    void execLevelOne();
    void execLevelTwo();
};