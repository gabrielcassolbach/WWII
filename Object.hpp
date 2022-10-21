#pragma once
#include "Graphic_Manager.hpp"
//#include "stdafx.hpp"
//class Managers::Graphic_Manager;

class Object
{
    protected: 
        Managers::Graphic_Manager* pGM;
        sf::RectangleShape retangulo;

    public:
        Object();
        ~Object();
        sf::RectangleShape getRectangleShape();
        virtual void imprimir_se(Managers::Graphic_Manager* pGM) = 0;
};