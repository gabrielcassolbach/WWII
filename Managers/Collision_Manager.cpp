#include "Collision_Manager.hpp"
#include "../Lists/EntityList.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Collision_Manager::Collision_Manager(EntityList *lMoving, EntityList *lStatic){
    pMovingEntitiesList=lMoving;
    pStaticEntitiesList=lStatic;
}
Collision_Manager::~Collision_Manager(){
    pMovingEntitiesList=nullptr;
    pStaticEntitiesList=nullptr;

}


/*SETTERS & GETTERS*/

/*METHODS*/
bool Collision_Manager::checkCollision(Entity* ent1, Entity* ent2){
    double centerDistance_x = ent1->get_x() - ent2->get_x();
    double centerDistance_y = ent1->get_y() - ent2->get_y();
    
    double intersection_x = (ent1->getSize_x()+ent2->getSize_x())/2 - centerDistance_x;
    double intersection_y = (ent1->getSize_y()+ent2->getSize_y())/2 - centerDistance_y;

    if (intersection_x>0 && intersection_y>0)
        return 1;
    return 0;
}
void Collision_Manager::collision(){
    int i, j;
    Entity* ent1=NULL;
    Entity* ent2=NULL;
    cout<<"Processo de colisao iniciado"<<endl;
    //Verificar colisão entre entidades estáticas e móveis
    cout<<"Size:"<<pStaticEntitiesList->getSize()<<endl;
    for (i=0; i<pStaticEntitiesList->getSize(); i++){
        for(j=0; j<pMovingEntitiesList->getSize(); j++){
            cout<<"Verificacao loop"<<endl;
            ent1=pStaticEntitiesList->operator[](i);
            cout<<"Verificacao operator"<<endl;
            ent2=pMovingEntitiesList->operator[](j);
            if (checkCollision(ent1, ent2))
                cout<<"Colisao!"<<endl;
        } 
    }

    for (i=0; i<pMovingEntitiesList->getSize(); i++){
        for (j=0; j<pMovingEntitiesList->getSize(); j++){
            ent1=pMovingEntitiesList->operator[](i);
            ent2=pMovingEntitiesList->operator[](j);
            if (checkCollision(ent1, ent2))
                cout<<"Colisao!"<<endl;
        }
    }

}

