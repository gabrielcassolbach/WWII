#pragma once

#include "../stdafx.hpp"

class Enty;

/* Classe que gerencia tudo o que aparece na tela
- Update/Spawn/Render...
*/
class Graphic_Manager
{
private:
    sf::RenderWindow *window; // Cria uma janela.
    static Graphic_Manager *instance; //Cria o gerenciador que será utilizado no jogo inteiro

/*CONSTRUCTOR & DESTRUCTORS*/
private:
    Graphic_Manager();
public:
    ~Graphic_Manager();

public:
/*SETTERS & GETTERS*/
    static Graphic_Manager* getGraphic_Manager(){
        if (!instance)
            instance = new Graphic_Manager();
        return instance;
    }
    sf::RenderWindow *getWindow() const;

/*METHODS*/
    void draw(Enty *pEnty);
    
    static void deleteInstance()
    {
        if (instance)
            delete instance;
    }

};