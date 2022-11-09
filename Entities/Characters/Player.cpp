#include "Player.hpp"

#define PLAYER_VELOCITY 1.5
#define PLAYER_JUMP_HEIGHT 83.0
#define PLAYER_ATTACK_RANGE 20
#define PLAYER_DAMAGE_COOLDOWN 0.5
#define PLAYER_ATTACK_COOLDOWN 0.3
  
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
    walking = false;
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

void Player::setWalking(bool walk)
{
    walking = walk;
}

bool Player::getWalking()
{
    return walking;
}

void Player::receiveDamage(int dam)
{
    if (damageCooldownTimer > PLAYER_DAMAGE_COOLDOWN)
    {
        health -= damage;
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

    if (walking)
    {
        velocity_x = PLAYER_VELOCITY;
        if (getLeftDirection())
            velocity_x *= -1;
    }
    else   
        velocity_x = 0.0;

    velocity_y += 9.8 * timeFraction; // Aqui.

    position_x += (velocity_x);
    position_y += (velocity_y);

    retangulo.setPosition(sf::Vector2f(position_x, position_y));

    damageCooldownTimer += timeFraction;
}

void Player::collide(Entity *ent2, double inter_x, double inter_y)
{
    if (ent2->getId() == 4)
    {
        Character *pAttacker = static_cast<Character *>(ent2);
        receiveDamage(pAttacker->getDamage());
    }
    else
    {
        collisionMovement(ent2, inter_x, inter_y);
    }
}

void Player::jump(double timeFraction)
{
    if(!velocity_y)
        velocity_y = -sqrtf(PLAYER_JUMP_HEIGHT / 35 * 2 * 9.8);
    // Divide-se por 35 pois as dimensões do jogo estão numa escala 10x maior que a proporção da velocidade (valores reais).
}
 