#include "stdafx.h"
#include "Personagem.h"

Personagem::Personagem()
{

}

Personagem::~Personagem()
{

}

void Personagem::setNum_Vidas(const int life)
{
    num_vidas = life;
}

const int Personagem::getNum_Vidas() const
{
    return num_vidas;
}