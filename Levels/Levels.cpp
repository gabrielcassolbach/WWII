#include "Levels.hpp"

// Início do desenvolvimento dia 28/10/22.
/*CONSTRUCTORS & DESTRUCTORS*/
Levels::Levels(){

}
Levels::~Levels(){

}

Player* Levels::getPlayer(int player_selected)
{
    for(int i = 0; i < pPlayersList.size(); i++)
    {
        if(i+1 == player_selected)  return pPlayersList[i];
    }
}