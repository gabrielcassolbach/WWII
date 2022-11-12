#include "Menu.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Menu::Menu(Game* pg){
    pGame=pg;
}
Menu::~Menu(){
    pGame=nullptr;
}
void Menu::init (){

}

/*SETTERS & GETTERS*/
sf::RectangleShape Menu::getRectangleShape() const{
    
}

/*METHODS*/
void Menu::drawThis(Graphic_Manager* pGM){

}