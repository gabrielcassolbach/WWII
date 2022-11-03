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
    double intersection_x, intersection_y, centerDistance_x, centerDistance_y, distance_x, distance_y;
    Entity* ent1=NULL;
    Entity* ent2=NULL;
    
    //Verificar colisão entre entidades estáticas e móveis
    for (it=staticEntitiesList.begin(); it!=staticEntitiesList.end(); it++){
        for(i=0; i<movingEntitiesList.size(); i++){
            ent1=(*it);
            ent2=movingEntitiesList[i];
            
            if (ent1->getPosition_y() > ent2->getPosition_y()){
                centerDistance_y = (ent2->getSize_y() + ent1->getSize_y())/2;
                distance_y=abs(ent2->getPosition_y()-ent1->getPosition_y());
                intersection_y = centerDistance_y - distance_y;
            }
            else{
                centerDistance_y=ent1->getSize_y();
                distance_y=abs(ent1->getPosition_y()-ent2->getPosition_y());
                intersection_y=centerDistance_y-distance_y;
            }

            if (ent1->getPosition_x() > ent2->getPosition_x()){
                centerDistance_x = (ent2->getSize_x() + ent1->getSize_x())/2;
                distance_x=abs(ent2->getPosition_x()-ent1->getPosition_x());
                intersection_x = centerDistance_x - distance_x;
            }
            else{
                centerDistance_x=ent1->getSize_x();
                distance_x=abs(ent1->getPosition_x()-ent2->getPosition_x());
                intersection_x=centerDistance_x-distance_x;
            }

            if (intersection_x>0.0 && intersection_y>0.0){
                ent2-> collide (ent1, intersection_x, intersection_y);
            }       
        }
    }

    //Verifica colisao entre objetos que se movem
    for (i=0; i<movingEntitiesList.size(); i++){
        for(j=i+1; j<movingEntitiesList.size(); j++){
            ent1=movingEntitiesList[j];
            ent2=movingEntitiesList[i];
            
            if (ent1->getPosition_y() > ent2->getPosition_y()){
                centerDistance_y = (ent2->getSize_y() + ent1->getSize_y())/2;
                distance_y=abs(ent2->getPosition_y()-ent1->getPosition_y());
                intersection_y = centerDistance_y - distance_y;
            }
            else{
                centerDistance_y=ent1->getSize_y();
                distance_y=abs(ent1->getPosition_y()-ent2->getPosition_y());
                intersection_y=centerDistance_y-distance_y;
            }

            if (ent1->getPosition_x() > ent2->getPosition_x()){
                centerDistance_x = (ent2->getSize_x() + ent1->getSize_x())/2;
                distance_x=abs(ent2->getPosition_x()-ent1->getPosition_x());
                intersection_x = centerDistance_x - distance_x;
            }
            else{
                centerDistance_x=ent1->getSize_x();
                distance_x=abs(ent1->getPosition_x()-ent2->getPosition_x());
                intersection_x=centerDistance_x-distance_x;
            }

            if (intersection_x>0.0 && intersection_y>0.0){
                ent2->collide (ent1, intersection_x, intersection_y);
                ent1->collide (ent2, intersection_x, intersection_y);
            } 
        }
    } 
}
