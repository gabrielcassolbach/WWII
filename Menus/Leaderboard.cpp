#include "Leaderboard.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Leaderboard::Leaderboard(Game* pg){
    setBackground();
    setText();

    pGame=pg;
    nUsers=0;

    readLeaderboard();
    sortLeaderboard();
}

/*SETTERS & GETTERS*/
sf::RectangleShape Leaderboard::getRectangleShape() const{

 }
void Leaderboard::setText(){
    if (!font.loadFromFile("Font/PIXEARG_.TTF"))
    {
        cout << "error" << endl;
        exit(1);
    }

    text[0].setFont(font);
    text[0].setCharacterSize(50);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("LEADERBOARD"); // 1 item
    text[0].setPosition(sf::Vector2f(400, 50));
}
void Leaderboard::setBackground(){
    backgroundTexture.loadFromFile("Images/backgroundPauseMenu.jpg");
    backgroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
    backgroundRectangle.setTexture(&backgroundTexture);
    backgroundRectangle.setPosition(sf::Vector2f(0, 0));
}

/*METHODS*/
void Leaderboard::drawThis(Graphic_Manager *pGM){
     pGM->getWindow()->draw(backgroundRectangle);

    for (int i = 0; i < MAX_LEADERBOARD_ITENS; i++)
    {
        pGM->getWindow()->draw(text[i]);
    }
}
void Leaderboard::draw(){
    drawThis(pGM);
}
void Leaderboard::sortLeaderboard(){

}
void Leaderboard::readLeaderboard(){

}





