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
void Collision_Manager::collision(){
    std::list<Entity*>::iterator it;
    int i, j;
    double intersection_x, intersection_y, centerDistance_x, centerDistance_y;
    Entity* ent1=NULL;
    Entity* ent2=NULL;
    
    //Verificar colisão entre entidades estáticas e móveis
    for (it=staticEntitiesList.begin(); it!=staticEntitiesList.end(); it++){
        for(i=0; i<movingEntitiesList.size(); i++){
            ent1=(*it);
            ent2=movingEntitiesList[i];
            centerDistance_x = ent1->getPosition_x() - ent2->getPosition_x();
            if (centerDistance_x<0)
                centerDistance_x=-centerDistance_x;
            centerDistance_y = ent1->getPosition_y() - ent2->getPosition_y();
            if (centerDistance_y<0)
                centerDistance_y=-centerDistance_y;

            intersection_x = (ent1->getSize_x()+ent2->getSize_x())/2 - centerDistance_x;
            intersection_y = (ent1->getSize_y()+ent2->getSize_y())/2 - centerDistance_y;
            
            if (intersection_x>0 && intersection_y>0)
                ent2-> collide (ent1, intersection_x, intersection_y);
        } 
    }

    //Verifica colisao entre objetos que se movem
    for (i=0; i<movingEntitiesList.size(); i++){
        for(j=i+1; j<movingEntitiesList.size(); j++){
            ent1=movingEntitiesList[j];
            ent2=movingEntitiesList[i];
            centerDistance_x = ent1->getPosition_x() - ent2->getPosition_x();
            if (centerDistance_x<0)
                centerDistance_x=-centerDistance_x;
            centerDistance_y = ent1->getPosition_y() - ent2->getPosition_y();
            if (centerDistance_y<0)
                centerDistance_y=-centerDistance_y;

            intersection_x = (ent1->getSize_x()+ent2->getSize_x())/2 - centerDistance_x;
            intersection_y = (ent1->getSize_y()+ent2->getSize_y())/2 - centerDistance_y;
            
            if (intersection_x>0 && intersection_y>0){
                ent1-> collide (ent2, intersection_x, intersection_y);
                ent2-> collide (ent1, intersection_x, intersection_y);
            }
        } 
    }

}


