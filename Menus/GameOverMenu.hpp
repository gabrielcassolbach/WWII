#pragma once
#include "../Game_State.hpp"
#include "../Enty.hpp"
#include "../Game.hpp"
#include <iostream>
#include <string.h>
using namespace std;
#define ITENS_GAMEOVER_MENU 7

namespace Menus
{
    class GameOverMenu : public Enty, public Game_State
    {
    private:
        Game *pGame;
        sf::Text text[ITENS_GAMEOVER_MENU];
        sf::Font font;
        sf::RectangleShape backgroundRectangle;
        sf::Texture backgroundTexture;

        double totalPoints1;
        char name[10];
        int nameSize;

    public:
        GameOverMenu(Game *pg, double points);
        ~GameOverMenu();
        void setText();
        void setBackground();
        void init() {}

        void update(double timeFraction) {}
        sf::RectangleShape getRectangleShape() const {}
        void drawThis(Graphic_Manager *pGM);
        void draw();
        void input();
        void keyPressedAction(sf::Event event);
        void writeLetter(sf::Event event);
        void saveLeaderboard();
        void goToLevelTwo();
    };
}

using namespace Menus;