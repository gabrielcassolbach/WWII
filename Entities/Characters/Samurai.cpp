#include "Samurai.hpp"

#define SAMURAI_ATTACK_COOLDOWN 1.2
#define SAMURAI_VIEWDISTANCE 300.f
#define SAMURAI_VELOCITY_X 0.5
#define SAMURAI_ATTACK_RANGE 20
#define SAMURAI_DAMAGE 3

/*CONSTRUCTORS & DESTRUCTORS*/
Samurai::Samurai(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, Player *pP, int bt) : 
Enemy(ident, px, py, sx, sy, vx, vy, hp, SAMURAI_DAMAGE, SAMURAI_ATTACK_COOLDOWN, pP)
{
    belt=bt;
    velocity_y = 0.0;
    velocity_x = 0.0;    
}

Samurai::~Samurai()
{
}

/*SETTERS & GETTERS*/

/*METHODS*/
void Samurai::update(double timeFraction)
{
    Character::increaseAttackTimer(timeFraction);

    playerDistance = (pPlayer->getPosition_x()) - position_x;
    heightDistance=pPlayer->getPosition_y()-position_y;

    if (playerDistance <= 0)
        setLeftDirection(true);
    else
        setLeftDirection(false);

    if (fabs(playerDistance) < SAMURAI_VIEWDISTANCE && fabs(heightDistance)<getSize_y())
    {
        if (leftDirection)
            velocity_x = SAMURAI_VELOCITY_X * (-1);
        else
            velocity_x = SAMURAI_VELOCITY_X;
        
        if (fabs(playerDistance) < SAMURAI_ATTACK_RANGE && canAttack())
            attack();
    }

    velocity_y += GRAVITY * timeFraction;

    if (belt==2)
        velocity_x*=1.25;

    position_x += velocity_x;
    position_y += velocity_y;

    retangulo.setPosition(sf::Vector2f(position_x, position_y));
} 

void Samurai::init()
{
    text.loadFromFile("Images/samurai.png");
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setTexture(&text);
    //retangulo.setFillColor(sf::Color::Blue);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Samurai::collide(Entity *ent2, double inter_x, double inter_y)
{
    if (ent2->getId()==2 || ent2->getId()== 3 || ent2->getId()==1)
        collisionMovement(ent2, inter_x, inter_y);
    
    else if (ent2->getId()==4){
        health-=ent2->getDamage();
        if (health<=0){
            position_y=1000;
            pPlayer->operator+(15.0);
        }
    }
}

void Samurai::attack()
{
    pPlayer->receiveDamage(SAMURAI_DAMAGE);
    cooldownAttackTimer = 0;
}
