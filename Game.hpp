#pragma once
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"

#define FRAME_RATE 0.01

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
private:
    FirstLevel levelOne;
    SecondLevel levelTwo;
    Graphic_Manager* pGM;
    
    bool runningLevelOne;
    bool runningLevelTwo;
    
    sf::Clock clock;
    double dt;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/

/*METHODS*/
    void execLevelOne();
    void execLevelTwo();

    void keyPressedAction (sf::Event event);
    void mousePressedAction(sf::Event event);
};