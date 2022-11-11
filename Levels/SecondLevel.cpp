#include "SecondLevel.hpp"

SecondLevel::SecondLevel() : CM()
{
    StaticEntityList.initAll();
    MovingEntityList.initAll();
    CM.init(&MovingEntityList, &StaticEntityList);
}

/* - Desaloca todos os objetos alocados dinamicamente
   - Faz o ponteiro da janela apontar para NULL
*/
SecondLevel::~SecondLevel()
{
    MovingEntityList.destroyAll();
    StaticEntityList.destroyAll();
}

/*SETTERS & GETTERS*/
Player *SecondLevel::getPlayerOne() const
{
    return pPlayer1;
}
Collision_Manager* SecondLevel::getCollisionManager(){
    return (&CM);
}

/*METHODS*/
void SecondLevel::update(double timeFraction)
{
    MovingEntityList.updateAll(timeFraction);
    StaticEntityList.updateAll(timeFraction);
    CM.collision();
}

void SecondLevel::render()
{
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}