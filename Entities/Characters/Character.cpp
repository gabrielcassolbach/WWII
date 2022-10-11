#include "stdafx.h"
#include "Character.hpp"

namespace Entities
{
    namespace Characters
    {
        Character::Character()
        {

        }

        Character::~Character()
        {

        }

        void Character::setNum_Vidas(const int life)
        {
            num_vidas = life;
        }

        const int Character::getNum_Vidas() const
        {
            return num_vidas;
        }
    }
}