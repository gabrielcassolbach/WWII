#include "Leaderboard.hpp"
#include "../Game.hpp"

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

void Leaderboard::setText()
{
    if (!font.loadFromFile("Font/PIXEARG_.TTF"))
    {
        cout << "error" << endl;
        exit(1);
    }

   Title.setFont(font);
   Title.setCharacterSize(50);
   Title.setFillColor(sf::Color::White);
   Title.setString("LEADERBOARD"); // 1 item
   Title.setPosition(sf::Vector2f(400, 50));
}

void Leaderboard::setBackground(){
    backgroundTexture.loadFromFile("Images/backgroundPauseMenu.jpg");
    backgroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
    backgroundRectangle.setTexture(&backgroundTexture);
    backgroundRectangle.setPosition(sf::Vector2f(0, 0));
}

/*METHODS*/
void Leaderboard::drawThis(Graphic_Manager *pGM)
{
    pGM->getWindow()->draw(backgroundRectangle);
    pGM->getWindow()->draw(Title);

    for (int i = 0; i < MAX_LEADERBOARD_ITENS; i++)
    {
        pGM->getWindow()->draw(text[i]);
        pGM->getWindow()->draw(text2[i]);
    }
    
}

void Leaderboard::draw()
{
    drawThis(pGM);
}

void Leaderboard::sortLeaderboard()
{

}

void Leaderboard::readLeaderboard(){
    if (!font.loadFromFile("Font/PIXEARG_.TTF"))
    {
        cout << "error" << endl;
        exit(1);
    }

    char ch[10];
    float pt;
    
    ifstream recover ( "Leaderboard.dat", ios::in );
    

    if ( !recover )
    {
        cerr << " Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar( );
    }

    while(!recover.eof())
    {
        recover >> ch >> pt;
        if(strcmp(ch, "") && strcmp(ch, "\n") && pt >= 0)
            map_leaderboard.insert(pair_(pt, string(ch)));

    }

    recover.close();

    map_::iterator it = map_leaderboard.begin();
    int i = 0;
    for(it = map_leaderboard.begin(); it != map_leaderboard.end() && i <= MAX_LEADERBOARD_ITENS; it++)
    {
        text[i].setString(string((*it).second));
        text[i].setFont(font);
        text[i].setCharacterSize(20);
        text[i].setFillColor(sf::Color::White);
        text[i].setPosition(sf::Vector2f(620, 200 + 100*i));
        text2[i].setString(string(std::to_string((*it).first)));
        text2[i].setFont(font);
        text2[i].setCharacterSize(20);
        text2[i].setFillColor(sf::Color::White);
        text2[i].setPosition(sf::Vector2f(780, 200 + 100*i));
        i++;
    }
}

void Leaderboard::input()
{
    sf::Event event;
    while ((pGM->getWindow())->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            (pGM->getWindow())->close();
        }
        break;

        case sf::Event::KeyPressed:
        {
            keyPressedAction(event);
        }
        break;

        default:
        {
        }
        break;
        }
    }
}

void Leaderboard::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Escape:
    {
        pGame->popState();
    }break;

    }
}
