#pragma once
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"
#include "Menu.hpp"

#define FRAME_RATE 0.01

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
private:
    Menu menu;
    FirstLevel levelOne;
    SecondLevel levelTwo;
    Graphic_Manager* pGM;
    
    bool runningMenu;
    bool runningLevelOne;
    bool runningLevelTwo;
    
    sf::Clock clock;
    double dt;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/
    void setRunningLevelOne (bool l1);
    void setRunningLevelTwo (bool l2);
    void setRunningMenu (bool m);
    bool getRunningLevelOne ();
    bool getRunningLevelTwo ();
    bool getRunningMenu();

/*METHODS*/
    void execLevelOne();
    void execLevelTwo();
    void execMenu();

    void keyPressedActionLevel (sf::Event event);
    void mousePressedActionLevel (sf::Event event);
    void keyPressedActionMenu(sf::Event event);
};