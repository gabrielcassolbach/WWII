#pragma once
#include "Obstacle.hpp"

class Box : public Obstacle
{
private:
    bool pushingBox;

public: 
    Box(int ident = 2, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    ~Box();

    void setPushingBox(bool pushing);
    bool getPushingBox();

    void update(double timeFraction);
    void init();
    void collide(Entity *ent2, double inter_x, double inter_y);
};
