#pragma once
#include "Obstacle.hpp"

class Cannon : public Obstacle
{
private:
    sf::Texture text;
public: 
    Cannon(int ident = 7, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    ~Cannon();

    void update(double timeFraction);
    void init();
    void collide(Entity *ent2, double inter_x, double inter_y);
};
