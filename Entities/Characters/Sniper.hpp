#pragma once
#include "Enemy.hpp"
#include "../Projectile.hpp"

namespace Entities
{
    namespace Characters
    {

        class Sniper : public Enemy
        {
        private:
            Projectile *bullet;

        public:
            /*CONSTRUCTORS & DESTRUCTORS*/
            Sniper(int ident = 5, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int hp = 6, Player *pP = nullptr);
            ~Sniper();

            /*SETTERS & GETTERS*/
            Projectile *getBullet();

            /*METHODS*/
            void update(double timeFraction);
            void init();
            void collide(Entity *ent2, double inter_x, double inter_y);
            void attack();
            bool canAttack();
        };
    }
}