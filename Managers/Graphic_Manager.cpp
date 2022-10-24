#include "Graphic_Manager.hpp"
#include "../Object.hpp"

/*CONSTRUCTOS & DESTRUCTORS*/
Graphic_Manager::Graphic_Manager(){
/*Construtora da classe Graphic_Manager
- Criação de uma janela (800, 600) com nome "Jogo"
*/
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
}
Graphic_Manager::~Graphic_Manager(){
/* Destrutora da classe Graphic_Manager
- Desaloca os objetos alocados dinamicamente
*/
        if (instance)
            delete instance;
        if (window)
            delete window;
}

/*SETTERS & GETTERS*/
sf::RenderWindow* Graphic_Manager::getWindow(){
/* Função que retorna a janela em questão
*/
        return window;
}

/*METHODS*/
void Graphic_Manager::draw(Object *pObject){
/*Função que desenha algo na tela
*/
    window->draw(pObject->getRectangleShape());
}

Graphic_Manager* Graphic_Manager::instance = nullptr;


