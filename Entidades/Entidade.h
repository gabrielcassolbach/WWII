#pragma once

namespace Entidades
{

    class Entidade
    {
    protected:
        int x, y;

    public:
        Entidade();
        ~Entidade();

        virtual void executar() const = 0; /*Pedir!*/
   
        //virtual void renderizar();
    };

}