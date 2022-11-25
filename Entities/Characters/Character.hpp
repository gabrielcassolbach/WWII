#pragma once
#include "../MovingEntity.hpp"

namespace Entities
{
    namespace Characters
    {
        /*Classe que cria personagens*/
        class Character : public MovingEntity
        {
        protected:
            int health;

            const float attackCooldown;
            float cooldownAttackTimer;

        public:
            /*CONSTRUCTORS & DESTRUCTORS*/
            Character(int ident = -4, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f, int hp = 10, int dam = 2, const float atkCooldown = 0.0);
            virtual ~Character();
            virtual void init() = 0; // Função que inicializa os retangulos

            /*SETTERS & GETTERS*/
            virtual void receiveDamage(int dam);
            int getHealth();
            void increaseAttackTimer(double dt);
            void resetAttackTimer();

            /*METHODS*/
            virtual void update(double timeFraction) = 0;
            virtual void collide(Entity *ent2, double inter_x, double inter_y) = 0;
            virtual bool canAttack();
        };
    }
}
