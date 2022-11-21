#include "Boss.hpp"

#define BOSS_BULLET_SPEED 7
#define BOSS_HEALTH 15
#define BOSS_DAMAGE 11
#define BOSS_SHOOTING_RANGE 400
#define BOSS_SHOOTING_COOLDOWN 3
#define BOSS_VELOCITY 0.7
#define BOSS_VIEWDISTANCE 400.f
#define BOSS_ATTACK_RANGE 20


/*CONSTRUCTORS & DESTRUCTORS*/
Boss::Boss(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam, const float atkCooldown, Player *pP) : 
Enemy(ident, px, py, sx, sy, 0, 0, BOSS_HEALTH, BOSS_DAMAGE, BOSS_SHOOTING_COOLDOWN , pP)
{
    bullet = nullptr;
    bullet = new Projectile(4, 0.0, -65.0, 4, 4, BOSS_BULLET_SPEED, 0, BOSS_DAMAGE);
}

Boss::~Boss()
{
    bullet = nullptr;
}

/*SETTERS & GETTERS*/
Projectile *Boss::getBullet()
{
    return bullet;
}

/*METHODS*/
void Boss::update(double timeFraction)
{
    Character::increaseAttackTimer(timeFraction);

    playerDistance = (pPlayer->getPosition_x()) - position_x;

    double heightDistance;
    heightDistance=pPlayer->getPosition_y()-position_y;

    if (playerDistance <= 0){
        setLeftDirection(true);
        velocity_x=-BOSS_VELOCITY;
    }
    else{
        setLeftDirection(false);
        velocity_x=BOSS_VELOCITY;
    }

    if (fabs(playerDistance) < BOSS_SHOOTING_RANGE && canAttack())
        attack();

    if (fabs(playerDistance) < BOSS_VIEWDISTANCE)
    {
        if (leftDirection)
            velocity_x = BOSS_VELOCITY * (-1);
        else
            velocity_x = BOSS_VELOCITY;
    }

    velocity_y+=GRAVITY* timeFraction;

    position_x+=velocity_x;
    position_y+=velocity_y;

    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Boss::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Cyan);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Boss::collide(Entity *ent2, double inter_x, double inter_y)
{
    int id = ent2 -> getId();

    if (id == 2 || id == 3 || id == 9 || id == 1)
        collisionMovement(ent2, inter_x, inter_y);
    
    if (id == 4)
    {
        health-=ent2->getDamage();
        if (health<=0){
            position_y=1000;
            pPlayer->operator+(32.0);
        }
    }

    if(id == 1)
        collisionMovement(ent2, inter_x, inter_y);

}
   
void Boss::attack()
{
    bullet->setActive(1);
    bullet->Entity::setPosition_x(position_x);
    bullet->Entity::setPosition_y(position_y);
    Character::resetAttackTimer();

    if (leftDirection)
        bullet->projectileReset(position_x, position_y, -BOSS_BULLET_SPEED, 0);
    else
        bullet->projectileReset(position_x+size_x, position_y, BOSS_BULLET_SPEED, 0);

}

bool Boss::canAttack()
{
    if (!bullet->getActive() && cooldownAttackTimer > attackCooldown)
        return 1;
    return 0;
}
