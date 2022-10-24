//CLASSE TEMPLATE
#pragma once

template<class TIPO>
class List{
private:
    class Element{
        public:
        /*CONSTRUCTORS & DESTRUCTORS*/
            Element();
            ~Element();

        /*SETTERS & GETTERS*/
            void setPrevElement (Element* p);
            Element* getPrevElement ();
            void setNextElement (Element* n);
            Element* getNextElement ();
            void setValorCorrespondente (TIPO* c);
            TIPO* getValorCorrespondente ();

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