#include "Player.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Player::Player(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp):
Character(ident, px, py, sx, sy, vx, vy, hp)
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


/*METHODS*/
void Player::init ()
{
    /*Função que determina as propriedades básicas de um retângulo
    - Determina o tamanho do retângulo
    - Determina a cor do retângulo (azul para player e vermelho para inimigo)
    - Determina a posição inicial do retângulo
    */
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Blue);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}
void Player::update(){
/*Função que atualiza as posições e velocidades de um objeto
- Altera a posição do objeto a cada frame de acordo com uma velocidade vx e vy.
- Determina a nova posição do retângulo
*/ 
    position_x+=velocity_x;
    position_y+=velocity_y;
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}
void Player::collide (Entity* ent2, double inter_x, double inter_y){
    if (ent2->getId()==1){
        Character* pAttacker = static_cast<Character*>(ent2);
        cout<<"Colisao player com Samurai"<<endl;
    }    
    else{
        collisionMovement(ent2, inter_x, inter_y);
        switch(ent2->getId()){
            case 2:{
                cout<<"Colisao com uma caixa"<<endl;
                break;
            }
        }
    }
}






