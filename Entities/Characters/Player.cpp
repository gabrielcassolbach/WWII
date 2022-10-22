#include "Player.hpp"

Player::Player(){

}

Player::~Player(){

}

void Player::init (){
    retangulo = sf::RectangleShape(sf::Vector2f(100, 100));
    retangulo.setFillColor(sf::Color::Blue);
}

sf::RectangleShape Player::getRectangleShape(){
    return retangulo;
}