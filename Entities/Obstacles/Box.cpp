#include "Box.hpp"
#define BOX_DAMAGE 1

namespace Entities
{
    namespace Obstacles
    {

        Box::Box(int ident, double px, double py, double sx, double sy, double vx, double vy) : Obstacle(ident, px, py, sx, sy, vx, vy)
        {
            damage = BOX_DAMAGE;
            crossable = 0;
        }
        Box::~Box()
        {
        }

        int Box::getDamage()
        {
            return damage;
        }
        void Box::update(double timeFraction)
        {
            velocity_x = 0.0f; // Aqui é necessário adicionar a parte de colisão. A fim de garantir que eu consiga mover a caixa.
            velocity_y += 9.8f * timeFraction;
            position_x += (velocity_x);
            position_y += (velocity_y);
            retangulo.setPosition(sf::Vector2f(position_x, position_y));
        }
        void Box::init()
        {
            text.loadFromFile("Images/box.png");
            retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
            retangulo.setTexture(&text);
            retangulo.setPosition(sf::Vector2f(position_x, position_y));
        }
        void Box::collide(Entity *ent2, double inter_x, double inter_y)
        {
            int id = ent2->getId();

            if (id == 3)
                collisionMovement(ent2, inter_x, inter_y);
        }
    }
}
