#pragma once

#include "../stdafx.hpp"

class Object;

// O que o Gerenciador Gráfico faz? gerencia tudo que aparece na tela.

/*
-> Mesma ideia para todos os gerenciadores.

    O gerenciador gráfico vai ter acesso ao jogo. Ele vai imprimir os objetos.
    O objeto vai ter um ponteiro para o gerenciador gráfico (imprimir-se()) -> padrão singleton.

    relação objeto gerenciador: 1 para n;
*/

class Graphic_Manager
{
private:
    sf::RenderWindow *window; // Cria uma janela.

    // Utilizar o padrão de projeto singleton -> forçando a existencia de um único gerenciador gráfico no jogo.
    static Graphic_Manager *instance;

private:
    Graphic_Manager()
    {
        window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
    }

public:
    ~Graphic_Manager()
    {
        if (instance)
            delete instance;
        if (window)
            delete window;
    }

public:
    static Graphic_Manager* getGraphic_Manager()
    {
        if (!instance)
            instance = new Graphic_Manager();
        return instance;
    }

    void draw(Object *pObject);

    sf::RenderWindow *getWindow()
    {
        return window;
    }
};