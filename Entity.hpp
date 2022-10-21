#pragma once
#include "../Object.hpp"

namespace Entities
{
    class Entity : public Object
    {
        protected:
            double x, y;           
            double velocity_x, velocity_y;

        public:
            Entity(double xi = 0.0, double yi = 0.0, double velocity_x = 0.0, double velocity_y = 0.0);
            ~Entity();
            virtual void imprimir_se(Graphic_Manager* pGM) = 0;
            virtual void atualizar_se() = 0;
    };

}