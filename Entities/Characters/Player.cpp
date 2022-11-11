#include "Player.hpp"

#define PLAYER_VELOCITY 1.5
#define PLAYER_JUMP_HEIGHT 83.0
#define PLAYER_ATTACK_RANGE 50
#define PLAYER_DAMAGE_COOLDOWN 0.5
#define PLAYER_ATTACK_COOLDOWN 0.3
#define SLOW_ACELERATION 0.3
#define FAST_ACELERATION 1.5



/*CONSTRUCTORS & DESTRUCTORS*/
/*Construtora da class player
    - Posição inicial do player será (px, py)
    - Posição definida como default é (0, 0)
    - Velocidade inicial do player será (vx, xy)
    - Velocidade definida como default é (0, 0)
    - Tamanho inicial definido por (sx, sy)
    - Tamanho inicial defautl como (0, 0)
*/

Player::Player(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam, const float atkCooldown) : 
Character(ident, px, py, sx, sy, vx, vy, hp, dam, PLAYER_ATTACK_COOLDOWN),
attackRange(PLAYER_ATTACK_RANGE)
{
    velocity_x = 0;
    velocity_y = 0;
    
    damageCooldownTimer = 0;
}

Player::~Player()
{
}

/*SETTER & GETTERS*/
void Player::setVelocity(double vx, double vy)
{
    velocity_x = vx;
    velocity_y = vy;
}

double Player::getVelocity_x()
{
    return velocity_x;
}

double Player::getVelocity_y()
{
    return velocity_y;
}

void Player::setVelocity_x(double vx)
{
    velocity_x = vx;
}

void Player::setVelocity_y(double vy)
{
    velocity_y = vy;
}

void Player::receiveDamage(int dam)
{
    if (damageCooldownTimer > PLAYER_DAMAGE_COOLDOWN)
    {
        health -= dam;
        if (health <= 0)
            cout << "Morto" << endl;
        cout << health << endl;
        damageCooldownTimer = 0;
    }
}

/*METHODS*/
/*  Função que determina as propriedades básicas de um retângulo
    - Determina o tamanho do retângulo
    - Determina a cor do retângulo (azul para player e vermelho para inimigo)
    - Determina a posição inicial do retângulo
*/
void Player::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Green);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

/*Função que atualiza as posições e velocidades de um objeto
    - Altera a posição do objeto a cada frame de acordo com uma velocidade vx e vy.
    - Determina a nova posição do retângulo
*/
void Player::update(double timeFraction)
{
    Character::increaseAttackTimer(timeFraction);

    velocity_x = PLAYER_VELOCITY * aceleration;
    
    if (getLeftDirection())
        velocity_x*=(-1);    

    velocity_y += 9.8 * timeFraction; // Aqui.

    position_x += (velocity_x);
    position_y += (velocity_y);

    retangulo.setPosition(sf::Vector2f(position_x, position_y));

    damageCooldownTimer += timeFraction;
}

void Player::collide(Entity *ent2, double inter_x, double inter_y)
{

    int id = ent2 -> getId();

    if (id == 4)
    {
        Character *pAttacker = static_cast<Character *>(ent2);
        receiveDamage(pAttacker->getDamage());
    }

    if (id == 3){
        collisionMovement(ent2, inter_x, inter_y);
        aceleration = 1;
    }

    if(id == 2)
        collisionMovement(ent2, inter_x, inter_y);
 
    if(id == 6){
        aceleration = SLOW_ACELERATION;    
    } 

    if(id == 7){
        aceleration = FAST_ACELERATION;
    }
        
    
}

void Player::jump(double timeFraction)
{
    if(!velocity_y)
        velocity_y = -sqrtf(PLAYER_JUMP_HEIGHT / 35 * 2 * 9.8);
    // Divide-se por 35 pois as dimensões do jogo estão numa escala 10x maior que a proporção da velocidade (valores reais).
}

void Player::attack(Collision_Manager* CM){
    sf::RectangleShape hitBox;
    hitBox=sf::RectangleShape(sf::Vector2f(2*PLAYER_ATTACK_RANGE+size_x, size_y));
    hitBox.setFillColor(sf::Color(0, 0, 0, 255));
    hitBox.setPosition(sf::Vector2f(position_x-PLAYER_ATTACK_RANGE, position_y));
    
    CM->playerAttack(hitBox);
}
















