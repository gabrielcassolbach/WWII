#pragma once
#include "../Game_State.hpp"
#include "../Enty.hpp"

namespace Menus
{
    class MenuCore : public Enty, public Game_State
    {
    protected:
        Game *pGame;
        sf::Font font;
        sf::RectangleShape backgroundRectangle;
        sf::Texture backgroundTexture;

    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        MenuCore(Game *pg);
        ~MenuCore();
        void init() {}

        /*SETTERS & GETTERS*/
        virtual void setText() = 0;
        virtual void setBackground() = 0;
        sf::RectangleShape getRectangleShape() const {}

        /*METHODS*/
        virtual void drawThis(Managers::Graphic_Manager *pGM){};
        void update(double timeFraction){};
    };

}
