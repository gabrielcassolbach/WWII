#include "Enemy.hpp"

class Samurai: public Enemy{
private:

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Samurai(int ident=1, double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f, int hp=6, int dam=2);
    ~Samurai();

/*SETTERS & GETTERS*/

/*METHODS*/
    void update();
    void init();
    void collide (Entity* ent2, double inter_x, double inter_y);
};