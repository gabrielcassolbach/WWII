#pragma once
#include "../Object.hpp"
#include <string>
 
class Entity : public Object
{
protected:
    int id;
    double position_x, position_y;
    double size_x, size_y;
    sf::RectangleShape retangulo;

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Entity(int ident=-1, double px = 0.0f, double py = 0.0f, double sx=0.0f, double sy=0.0f);
    virtual ~Entity();

/*SETTERS & GETTERS*/
    const int getId () const;
    sf::RectangleShape getRectangleShape() const;
    double getPosition_x() const;
    double getPosition_y() const;
    double getSize_x() const;
    double getSize_y() const;

/*METHODS*/
    void drawThis(Graphic_Manager *pGM);
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void collide (Entity* ent2, double inter_x, double inter_y)=0;
};

