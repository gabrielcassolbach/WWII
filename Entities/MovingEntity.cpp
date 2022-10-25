#include "MovingEntity.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
MovingEntity::MovingEntity(double px, double py, double sx, double sy, double vx, double vy):
Entity(px, py, sx, sy){
    velocity_x=vx;
    velocity_y=vy;
}
MovingEntity::~MovingEntity(){

}

/*SETTERS & GETTERS*/

/*METHODS*/