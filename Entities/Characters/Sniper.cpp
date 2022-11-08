#include "Sniper.hpp"

#define SNIPER_BULLET_SPEED 5
#define SNIPER_HEALTH 3
#define SNIPER_DAMAGE 4
#define SNIPER_SHOOTING_RANGE 400
#define SNIPER_SHOOTING_COOLDOWN 3

/*CONSTRUCTORS & DESTRUCTORS*/
Sniper::Sniper(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam, const float atkCooldown, Player* pP):
Enemy(ident, px, py, sx, sy, 0, 0, SNIPER_HEALTH, SNIPER_DAMAGE, SNIPER_SHOOTING_COOLDOWN, pP)
{
    bullet=nullptr;
    bullet= new Projectile(4, 0.0, -65.0, 2, 2, SNIPER_BULLET_SPEED, 0, SNIPER_DAMAGE);
}
Sniper::~Sniper(){
    bullet=nullptr;
}

/*SETTERS & GETTERS*/
Projectile* Sniper::getBullet(){
    return bullet;
}

/*METHODS*/
void Sniper::update(double timeFraction){
    Character::increaseAttackTimer(timeFraction);

    playerDistance=(pPlayer->getPosition_x())-position_x;
    if (playerDistance<=0)
        setLeftDirection(true);
    else
        setLeftDirection(false);

    if (fabs(playerDistance)<SNIPER_SHOOTING_RANGE && canAttack())
        attack();

    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}
void Sniper::init(){
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Red);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}
void Sniper::collide (Entity* ent2, double inter_x, double inter_y){

}
void Sniper::attack(){
    bullet->setActive(1);
    bullet->Entity::setPosition_x(position_x);
    bullet->Entity::setPosition_y(position_y);
    Character::resetAttackTimer();
    
    if (leftDirection)
        bullet->projectileReset(position_x, position_y, SNIPER_BULLET_SPEED*(-1.0), 0);
    else
        bullet->projectileReset(position_x, position_y, SNIPER_BULLET_SPEED, 0);
}
bool Sniper::canAttack(){
    if (!bullet->getActive() && cooldownAttackTimer>attackCooldown)
        return 1;
    return 0;
}
