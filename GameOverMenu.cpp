#include "GameOverMenu.hpp"

GameOverMenu::GameOverMenu(Game *pg)
{
    setText();
    setBackground();
    pGame = pg;
}
GameOverMenu::~GameOverMenu()
{
    pGame = nullptr;
}
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
}

void GameOverMenu::setBackground()
{
    backgroundTexture.loadFromFile("Images/backgroundPauseMenu.jpg");
    backgroundRectangle = sf::RectangleShape(sf::Vector2f(1280, 720));
    backgroundRectangle.setTexture(&backgroundTexture);
    backgroundRectangle.setPosition(sf::Vector2f(0, 0));
}

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
    }
    break;
    }
}
