#include "EntityList.hpp"

/*CONSTRUCTOS & DESTRUCTORS*/
EntityList::EntityList(){

}
EntityList::~EntityList(){
    EntitiesList.clear();
}

/*SETTERS & GETTERS*/

/*METHODS*/
    void EntityList::includeEntity(Entity* p){
        if (p != NULL)
            EntitiesList.includeElement(p);     
    }
    void EntityList::drawAll(){//PODE APRESENTAR ERROS
        List<Entity*>::Element* cur=NULL;
        cur=EntitiesList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->drawThis(Object::getGraphicManager());
            cur=cur->getNextElement();
        }
    }
    void EntityList::updateAll(){
        List<Entity*>::Element* cur=NULL;
        cur=EntitiesList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->update();
            cur=cur->getNextElement();
        }
    }
    void EntityList::initAll(){
        List<Entity*>::Element* cur=NULL;
        cur=EntitiesList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->init();
            cur=cur->getNextElement();
        }
    }
    void EntityList::destroyAll(){
        List<Entity*>::Element* cur=NULL;
        List<Entity*>::Element* aux=NULL;
        cur=EnititiesList.getFirstElement();
        while (cur!=NULL){
            aux=cur->getNextElement();
            delete(cur->getValue());
            aux=cur;
        }

        EntitiesList.clear();
    }