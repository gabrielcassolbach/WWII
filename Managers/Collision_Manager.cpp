#include "Collision_Manager.hpp"
#include "../Lists/EntityList.hpp"
#include <iostream>
using namespace std;

/*CONSTRUCTORS & DESTRUCTORS*/
Collision_Manager::Collision_Manager(){

}

Collision_Manager::~Collision_Manager(){
    movingEntitiesList.clear();
    staticEntitiesList.clear();
}

void Collision_Manager::init(EntityList* lMoving, EntityList* lStatic){
    int i;
    for (i=0; i<lMoving->getSize(); i++){
        movingEntitiesList.push_back(lMoving->operator[](i));
    }
    for (i=0; i<lStatic->getSize(); i++){
        staticEntitiesList.push_back(lStatic->operator[](i));
    }
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
    std::list<Entity*>::iterator it;
    int i, j;
    Entity* ent1=NULL;
    Entity* ent2=NULL;
    
    //Verificar colisão entre entidades estáticas e móveis
    for (it=staticEntitiesList.begin(); it!=staticEntitiesList.end(); it++){
        for(i=0; i<movingEntitiesList.size(); i++){
            ent1=(*it);
            ent2=movingEntitiesList[i];
            if (checkCollision(ent1, ent2)){
                cout<<"Colisao!"<<endl;
                //getchar();
            }
        } 
    }

    //Verifica colisao entre objetos que se movem
    for (i=0; i<movingEntitiesList.size(); i++){
        for(j=i+1; j<movingEntitiesList.size(); j++){
            ent1=movingEntitiesList[j];
            ent2=movingEntitiesList[i];
            if (checkCollision(ent1, ent2)){
                cout<<"Colisao!"<<endl;
                getchar();
            }
        } 
    }

}

