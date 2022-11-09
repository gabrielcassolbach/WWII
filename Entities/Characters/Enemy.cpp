#include "Enemy.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Enemy::Enemy(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam, const float atkCooldown, Player *pP) : 
Character(ident, px, py, sx, sy, vx, vy, hp, dam, atkCooldown)
{
    pPlayer = pP;
}

Enemy::~Enemy()
{
}

/*SETTERS & GETTERS*/
void Enemy::setPPlayer(Player *pP)
{
    pPlayer = pP;
}
