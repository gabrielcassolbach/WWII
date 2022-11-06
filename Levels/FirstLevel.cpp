#include "FirstLevel.hpp"

//Eescala de tamanho 35 vezes maior que o real
//Escala de velocidade real


/*  - Cria dinamicamente os objetos pré-determinados no arquivo.h
    - Inicializa todos os objetos.
    - Faz o ponteiro apontar para a janela que será utilizada.
    - Chama a função de execução. */
FirstLevel::FirstLevel():
CM()
{
    pBloco = new Player(0, 20.0, 40.0, 18.00, 63.0, 0.0, 0.0, 10, 2);
    pBloco2= new Box (2, 800.00-100.00, 40.00, 20.0, 20.0); 
    pBloco3= new Samurai (1, 400.0, 620.0, 18.00, 63.0, 0.0, 0.0, 6, 2, 1, pBloco);
    
    floor= new Platform (3, 0.0, 640.0, 1280.0, 80.0);
    ceiling= new Platform (3, 0.0, 1.0, 1280.0, 5.0);
    leftWall= new Platform(3, 0.0, 5.0, 5.0, 635.0);
    rightWall= new Platform (3, 1275.0, 5.0, 5.0, 635.0);
    plat1= new Platform (3, 426.66, 640, 425.66, 40);

    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco3));

    StaticEntityList.includeEntity(static_cast<Entity*>(pBloco2));
    StaticEntityList.includeEntity(static_cast<Entity*>(floor));
    StaticEntityList.includeEntity(static_cast<Entity*>(ceiling));
    StaticEntityList.includeEntity(static_cast<Entity*>(leftWall));
    StaticEntityList.includeEntity(static_cast<Entity*>(rightWall));
    StaticEntityList.includeEntity(static_cast<Entity*>(plat1));

    StaticEntityList.initAll();
    MovingEntityList.initAll();
    CM.init(&MovingEntityList, &StaticEntityList);
    pGM = Graphic_Manager::getGraphic_Manager();

    gravity=9.8;
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
Player* FirstLevel::getPlayerOne () const{
    return pBloco;
}

/*METHODS*/
void FirstLevel::update (double timeFraction){
    MovingEntityList.updateAll(timeFraction);
    //StaticEntityList.updateAll();
    CM.collision();
}
void FirstLevel::render (){
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}