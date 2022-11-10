#include "StaticEntity.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
StaticEntity::StaticEntity(int ident, double px, double py, double sx, double sy, double vx, double vy) : 
Entity(ident, px, py, sx, sy)
{
    velocity_x = vx;
    velocity_y = vy;
}

StaticEntity::~StaticEntity()
{
}

/*SETTERS & GETTERS*/
void StaticEntity::setVelocity_x(double vx){
    velocity_x=vx;
}
void StaticEntity::setVelocity_y(double vy){
    velocity_y=vy;
}


/*METHODS*/

void StaticEntity::collisionMovement(Entity *ent2, double intersection_x, double intersection_y)
{
    if (intersection_x<intersection_y){
        if (position_x>ent2->getPosition_x())
            position_x+=intersection_x;
        else
            position_x-=intersection_x;
        velocity_x = 0.0;
    }
    else{
        if (position_y>ent2->getPosition_y())
            position_y+=intersection_y;
        else
            position_y-=intersection_y;
        velocity_y = 0.0;
    }
}