#pragma once
#include "../Lists/EntityList.hpp"
#include "../Managers/Graphic_Manager.hpp"
#include "../Managers/Collision_Manager.hpp"
#include "../Entities/Characters/Player.hpp"
#include "../Entities/Obstacles/Box.hpp"
#include "../Entities/Obstacles/Trench.hpp"
#include "../Entities/Obstacles/Cannon.hpp"
#include "../Entities/Characters/Samurai.hpp"
#include "../Entities/Obstacles/Platform.hpp"
#include "../Entities/Projectile.hpp"
#include "../Entities/Characters/Sniper.hpp"

class Character;

class Levels : public Enty
{
protected:  
    EntityList MovingEntityList;
    EntityList StaticEntityList;
    Player* pPlayer1;
    Sniper* pSniper1;  
    Sniper* pSniper2;   
    Sniper* pSniper3;  
    Sniper* pSniper4;                                                     

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Levels();
    ~Levels();

/*SETTERS & GETTERS*/

/*METHODS*/
    virtual void update(double timeFraction) = 0;
    virtual void render() = 0;
    virtual void createEnemies() = 0;
    virtual void createPlatforms() = 0;
    virtual void createTrenchs() = 0;
    virtual void createCannons() = 0;
    virtual void createBoxes() = 0;
    virtual void createSnipers() = 0;
    virtual void createPlayers() = 0;
};
