#pragma once
#include "Entity.hpp"

class Character : public Entity
{
private:
    int vida;
    int dano;

public:
    Character();
    ~Character();
    void imprimir_se(Graphic_Manager *pGM);
    void atualizar_se();
};
