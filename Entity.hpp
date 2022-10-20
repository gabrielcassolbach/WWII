#pragma once

class Entity
{
protected:
    int id;

public:
    Entity();
    ~Entity();

    virtual void execute() = 0;
    void print();
};  