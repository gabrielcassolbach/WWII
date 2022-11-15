#include "Menu.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Menu::Menu(Game *pg)
{
    setText();
    setBackground();
    pGame = pg;
}

Menu::~Menu()
{
    pGame = nullptr;
}

/*SETTERS & GETTERS*/
sf::RectangleShape Menu::getRectangleShape() const
{
}

void Menu::setText()
{
    if(!font.loadFromFile("Font/PIXEARG_.TTF")) {cout << "error" << endl; exit(1);}
    
    Title.setFont(font);
    Title.setCharacterSize(40);
    Title.setFillColor(sf::Color::Black);
    Title.setString("Battle for Monte Castello"); // 1 item
    Title.setPosition(sf::Vector2f(400, 30));

    text[0].setFont(font);
    text[0].setCharacterSize(35);
    text[0].setFillColor(sf::Color::Red);
    text[0].setString("First Level"); // 1 item
    text[0].setPosition(sf::Vector2f(500, 220));

    text[1].setFont(font);
    text[1].setCharacterSize(35);
    text[1].setFillColor(sf::Color::Red);
    text[1].setString("Second Level"); // 2 item ...
    text[1].setPosition(sf::Vector2f(500, 320)); // Janela 1280 x 720.

    text[2].setFont(font);
    text[2].setCharacterSize(35);
    text[2].setFillColor(sf::Color::Red);;
    text[2].setString("Ranking");
    text[2].setPosition(sf::Vector2f(500, 420));

    text[3].setFont(font);
    text[3].setCharacterSize(35);
    text[3].setFillColor(sf::Color::Red);
    text[3].setString("Pause");
    text[3].setPosition(sf::Vector2f(500, 520));
}

/*METHODS*/
void Menu::drawThis(Graphic_Manager *pGM)
{   
    pGM->getWindow()->draw(backgroundSprite);
    
    pGM -> getWindow() -> draw(Title);

    for(int i = 0; i < MAX_NUMBER_OF_ITENS; i++)
    {
        pGM->getWindow()->draw(text[i]);   
    }
}   

void Menu::init()
{

}

void Menu::draw()
{
    drawThis(pGM);
}


void Menu::setBackground()
{
    backgroundTexture.loadFromFile("Images/backgroundMenu.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);   
}

void Menu::update(double timeFraction)
{

}