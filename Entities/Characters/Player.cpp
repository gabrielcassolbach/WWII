#include "Player.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Player::Player(double px, double py, double vx, double vy, double sx, double sy):
Character(px, py, vx, vy, sx, sy)
{
/*Construtora da class player
- Posição inicial do player será (px, py)
- Posição definida como default é (0, 0)
- Velocidade inicial do player será (vx, xy)
- Velocidade definida como default é (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial defautl como (0, 0)
*/
}
Player::~Player(){

}

/*SETTER & GETTERS*/
sf::RectangleShape Player::getRectangleShape(){
/*Função que retorna o retângulo
-
*/
    return retangulo;
}

/*METHODS*/
void Player::init (){
    /*Função que determina as propriedades básicas de um retângulo
    - Determina o tamanho do retângulo
    - Determina a cor do retângulo (azul para player e vermelho para inimigo)
    - Determina a posição inicial do retângulo
    */
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Blue);
    retangulo.setPosition(sf::Vector2f(x, y));
}
void Player::update(){
/*Função que atualiza as posições e velocidades de um objeto
- Altera a posição do objeto a cada frame de acordo com uma velocidade vx e vy.
- Determina a nova posição do retângulo
*/ 
    x+=velocity_x;
    y+=velocity_y;
    retangulo.setPosition(sf::Vector2f(x, y));
}