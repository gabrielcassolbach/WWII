#include "GameOverMenu.hpp"

/*CONTRUCTORS & DESTRUCTORS*/
GameOverMenu::GameOverMenu(Game *pg, double points)
{
    totalPoints1=points;
    nameSize=0;
    cout<<points<<endl;

    for (int i=0; i<10; i++){
        name[i]='_';
    }
    name[9]='\0';

    setText();
    setBackground();
    pGame = pg;
}

GameOverMenu::~GameOverMenu()
{
    pGame = nullptr;
}

/*SETTERS & GETTERS*/
void GameOverMenu::setText()
{
    if (!font.loadFromFile("Font/PIXEARG_.TTF"))
    {
        cout << "error" << endl;
        exit(1);
    }

    text[0].setFont(font);
    text[0].setCharacterSize(50);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("GAME OVER!"); // 1 item
    text[0].setPosition(sf::Vector2f(400, 220));

    text[1].setFont(font);
    text[1].setCharacterSize(30);
    text[1].setFillColor(sf::Color::Yellow);
    text[1].setString("Insert your name:"); // 1 item
    text[1].setPosition(sf::Vector2f(300, 400));

    text[2].setFont(font);
    text[2].setCharacterSize(10);
    text[2].setFillColor(sf::Color::Yellow);
    text[2].setString("1- Back to menu"); // 1 item
    text[2].setPosition(sf::Vector2f(100, 680));

    text[4].setFont(font);
    text[4].setCharacterSize(30);
    text[4].setFillColor(sf::Color::Yellow);
    text[4].setString("Points: "); // 1 item
    text[4].setPosition(sf::Vector2f(300, 460));

    int pointsShowed=(int)totalPoints1;
    cout<<pointsShowed<<endl;
    string str = to_string (pointsShowed);
    text[5].setFont(font);
    text[5].setCharacterSize(30);
    text[5].setFillColor(sf::Color::Yellow);
    text[5].setString(str); // 1 item
    text[5].setPosition(sf::Vector2f(460, 460));
}

void GameOverMenu::setBackground()
{
    backgroundTexture.loadFromFile("Images/backgroundPauseMenu.jpg");
    backgroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
    backgroundRectangle.setTexture(&backgroundTexture);
    backgroundRectangle.setPosition(sf::Vector2f(0, 0));
}

/*METHODS*/
void GameOverMenu::drawThis(Graphic_Manager *pGM)
{
    pGM->getWindow()->draw(backgroundRectangle);

    for (int i = 0; i < ITENS_GAMEOVER_MENU; i++)
    {
        pGM->getWindow()->draw(text[i]);
    }
}

void GameOverMenu::draw()
{
    drawThis(pGM);
}

void GameOverMenu::input()
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

void GameOverMenu::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Num1:
    {
        pGame->popState();
        pGame->popState();
    }break;
    case sf::Keyboard::Enter:
    {
        saveLeaderboard();
    }break;
    default:
    {
        writeLetter(event);
    }
    }
}

void GameOverMenu::writeLetter(sf::Event event){
    if (nameSize<10){
        if (event.text.unicode < 128){
            char character= static_cast<char>(event.text.unicode+65);
            name[nameSize]=character;
            nameSize++;
        }
    }
    
    text[6].setFont(font);
    text[6].setCharacterSize(30);
    text[6].setFillColor(sf::Color::Yellow);
    text[6].setString(name); // 1 item
    text[6].setPosition(sf::Vector2f(650, 400));
}

void GameOverMenu::saveLeaderboard()
{
    ofstream saver ( "Leaderboard.dat", ios::out | ios::app);
    
    if ( !saver ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    saver<<name<<' '<<totalPoints1<<endl;
    saver.close();
}



