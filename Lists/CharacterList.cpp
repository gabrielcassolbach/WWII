#include "CharacterList.hpp"

/*CONSTRUCTOS & DESTRUCTORS*/
CharacterList::CharacterList(){

}
CharacterList::~CharacterList(){
    CharactersList.clear();
}

/*SETTERS & GETTERS*/

/*METHODS*/
    void CharacterList::includeCharacter(Character* p){
        if (p != NULL)
            CharactersList.includeElement(p);     
    }
    void CharacterList::drawAll(){
        List<Character*>::Element* cur=NULL;
        cur=CharactersList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->drawThis(cur->getValue()->getGraphicManager());
            cur=cur->getNextElement();
        }
    }
    void CharacterList::updateAll(){
        List<Character*>::Element* cur=NULL;
        cur=CharactersList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->update();
            cur=cur->getNextElement();
        }
    }
    void CharacterList::initAll(){
        List<Character*>::Element* cur=NULL;
        cur=CharactersList.getFirstElement();
        while (cur!=NULL){
            cur->getValue()->init();
            cur=cur->getNextElement();
        }
    }
    void CharacterList::destroyAll(){
        List<Character*>::Element* cur=NULL;
        List<Character*>::Element* aux=NULL;
        cur=CharactersList.getFirstElement();
        while (cur!=NULL){
            aux=cur->getNextElement();
            delete(cur->getValue());
            aux=cur;
        }

        CharactersList.clear();
    }