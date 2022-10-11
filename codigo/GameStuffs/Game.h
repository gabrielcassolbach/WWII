#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <iostream>
using namespace std;
#include <ctime>

class Game{
private:
/*WINDOW*/
    RenderWindow* window;
    VideoMode videoMode;
    Event event;

/*MOUSE*/
    Vector2i mousePositionWindow;
    Vector2f mousePositionView;
    bool mouseHeld;

/*ENEMY OBJECTS*/
    RectangleShape enemy;
    vector<RectangleShape>enemies;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

/*GAME OBJECTS*/
    bool endGame;
    int points;
    int health;

/*INITIALIZERS*/
    void initializeWindow();
    void initializeVariables();
    void initializeEnemies();

public:
/*CONSTRUCTORS & DESTRUCTORS*/
    Game();
    ~Game();

/*SETTER & GETTERS*/

/*GAME METHODS*/
    void gameLoop();
    void update();
    void render();
    void pollEvents();
    void updateMousePositionWindow();

/*ENEMY METHODS*/
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
};