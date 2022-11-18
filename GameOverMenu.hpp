#pragma once
#include "Game_State.hpp"
#include "Enty.hpp"
#include "Game.hpp"

#define ITENS_GAMEOVER_MENU 4

class GameOverMenu: public Enty, public Game_State{
    private:
        Game* pGame;
        sf::Text text[ITENS_GAMEOVER_MENU];
        sf::Font font;
        sf::RectangleShape backgroundRectangle;
        sf::Texture backgroundTexture;

    public:
        GameOverMenu(Game* pg);
        ~GameOverMenu();
        void setText();
        void setBackground();
        void init (){}

        void update (double timeFraction){}
        sf::RectangleShape getRectangleShape()const {}
        void drawThis(Graphic_Manager* pGM);
        void draw();
        void input();
        void keyPressedAction (sf::Event event);
};