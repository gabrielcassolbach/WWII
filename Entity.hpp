#pragma once

#include "Object.hpp"

class Entity : public Object
{
protected:
    double x, y;
    double velocity_x, velocity_y;

public:
    Entity(double px = 0.0f, double py = 0.0f, double vx = 0.0f, double vy = 0.0f);
    ~Entity();
    virtual void imprimir_se(Graphic_Manager *pGM) = 0;
    virtual void atualizar_se() = 0;
};
