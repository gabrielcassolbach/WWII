#include "Projectile.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Projectile::Projectile(int ident, double px, double py, double sx, double sy, double vx, double vy, int dam) : MovingEntity(ident, px, py, sx, sy, vx, vy, dam)
{
    active = 0;
}

Projectile::~Projectile()
{
}

/*SETTERS & GETTERS*/
bool Projectile::getActive()
{
    return active;
}

void Projectile::setActive(bool ac)
{
    active = ac;
}

/*METHODS*/
void Projectile::projectileReset(double px, double py, double vx, double vy)
{
    position_x = px;
    position_y = py;
    velocity_x = vx;
    velocity_y = vy;
}

void Projectile::update(double timeFraction)
{
    if (active)
    {
        velocity_y = GRAVITY * timeFraction;
    }

    position_x += velocity_x;
    position_y += velocity_y;

    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Projectile::init()
{
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::Red);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}

void Projectile::collide(Entity *ent2, double inter_x, double inter_y)
{
    active = false;
    position_x = 0.0;
    position_y = -65.0;
}