#include "Levels.hpp"

// Início do desenvolvimento dia 28/10/22.
/*CONSTRUCTORS & DESTRUCTORS*/
Levels::Levels(Game* pg, int np)
{
    srand(time(0));
    pGame = pg;
    nPlayers=np;
}

Levels::~Levels(){

}

EntityList* Levels::getMovingEntityList() {
    return &MovingEntityList;
}
EntityList* Levels::getStaticEntityList() {
    return &StaticEntityList;
}
Player* Levels::getPlayer(int player_selected)
{
    for(int i = 0; i < pPlayersList.size(); i++)
    {
        if(i+1 == player_selected)  return pPlayersList[i];
    }
}
int Levels::getNPlayers(){
    return nPlayers;
}

int Levels::randomQuantity()
{   
    int ret;
    ret=rand()%3+3;

    cout<<"--"<<ret<<endl;
    return ret;
}
