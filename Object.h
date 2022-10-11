#pragma once

class Object
{
protected:
    int id;

public:
    Object();
    ~Object();

    virtual void executar() const = 0; /*pedir const.*/
    
    void setId(int i);
    const int getId() const;

    void imprimir();
};