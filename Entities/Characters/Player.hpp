#include "Character.hpp"
#pragma once

class Player : public Character
{
private:
public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Player(int ident=0, double px = 0.0f, double py = 0.0f, double sx = 0.0f, double sy = 0.0f, double vx = 0.0f, double vy = 0.0f);
    ~Player();

    /*SETTERS & GETTERS*/

    /*METHODS*/
    void init();
    void update();
    void collide (Entity* ent2, double inter_x, double inter_y);
};