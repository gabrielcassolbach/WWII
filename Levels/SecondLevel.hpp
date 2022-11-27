#pragma once
#include "Level.hpp"
#include "../Menus/GameOverMenu.hpp"

namespace Entities
{
    namespace Characters
    {
        class Boss;
    }
}

namespace Levels
{
    class SecondLevel : public Level
    {
    private:
        std::vector<Entities::Characters::Boss *> pBossList;
        Managers::Collision_Manager CM; // criar um singleton. -> não faz sentido nenhum. (PENSAR!)
        int *entitiesQuantity;

        sf::Sprite backgroundSprite;
        sf::Texture backgroundTexture;

    public:
        /*CONSTRUCTORS & DESTRUCTORS*/
        SecondLevel(Game *pg, int np, double p1, double p2);
        SecondLevel(Game *pg, int np, double p1);
        SecondLevel(Game *pg, int np, int size);
        ~SecondLevel();

        /*SETTERS & GETTERS*/
        int *getEntitiesQuantity();

        /*METHODS*/
        void update(double timeFraction);
        void input();
        void draw();
        void keyPressedAction(sf::Event event);
        void CheckPlayerState();
        void endCurrentState();
        /*------------------------------------------------*/
        void init() {}                                   // pensar!!
        void drawThis(Managers::Graphic_Manager *pGM) {} // pensar!!
        /*------------------------------------------------*/
        void createBoss();
        void createEnemies();
        void createPlatforms();
        void createTrenchs();
        void createCannons();
        void createBoxes();
        void createSnipers();
        void createPlayers(double p1, double p2);
        void createPlayers(double p1);
        void setBackground();
        void recoverPlayer(ifstream *recover, int color);

        /*SETTERS & GETTERS*/
        sf::RectangleShape getRectangleShape() const {} // pensar sobre essa função
        void CheckLevelEnd();
    };
}