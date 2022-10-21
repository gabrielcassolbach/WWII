#pragma once
#include "Entity.hpp"

namespace Entities
{
    class Character : public Entity
    {
    private:
        int vida;
        int dano;

    public:
        Character(int vida = 0, int dano = 0);
        ~Character();
        void imprimir_se(Graphic_Manager *pGM);
    };
}
