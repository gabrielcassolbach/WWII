#pragma once
#include "Obstacle.hpp"

namespace Entities
{
    namespace Obstacles
    {
        class Platform : public Obstacle
        {
        private:
            float floatabily_constant;

        public:
            Platform(int ident = 3, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
            ~Platform();

            void update(double timeFraction);
            void init();
            void collide(Entity *ent2, double inter_x, double inter_y);
        };
    }
}
