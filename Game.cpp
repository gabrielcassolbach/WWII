#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
// CLOCK -> gerencia a atualização da tela: fps.
    // a cada 1/60 segundos chamar a função atualizar posição();

// Percorrer uma lista de entidades.

Game::Game()  
{   
    // Percorrer uma lista de entidades.
    pBloco =  new Character();
    pGM = Graphic_Manager::getGraphic_Manager();
}

Game::~Game() 
{
    // deletar a lista de Entidades.
    if(pBloco) delete pBloco;
}

void Game::executar() 
{

    while((pGM ->getWindow()) -> isOpen()){
        

        pBloco -> atualizar_se();
        sf::Event event;
        while ((pGM ->getWindow())-> pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                (pGM ->getWindow())->close();
        }
        (pGM ->getWindow()) -> clear();
        pBloco -> imprimir_se(pGM);
        // Percorro a lista de entidades.
            /* classe Entity -> atualizar posição(): chama gerenciador de eventos e colisões.
                             -> imprimir-se(): chama o gerenciador gráfico para desenhar.
            */
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}