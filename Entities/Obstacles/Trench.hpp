#pragma once
#include "Obstacle.hpp"

namespace Entities
{
    namespace Obstacles
    {
        class Trench : public Obstacle
        {
        private:
            double slowness;

        public:
            Trench(int ident = 6, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
            ~Trench();

            double getSlowness();

            void update(double timeFraction);
            void init();
            void collide(Entity *ent2, double inter_x, double inter_y);
        };
    }
}
