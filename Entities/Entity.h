#pragma once

namespace Entities
{

    class Entity  
    {
    protected:
        int x, y;

    public:
        Entity();
        ~Entity();

        virtual void executar() const = 0; /*Pedir!*/
   
        //virtual void renderizar();
    };

}