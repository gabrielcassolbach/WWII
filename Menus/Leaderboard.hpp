#include "../Game_State.hpp"
#include "../Enty.hpp"
#include <string.h>
using namespace std;

#define MAX_LEADERBOARD_ITENS 25

class Leaderboard: public Game_State, public Enty{
private:
    Game* pGame;
    sf::Text text[MAX_LEADERBOARD_ITENS];
    sf::Text Title;
    sf::Font font;
    sf::RectangleShape backgroundRectangle;
    sf::Texture backgroundTexture;

    int nUsers;
    int pontuations;

public:
    Leaderboard(Game* pg);
    ~Leaderboard();
    void init (){}

    sf::RectangleShape getRectangleShape() const;
    void setText();
    void setBackground();

    void drawThis(Graphic_Manager *pGM);
    void draw();
    void update(double timeFraction){};
    void input(){};
    void sortLeaderboard();
    void readLeaderboard();
};