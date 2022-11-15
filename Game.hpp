#pragma once
#include "Menu.hpp"
#include "Levels/Levels.hpp"
#define FRAME_RATE 0.01

/*Classe responsável pela mecânica geral do jogo*/

class Game
{
private:
    Levels* level;    
    Menu menu;
    
    std::stack <Game_States*> states;


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
    void chooseLevel(int level_path);
    void execute();
    void execMenu ();
    void GetInput();
    void execLevelOne();
    void execLevelTwo();

    void keyPressedAction (sf::Event event);
};