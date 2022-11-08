#pragma once
#include "../Lists/EntityList.hpp"
#include "../Managers/Graphic_Manager.hpp"
#include "../Managers/Collision_Manager.hpp"
#include "../Entities/Characters/Player.hpp"
#include "../Entities/Obstacles/Box.hpp"
#include "../Entities/Characters/Samurai.hpp"
#include "../Entities/Obstacles/Platform.hpp"
#include "../Entities/Projectile.hpp"
#include "../Entities/Characters/Sniper.hpp"
class Character;

class Levels : public Object
{
protected:  
    EntityList MovingEntityList;
    EntityList StaticEntityList;
    Player* pPlayer1;
    Sniper* pSniper1;                                                    

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Levels();
    ~Levels();

/*SETTERS & GETTERS*/


/*METHODS*/
    virtual void update(double timeFraction)=0;
    virtual void render()=0;

};
