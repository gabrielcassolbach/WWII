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

void Levels::initPointsText(){
    if(!font.loadFromFile("Font/PIXEARG_.TTF")) {cout << "error" << endl; exit(1);}
    
    showPoints1.setFont(font);
    showPoints1.setCharacterSize(20);
    showPoints1.setFillColor(sf::Color::Black);
    int points1=pPlayersList[0]->getPoints();
    string str= to_string(points1);
    showPoints1.setString(str);
    showPoints1.setPosition(sf::Vector2f(30, 30));

    if (nPlayers==2){
        showPoints2.setFont(font);
        showPoints2.setCharacterSize(20);
        showPoints2.setFillColor(sf::Color::Black);
        int points2=pPlayersList[0]->getPoints();
        string str= to_string(points2);
        showPoints2.setString(str);
        showPoints2.setPosition(sf::Vector2f(30, 57));
    }
}
int Levels::randomQuantity()
{   
    int ret;
    ret=rand()%3+3;

    cout<<"--"<<ret<<endl;
    return ret;
}
