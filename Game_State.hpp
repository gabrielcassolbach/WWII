#pragma once 

class Game;

class Game_State
{   
    protected:
        Game* game;
    
    public:
        Game_State();
        ~Game_State();

        virtual void draw() = 0;
        virtual void update(double timeFraction) = 0;
        //virtual void -> pegar dados do teclado().
};  