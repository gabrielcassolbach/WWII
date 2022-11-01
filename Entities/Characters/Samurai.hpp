#include "Enemy.hpp"

class Samurai: public Enemy{
private:

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Samurai(double px=0.0f, double py=0.0f, double sx=0.0f, double sy=0.0f, double vx=0.0f, double vy=0.0f);
    ~Samurai();

/*SETTERS & GETTERS*/

/*METHODS*/
    void update();
    void init();
};