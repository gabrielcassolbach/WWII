#pragma once

class Personagem
{
protected:
    int num_vidas;

public:
    Personagem();
    ~Personagem();

    void setNum_Vidas(const int life);
    const int getNum_Vidas() const;
};