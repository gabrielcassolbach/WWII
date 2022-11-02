#include "FirstLevel.hpp"

FirstLevel::FirstLevel():
CM()
{
/*Construtora da classe Game
    - Cria dinamicamente os objetos pré-determinados no arquivo.h
    - Inicializa todos os objetos.
    - Faz o ponteiro apontar para a janela que será utilizada.
    - Chama a função de execução.
*/

    // 10 inimigos
    // 2 players.
    // 7 plataformas.
    // 3 inimigos.
    // 2 obstáculos.

    pBloco = new Player(0, 0.0, 0.0, 100.00, 100.0, 0.2, 0.0); //(px, py, vx, vy, sx, sy)
    pBloco2= new Box (2, 800.00-100.00, 0.00, 100.0, 100.0); //Posicao final - tamanho (para o retângulo aparecer por inteiro)
    pBloco3= new Samurai (1, 400.0, 0.0, 100.0, 100.0, 0.0, 0.0);
    
    
    cout<<"Jogadores criados"<<endl;

    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco3));

    StaticEntityList.includeEntity(static_cast<Entity*>(pBloco2));
    
    StaticEntityList.initAll();
    MovingEntityList.initAll();
    CM.init(&MovingEntityList, &StaticEntityList);
    pGM = Graphic_Manager::getGraphic_Manager();
}
FirstLevel::~FirstLevel(){
/*Destrutora da classe Game
- Desaloca todos os objetos alocados dinamicamente
- Faz o ponteiro da janela apontar para NULL
*/
    MovingEntityList.destroyAll();
    StaticEntityList.destroyAll();
    pGM=nullptr;
}

/*SETTERS & GETTERS*/

/*METHODS*/
void FirstLevel::update (){
    MovingEntityList.updateAll();
    StaticEntityList.updateAll();
    CM.collision();
}
void FirstLevel::render (){
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}