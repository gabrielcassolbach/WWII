#pragma once
#include "Obstacle.hpp"

class Box : public Obstacle
{
    private:
        // Empty!
    public:
        Box(double px = 0.0f, double py = 0.0f, double sx=0.0f, double sy=0.0f);
        ~Box();

        void update();
        void init();

};




