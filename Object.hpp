#pragma once
#include "stdafx.hpp"

#include "Managers/Graphic_Manager.hpp"

class Object
{
    protected: 
        Graphic_Manager* pGM;
        sf::RectangleShape retangulo;

    public:
        Object();
        ~Object();
        sf::RectangleShape getRectangleShape();
        virtual void imprimir_se(Graphic_Manager* pGM) = 0;
};