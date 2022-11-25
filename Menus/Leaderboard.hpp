#pragma once
#include "../Game_State.hpp"
#include "../Enty.hpp"
#include <string>
#include <map>
using namespace std;
#define MAX_LEADERBOARD_ITENS 4

class Game;

namespace Menus
{
    typedef multimap<float, string, std::greater<float>> map_;
    typedef pair<float, string> pair_;

    class Leaderboard : public Enty, public Game_State
    {
    private:
        Game *pGame;
        sf::Text text[MAX_LEADERBOARD_ITENS];
        sf::Text text2[MAX_LEADERBOARD_ITENS];
        sf::Text Title;
        sf::Font font;
        sf::RectangleShape backgroundRectangle;
        sf::Texture backgroundTexture;

        map_ map_leaderboard;

        int nUsers;
        int pontuations;

    public:
        Leaderboard(Game *pg);
        ~Leaderboard();
        void init() {}
        void setText();
        void setBackground();
        sf::RectangleShape getRectangleShape() const {}
        void drawThis(Managers::Graphic_Manager *pGM);
        void draw();
        void update(double timeFraction){};
        void input();
        void readLeaderboard();
        void keyPressedAction(sf::Event event);
    };

}