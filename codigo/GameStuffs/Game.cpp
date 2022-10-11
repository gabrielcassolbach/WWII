#include "Game.h"

/*CONSTRUCTORS & DESTRUCTORS*/
Game::Game(){
    /*
    Game constructor
    - Initialize variables
    - Initialize window
    - Initialize enemies
    - Go to the game loop
    */

    initializeVariables();
    initializeWindow();
    initializeEnemies();
    gameLoop ();
}
Game::~Game(){
    /*
    Game Destructor
    - Delete the window created
    */

    delete (window);
}

/*INITIALIZERS*/
void Game::initializeVariables(){
    /*
    Function that initialize variabels
    - Makes the pointers point to NULL
    - Determines some stuffs from enemies
    */
    this->window=NULL;

    this->mouseHeld=0;
    this->enemySpawnTimer=0.f;
    this->enemySpawnTimerMax=1.f; //When the timer catch up this, an enemy spawns
    this->maxEnemies=10;

    this->health=5;
    this->points=0;
    this->endGame=false;
}
void Game::initializeWindow(){
    /*
    Function who initialize an window
    - Defines the window measurements
    - Render a new window with these properties 
    */

    this->videoMode.height=720;
    this->videoMode.width=1024;

    this->window=new RenderWindow(this->videoMode, "Game 1");

    this->window->setFramerateLimit(144);
}
void Game::initializeEnemies(){
    /*
    Function that initializes enemies
    - Set enemies size
    - Set enemies color
    -Set enemies outline color and thickness
    */

    this->enemy.setSize(Vector2f(50.f, 50.f));
    this->enemy.setFillColor(Color::Black);
}

/*SETTERS & GETTERS*/

/*GAME METHODS*/
void Game::gameLoop(){
    /* 
    Function that makes the game run while the window is open
    - Update the window at every frame
    - Render what is shown at the window every frame
    */

    while (this->window->isOpen() && !endGame){
        update();
        render();
    }
        
}
void Game::update(){
    /*
    Fuction that changes what is shown at the window
    - Makes the necessary changes acordding to the events
    - Updates the mouse position
    - Update the enemies
    */

    this->pollEvents();
    this->updateMousePositionWindow();
    this->updateEnemies();

}
void Game::render(){
    /*
    Function that displays the things at the screen
    - Clear the screen 
    - Render the enemies
    - Display what is suposed.
    */

    this->window->clear(Color(173, 216, 230, 255));

    this->renderEnemies();

    this->window->display();
}
void Game::pollEvents(){
    /*
    Function that make changes according to the events
    */

    while (this->window->pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:{
                this->window->close();
            }break;
            case sf::Event::KeyPressed:{
                if (event.key.code==sf::Keyboard::Escape)
                    this->window->close();
            }
        }
    }
}
void Game::updateMousePositionWindow(){
    /*
    Function that updates the nouse positon - relative to the window
    - Updates the mouse position on int an float.
    */
   this->mousePositionWindow=Mouse::getPosition(*this->window);
   this->mousePositionView=this->window->mapPixelToCoords(this->mousePositionWindow);
}

/*ENEMY METHODS*/
void Game::spawnEnemy(){
    /*
    Function that creates an enemy 
    - Set the enemy start position
    - Set the enemy color
    - Add an enemy to the vector of enemies
    */


    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - enemy.getSize().x)),
        0.f);
    
    this->enemy.setFillColor(Color::Black);

    this->enemies.push_back(this->enemy);
}
void Game::updateEnemies(){
    /*
    Function that updates the enemies
    - Updates the timer every frame
    - Spawn when the spawnTimer gets the spawnTime
    - Moves an enemy
    - Kill the enemy if it is out of the living conditions
    */

    if (this->enemies.size() < this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemy(); //Spawning the enemy when spawnTimer==maxSpawnTimer
            this->enemySpawnTimer=0.f; 
        }
        else
            enemySpawnTimer+=1.f; //Updating the timer
    }

    for (int i=0; i<this->enemies.size(); i++){ //Change the position of the enemy
        this->enemies[i].move(0.f, 1.f);

        /*Check if the enemy is out of the screen*/
        if(this->enemies[i].getPosition().y > this->window->getSize().y){
            this->enemies.erase(this->enemies.begin()+i);
            this->health--;
            cout<<"Health: "<<this->health<<endl;
            if (!this->health)
                endGame=true;
        }
    }

    /*Check if the enemy was clicked upon*/
    if (Mouse::isButtonPressed(Mouse::Left)){
        if (!this->mouseHeld){
            this->mouseHeld=true;  
            for (int i=0; i<this->enemies.size(); i++){
                if (this->enemies[i].getGlobalBounds().contains(this->mousePositionView)){
                    this->enemies.erase(this->enemies.begin()+i);
                    this->points+=1;
                    cout<<"Points:"<<this->points<<endl;
                }
            }
        }
    }
    else
        this->mouseHeld=false;
}
void Game::renderEnemies(){
    /*
    Function that draws an enemy at the screen
    */
    for (auto &e : this->enemies)
        this->window->draw(e);
}





