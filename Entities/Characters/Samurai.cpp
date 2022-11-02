#include "Samurai.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Samurai::Samurai(int ident, double px, double py, double sx, double sy, double vx, double vy):
Enemy(ident, px, py, sx, sy, vx, vy)
{
}
Samurai::~Samurai(){

}

/*SETTERS & GETTERS*/

/*METHODS*/
void Samurai::update(){
}
void Samurai::init(){
    retangulo = sf::RectangleShape(sf::Vector2f(size_x, size_y));
    retangulo.setFillColor(sf::Color::White);
    retangulo.setPosition(sf::Vector2f(position_x, position_y));
}
void Samurai::collide (Entity* ent2, double inter_x, double inter_y){

}



