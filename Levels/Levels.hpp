#pragma once
#include "../Lists/EntityList.hpp"
#include "../Managers/Graphic_Manager.hpp"
#include "../Managers/Collision_Manager.hpp"
#include "../Entities/Characters/Player.hpp"
#include "../Entities/Obstacles/Box.hpp"
#include "../Entities/Obstacles/Platform.hpp"
#include "../Entities/Characters/Samurai.hpp"
class Character;

class Levels
{
protected:                                                      

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Levels();
    ~Levels();

/*SETTERS & GETTERS*/


/*METHODS*/
    virtual void update()=0;
    virtual void render()=0;

};
