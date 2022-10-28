#pragma once

class EntityList;
class Graphic_Manager;
class Collision_Manager;

class Levels
{
protected:   
    EntityList* MovingEntityList;
    EntityList* StaticEntityList;
    Graphic_Manager* pGM;
    Collision_Manager* CM;
    double gravity;

private:
    Levels();
    ~Levels();

    virtual void draw(Graphic_Manager*) = 0;
    virtual void uptade() = 0;

};

/*
A ideia da fábrica é, a partir da lista que existe dentro da classe Level, 
ir criando e colocando na lista.

*/