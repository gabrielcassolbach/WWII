//CLASSE TEMPLATE
#pragma once
#include <iostream>
using namespace std;

template<class TIPO>
class List{
private:
    class Element{
        public:
        /*CONSTRUCTORS & DESTRUCTORS*/
            Element(){
                nextElement=NULL;
                prevElement=NULL;
                valorCorrespondente=NULL;
            }
            ~Element(){
                nextElement=NULL;
                prevElement=NULL;
                valorCorrespondente=NULL;
            }

        /*SETTERS & GETTERS*/
            void setPrevElement (Element* p){
                prevElement=p;
            }
            Element* getPrevElement (){
                return prevElement;
            }
            void setNextElement (Element* n){
                nextElement=n;
            }
            Element* getNextElement (){
                return nextElement;
            }
            void setValorCorrespondente (TIPO* c){
                valorCorrespondente=c;
            }
            TIPO* getValorCorrespondente (){
                return valorCorrespondente;
            }

        /*METHODS*/
        private:
            Element* nextElement;
            Element* prevElement;
            TIPO* valorCorrespondente;

    };
    Element* firstElement;
    Element* currentElement;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    List();
    ~List();

/*SETTERS & GETTERS*/
    void setFirstElement (Element* f);
    Element* getFirstElement ();
    void setCurrentElement (Element* c);
    Element* getCurrentElement();

/*METHODS*/
    void clear();
    void includeElement(Element* n);
};


template <class TIPO>
List<TIPO>::List(){
    firstElement=NULL;
    currentElement=NULL;
}
template <class TIPO>
List<TIPO>::~List(){
    clear();
    firstElement=NULL;
    currentElement=NULL;
}

/*SETTERS & GETTERS*/
template <class TIPO>
void List<TIPO>::setFirstElement (Element* f){
    firstElement=f;
}
template <class TIPO>
Element* List<TIPO>::getFirstElement (){
    return firstElement;
}
template <class TIPO>
void List<TIPO>::setCurrentElement (Element* c){
    currentElement=c;
}
template <class TIPO>
Element* List<TIPO>::getCurrentElement(){
    return currentElement;
}

/*METHODS*/
template <class TIPO>
void List<TIPO>::clear(){
    Element* it=NULL;
    aux=firstElement;
    Element* aux= NULL;

    while (it!=NULL){
        aux=it->getNextElement();
        delete(it);
        it=aux;
    }
}
template<class TIPO>
void List<TIPO>::includeElement(TIPO* n){
    Element* newEl=NULL;
    newEl->setValorCorrespondente(n);
    if (currentElement!=NULL)
        currentElement->setNextElement(newEl);
    else{
        firstElement=newEl;
        currentElement=newEl;
    }

    newEl->setPrevElement(currentElement);
}