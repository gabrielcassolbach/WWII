#pragma once
#include "../Game_State.hpp"
#include "../Enty.hpp"

class MenuCore: public Enty, public Game_State{
    protected:
        Game* pGame;

    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        MenuCore(Game* pg);
        ~MenuCore();
        void init (){}

    /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const{}

    /*METHODS*/
        virtual void drawThis(Graphic_Manager* pGM){};
};