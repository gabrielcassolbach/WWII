// TEMPLATE CLASS
#pragma once
#include <iostream>
using namespace std;

template <class TIPO>
class List
{
public:
    class Element
    {
    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        Element()
        {
            nextElement = NULL;
            prevElement = NULL;
        }
        ~Element()
        {
            nextElement = NULL;
            prevElement = NULL;
        }

        /*SETTERS & GETTERS*/
        void setPrevElement(Element *p)
        {
            prevElement = p;
        }
        Element *getPrevElement()
        {
            return prevElement;
        }
        void setNextElement(Element *n)
        {
            nextElement = n;
        }
        Element *getNextElement()
        {
            return nextElement;
        }
        void setValue(TIPO c)
        {
            Value = c;
        }
        TIPO getValue()
        {
            return Value;
        }

        /*METHODS*/
    private:
        Element *nextElement;
        Element *prevElement;
        TIPO Value;
    };

private:
    Element *firstElement;
    Element *currentElement;

public:

    /*CONSTRUCTORS & DESTRUCTORS*/
    List(){
        firstElement = NULL;
        currentElement = NULL;
    }
    ~List(){
        clear();
    }

    /*SETTERS & GETTERS*/
    void setFirstElement(Element *f){
        firstElement = f;
    }
    Element *getFirstElement(){
        return firstElement;
    }
    void setCurrentElement(Element *c){
        currentElement = c;
    }
    Element *getCurrentElement(){
        return(currentElement);
    }

    /*METHODS*/
    void clear(){
        Element *it = NULL;
        it = firstElement;
        Element *aux = NULL;

        while (it != NULL)
        {
            aux = it->getNextElement();
            delete (it);
            it = aux;
        }

        firstElement = NULL;
        currentElement = NULL;
    }   
    void includeElement(TIPO n){
        Element *newEl = NULL;
        newEl=new Element();
        newEl->setValue(n);

        if (currentElement != NULL)
            currentElement->setNextElement(newEl);
        else
            firstElement = newEl;

        newEl->setPrevElement(currentElement);
        currentElement=newEl;
    }
};