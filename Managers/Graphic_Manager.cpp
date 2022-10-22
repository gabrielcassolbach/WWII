#include "Graphic_Manager.hpp"
#include "../Object.hpp"

/*CONSTRUCTOS & DESTRUCTORS*/
Graphic_Manager::Graphic_Manager(){
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
}
Graphic_Manager::~Graphic_Manager(){
        if (instance)
            delete instance;
        if (window)
            delete window;
}

/*SETTERS & GETTERS*/
sf::RenderWindow* Graphic_Manager::getWindow(){
        return window;
}

/*METHODS*/
void Graphic_Manager::draw(Object *pObject){
/*Função que desenha algo na tela*/
    window->draw(pObject->getRectangleShape());
}

Graphic_Manager* Graphic_Manager::instance = nullptr;


