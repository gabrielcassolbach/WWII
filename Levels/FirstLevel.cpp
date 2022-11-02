#include "FirstLevel.hpp"


/*  - Cria dinamicamente os objetos pré-determinados no arquivo.h
    - Inicializa todos os objetos.
    - Faz o ponteiro apontar para a janela que será utilizada.
    - Chama a função de execução. */
FirstLevel::FirstLevel():
CM()
{

    pBloco = new Player(0, 20.0, 40.0, 100.00, 100.0, 0.0, 0.2, 10);
    pBloco2= new Box (2, 800.00-100.00, 40.00, 100.0, 100.0); 
    pBloco3= new Samurai (1, 400.0, 40.0, 100.0, 100.0, 0.0, 0.0, 6);
    
    floor= new Platform (3, 0.0, 640.0, 1280.0, 80.0);
    //ceiling= new Platform (3, 0.0, 1.0, 1280.0, 5.0);

    cout<<"Jogadores criados"<<endl;

    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco));
    MovingEntityList.includeEntity(static_cast<Entity*>(pBloco3));

    StaticEntityList.includeEntity(static_cast<Entity*>(pBloco2));
    StaticEntityList.includeEntity(static_cast<Entity*>(floor));
    //StaticEntityList.includeEntity(static_cast<Entity*>(ceiling));

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