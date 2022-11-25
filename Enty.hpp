#pragma once
#include "stdafx.hpp"

#include "Managers/Graphic_Manager.hpp"

class Enty 
{
    protected: 
        Managers::Graphic_Manager* pGM;

    public:
    /*CONSTRUCTORS & DESTRUCTORS*/
        Enty();
        ~Enty();
        virtual void init () = 0;

    /*SETTERS & GETTERS*/
        virtual sf::RectangleShape getRectangleShape() const = 0;
        Managers::Graphic_Manager* getGraphicManager() const;

    /*METHODS*/
        virtual void drawThis(Managers::Graphic_Manager* pGM) = 0;
};