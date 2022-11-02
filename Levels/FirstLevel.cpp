#include "FirstLevel.hpp"


/*  - Cria dinamicamente os objetos pré-determinados no arquivo.h
    - Inicializa todos os objetos.
    - Faz o ponteiro apontar para a janela que será utilizada.
    - Chama a função de execução. */
FirstLevel::FirstLevel():
CM()
{

    pBloco = new Player(0, 20.0, 200.0, 100.00, 100.0, 0.2, 0.0); 
    pBloco2= new Box (2, 800.00-120.00, 200.00, 100.0, 100.0); //Posicao final - tamanho (para o retângulo aparecer por inteiro)
    pBloco3= new Samurai (1, 400.0, 200.0, 100.0, 100.0, 0.0, 0.0);
    cout<<"Jogadores criados"<<endl;


    pFloor = new Platform(5, 0.0, 670.0, 1280.0, 50.0);
    pCeiling = new Platform(5, 0.0, 0.0, 1280.0, 10.0);
    pRightLimit = new Platform(5, 1270.0, 10.0, 10.0, 660.00);
    pLeftLimit = new Platform(5, 0.0, 10.00, 10.00, 660.00);

    /*
    pPlat1 = new Platform(5, );
    pPlat2 = new Platform(5, );
    pPlat3 = new Platform(5, );
    */

    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco3));

    StaticEntityList.includeEntity(static_cast<Entity*>(pBloco2));

    StaticEntityList.includeEntity(static_cast<Entity*>(pFloor));
    StaticEntityList.includeEntity(static_cast<Entity*>(pCeiling));
    StaticEntityList.includeEntity(static_cast<Entity*>(pRightLimit));
    StaticEntityList.includeEntity(static_cast<Entity*>(pLeftLimit));


    StaticEntityList.initAll();
    MovingEntityList.initAll();
    CM.init(&MovingEntityList, &StaticEntityList);
    pGM = Graphic_Manager::getGraphic_Manager();
}

/* - Desaloca todos os objetos alocados dinamicamente
   - Faz o ponteiro da janela apontar para NULL
*/
FirstLevel::~FirstLevel()
{
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