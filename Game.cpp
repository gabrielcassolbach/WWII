#include "Game.hpp"
#include "Entities/Characters/Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game() {  
/*Construtora da classe Game
- Cria dinamicamente os objetos pré-determinados no arquivo.h
- Inicializa todos os objetos.
- Faz o ponteiro apontar para a janela que será utilizada.
- Chama a função de execução.
*/
    pBloco = new Player(0.0, 0.0, 0.2, 0.0, 100.0, 100.0); //(px, py, vx, vy, sx, sy)
    pBloco2= new Player (800.00-100.00, 0.00, 0.00, 0.00, 100.0, 100.0); //Posicao final - tamanho (para o retângulo aparecer por inteiro)
    pBloco3= new Player (350.00, 0.0, 0.0, 0.0, 100.0, 100.0);
    cout<<"Jogadores criados"<<endl;

    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco2));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco3));
    cout<<"Characters incluidos"<<endl;

    MovingEntityList.initAll();
    pGM = Graphic_Manager::getGraphic_Manager();
    exec();
}
Game::~Game() 
{
/*Destrutora da classe Game
- Desaloca todos os objetos alocados dinamicamente
- Faz o ponteiro da janela apontar para NULL
*/
    MovingEntityList.destroyAll();
    pGM=NULL;
}

/*METHODS*/
void Game::exec() {
//A comentar posteriormente
    while((pGM ->getWindow()) -> isOpen()){
        
        MovingEntityList.updateAll();
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
        MovingEntityList.drawAll();
        // Percorro a lista de entidades.
            /* classe Entity -> atualizar posição(): chama gerenciador de eventos e colisões.
                             -> imprimir-se(): chama o gerenciador gráfico para desenhar.
            */
        
        (pGM ->getWindow()) -> display(); // mostra na tela.
    }
}