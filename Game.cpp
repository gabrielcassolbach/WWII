#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()  {   
    pBloco =  new Player();
    pBloco->init();
    pGM = Graphic_Manager::getGraphic_Manager();
}
Game::~Game() 
{
    if(pBloco) delete pBloco;
    pGM=NULL;
}

/*METHODS*/
void Game::executar() {
//A comentar posteriormente
    while((pGM ->getWindow()) -> isOpen()){
        

        pBloco -> update();
        sf::Event event;
        while ((pGM ->getWindow())-> pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                (pGM ->getWindow())->close();
        }
        (pGM ->getWindow()) -> clear();
        pBloco -> drawThis(pGM);
        // Percorro a lista de entidades.
            /* classe Entity -> atualizar posição(): chama gerenciador de eventos e colisões.
                             -> imprimir-se(): chama o gerenciador gráfico para desenhar.
            */
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}