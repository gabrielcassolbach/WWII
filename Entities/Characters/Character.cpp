#include "Character.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
/*
- Posição inicial será (px, py)
- Posição como default é (0, 0)
- Velocidade inicial será (vx, vy)
- Velocidade como default é (0, 0)
- Tamanho inicial definido por (sx, sy)
- Tamanho inicial default como (0, 0)
*/
Character::Character(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam, const float atkCooldown) : MovingEntity(ident, px, py, sx, sy, vx, vy, dam),
                                                                                                                                              attackCooldown(atkCooldown)
{
    health = hp;
    cooldownAttackTimer = 0.0;
}

Character::~Character()
{
}

/*SETTERS & GETTERS*/
void Character::receiveDamage(int dam)
{
    health -= dam;
}

int Character::getHealth()
{
    return health;
}

void Character::increaseAttackTimer(double dt)
{
    cooldownAttackTimer += dt;
}

void Character::resetAttackTimer()
{
    cooldownAttackTimer = 0.0;
}

/*METHODS*/
bool Character::canAttack()
{
    if (cooldownAttackTimer >= attackCooldown)
        return 1;
    return 0;
}
