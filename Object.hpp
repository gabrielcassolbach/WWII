#pragma once
#include "stdafx.hpp"

#include "Managers/Graphic_Manager.hpp"

class Object
{
    protected: 
        Graphic_Manager* pGM;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Object();
        ~Object();
        virtual void init () = 0;

    /*SETTERS & GETTERS*/
        virtual sf::RectangleShape getRectangleShape() = 0;

    /*METHODS*/
        virtual void drawThis(Graphic_Manager* pGM) = 0;
};