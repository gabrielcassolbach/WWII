#pragma once
#include "Enemy.hpp"
#include "../Projectile.hpp"

namespace Entities
{
    namespace Characters
    {

        class Boss : public Enemy
        {
        private:
            Projectile *bullet;
            int evilness; // é necessário pensar sobre este atributo! ele é importante para diferenciar as classes.

        public:
            /*CONSTRUCTORS & DESTRUCTORS*/
            Boss(int ident = 9, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int hp = 6, Player *pP = nullptr);
            ~Boss();

            /*SETTERS & GETTERS*/
            Projectile *getBullet() const;

            /*METHODS*/
            void update(const double timeFraction);
            void updateVelocity(const double timeFraction);
            void updatePosition();
            void init();
            void collide(Entity *ent2, double inter_x, double inter_y);
            void attack();
            bool canAttack();
        };
    }
}
