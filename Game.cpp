#include "Game.hpp"
#include "Entities/Characters/Character.hpp"
/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game()  {   
    pBloco =  new Player();
    pBloco2= new Player (800.00-100.00, 0.00, 0.00, 0.00); //Posicao final - tamanh (para o retângulo aparecer por inteiro)
    pBloco->init();
    pBloco2->init();

    pGM = Graphic_Manager::getGraphic_Manager();
    exec();
}
Game::~Game() 
{
    if(pBloco) delete pBloco;
    if(pBloco2) delete pBloco2;
    pGM=NULL;

}

/*METHODS*/
void Game::exec() {
//A comentar posteriormente
    while((pGM ->getWindow()) -> isOpen()){
        

        pBloco -> update();
        pBloco2 ->update();
        sf::Event event;
        while ((pGM ->getWindow())-> pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                (pGM ->getWindow())->close();
            else if (event.key.code==sf::Keyboard::Escape)
                (pGM ->getWindow())->close();
        }
        (pGM ->getWindow()) -> clear();
        pBloco -> drawThis(pGM);
        pBloco2 -> drawThis (pGM);
        // Percorro a lista de entidades.
            /* classe Entity -> atualizar posição(): chama gerenciador de eventos e colisões.
                             -> imprimir-se(): chama o gerenciador gráfico para desenhar.
            */
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}