#include "EntityList.hpp"

namespace Lists
{
    /*CONSTRUCTOS & DESTRUCTORS*/
    EntityList::EntityList()
    {
    }

    EntityList::~EntityList()
    {
        EntitiesList.clear();
    }

    /*SETTERS & GETTERS*/
    int EntityList::getSize()
    {
        return EntitiesList.getSize();
    }

    /*METHODS*/
    void EntityList::includeEntity(Entities::Entity *p)
    {
        if (p != NULL)
            EntitiesList.includeElement(p);
    }

    void EntityList::drawAll()
    {
        List<Entities::Entity *>::Element *cur = NULL;
        cur = EntitiesList.getFirstElement();
        while (cur != NULL)
        {
            cur->getValue()->drawThis(cur->getValue()->getGraphicManager());
            cur = cur->getNextElement();
        }
    }

    void EntityList::updateAll(double timeFraction)
    {
        List<Entities::Entity *>::Element *cur = NULL;
        cur = EntitiesList.getFirstElement();
        while (cur != NULL)
        {
            cur->getValue()->update(timeFraction);
            cur = cur->getNextElement();
        }
    }

    void EntityList::initAll()
    {
        List<Entities::Entity *>::Element *cur = NULL;
        cur = EntitiesList.getFirstElement();
        while (cur != NULL)
        {
            cur->getValue()->init();
            cur = cur->getNextElement();
        }
    }

    void EntityList::destroyAll()
    {
        EntitiesList.clear();
    }

    Entities::Entity *EntityList::operator[](int index)
    {
        int contador = 0;
        List<Entities::Entity *>::Element *cur = NULL;
        cur = EntitiesList.getFirstElement();
        while (cur->getNextElement() != NULL && contador < index)
        {
            contador++;
            cur = cur->getNextElement();
        }
        return (cur->getValue());
    }
}