#include "Obstacle.hpp"
 
Obstacle::Obstacle(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
StaticEntity(ident, px, py, sx, sy, vx, vy)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::receiveDamage(int dam){
    
}
