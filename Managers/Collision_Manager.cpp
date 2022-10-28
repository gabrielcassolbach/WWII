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
    double centerDistance_x = ent1->getPosition_x() - ent2->getPosition_x();
    if (centerDistance_x<0)
        centerDistance_x=-centerDistance_x;
    double centerDistance_y = ent1->getPosition_y() - ent2->getPosition_y();
    if (centerDistance_y<0)
        centerDistance_y=-centerDistance_y;

    double intersection_x = (ent1->getSize_x()+ent2->getSize_x())/2 - centerDistance_x;
    double intersection_y = (ent1->getSize_y()+ent2->getSize_y())/2 - centerDistance_y;

    if (intersection_x>0 && intersection_y>0)
        return true;
    

    cout<<"Retornando false"<<endl;
    return false;
}
void Collision_Manager::collision(){
    int i, j;
    Entity* ent1=NULL;
    Entity* ent2=NULL;
    //Verificar colisão entre entidades estáticas e móveis
    for (i=0; i<pStaticEntitiesList->getSize(); i++){
        for(j=0; j<pMovingEntitiesList->getSize(); j++){
            ent1=pStaticEntitiesList->operator[](i);
            ent2=pMovingEntitiesList->operator[](j);
            if (checkCollision(ent1, ent2)){
                cout<<"Colisao!"<<endl;
            }
        } 
    }

    //Verifica colisao entre objetos que se movem
    for (i=0; i<pMovingEntitiesList->getSize(); i++){
        for (j=i+1; j<pMovingEntitiesList->getSize(); j++){
            ent1=pMovingEntitiesList->operator[](i);
            ent2=pMovingEntitiesList->operator[](j);
            if (checkCollision(ent1, ent2)){
                cout<<"Colisao!"<<endl;
            }
        }
    }

}

