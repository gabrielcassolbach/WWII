#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle
{
    private:
        // Empty!
    public:
        Platform(int ident=5,double px = 0.0f, double py = 0.0f, double sx=0.0f, double sy=0.0f);
        ~Platform();

        void update();
        void init();

};
