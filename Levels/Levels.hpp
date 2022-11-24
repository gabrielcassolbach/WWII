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
#include "../Game_State.hpp"
#include <iostream>
using namespace std;

class Character;

class Game;

namespace Level
{
    class Levels : public Enty, public Game_State
    {
    protected:
        Game *pGame;
        EntityList MovingEntityList;
        EntityList StaticEntityList;
        std::vector<Sniper *> pSniperList;
        std::vector<Player *> pPlayersList;

        int nPlayers;

        /*Showing informations on screen*/
        sf::Text showPoints1;
        sf::Text showPoints2;
        sf::Font font;

    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        Levels(Game *pg = nullptr, int np = 1);
        ~Levels();

        /*SETTERS & GETTERS*/
        Player *getPlayer(int player_selected);
        EntityList *getMovingEntityList();
        EntityList *getStaticEntityList();
        int getNPlayers();

        /*METHODS*/
        void initPointsText();
        virtual void createEnemies() = 0;
        virtual void createPlatforms() = 0;
        virtual void createTrenchs() = 0;
        virtual void createCannons() = 0;

        int randomQuantity();
    };
}

using namespace Level;