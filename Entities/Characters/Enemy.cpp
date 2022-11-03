#include "Enemy.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Enemy::Enemy(int ident, double px, double py, double sx, double sy, double vx, double vy, int hp, int dam):
Character(ident, px, py, sx, sy, vx, vy, hp, dam)
{

}
Enemy::~Enemy(){

}