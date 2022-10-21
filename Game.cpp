#include "Game.hpp"
// CLOCK -> gerencia a atualização da tela: fps.
    // a cada 1/60 segundos chamar a função atualizar posição();

// Percorrer uma lista de entidades.

Game::Game() 
{
    // Percorrer uma lista de entidades.
    pGM = Managers::Graphic_Manager::getGraphic_Manager();
}

Game::~Game() 
{
    // deletar a lista de Entidades.
}

void Game::executar() 
{
    while((pGM ->getWindow()) -> isOpen()){
        (pGM ->getWindow()) -> clear();
        // Percorro a lista de entidades.
            /* classe Entity -> atualizar posição(): chama gerenciador de eventos e colisões.
                             -> imprimir-se(): chama o gerenciador gráfico para desenhar.
            */
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}
