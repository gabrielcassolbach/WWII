#include "Samurai.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/
Samurai::Samurai(double px, double py, double sx, double sy, double vx, double vy):
Enemy(px, py, sx, sy, vx, vy)
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



