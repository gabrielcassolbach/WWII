#pragma once

class Ente
{
protected:
    int id;

public:
    Ente();
    ~Ente();

    virtual void executar() const = 0; /*pedir const.*/
    
    void setId(int i);
    const int getId() const;

    void imprimir();
};