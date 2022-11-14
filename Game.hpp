#pragma once
#include "Levels/FirstLevel.hpp"

#define FRAME_RATE 0.01

class Game
/*Classe responsável pela mecânica geral do jogo*/
{
private:
    FirstLevel levelOne;
    Graphic_Manager* pGM;
    
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Clock clock;
    double dt;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTERS & GETTERS*/
    void setBackground(string path);

/*METHODS*/
    //void execMenu ();
    //void execPause ();
    void waitForInput();
    void execLevelOne();
    void execLevelTwo();

    void keyPressedAction (sf::Event event);
};