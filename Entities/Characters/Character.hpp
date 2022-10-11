#pragma once

namespace Entities
{
    namespace Characters
    {
        class Character
        {
        protected:
            int num_vidas;

        public:
            Character();
            ~Character();

            void setNum_Vidas(const int life);
            const int getNum_Vidas() const;
        };

    }
}
