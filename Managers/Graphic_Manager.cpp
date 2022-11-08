#include "Graphic_Manager.hpp"
#include "../Enty.hpp"

/*CONSTRUCTOS & DESTRUCTORS*/
/*Construtora da classe Graphic_Manager
- Criação de uma janela (800, 600) com nome "Jogo"
*/
Graphic_Manager::Graphic_Manager()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Jogo");
}


Graphic_Manager::~Graphic_Manager()
{
    if (instance)
        delete instance;
    if (window)
        delete window;
}

/*SETTERS & GETTERS*/
sf::RenderWindow *Graphic_Manager::getWindow() const
{
    return window;
}

/*METHODS*/
void Graphic_Manager::draw(Enty *pEnty)
{
    window->draw(pEnty->getRectangleShape());
}

Graphic_Manager *Graphic_Manager::instance = nullptr;
