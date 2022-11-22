#include "FirstLevel.hpp"
#include "../Game.hpp"
#include "../Menus/Menu.hpp"

/*EXEMPLO GERAÇÃO AUTOMÁTICA
ofstream saver ( "lvl1-trenchs.dat", ios::out );

    
    if ( !saver ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    saver<<920.0<<' '<<620.0<<endl;
    saver<<1000.0<<' '<<620.0<<endl;
    saver<<800.0<<' '<<200.0<<endl;
    saver<<1100.0<<' '<<200.0<<endl;
    saver<<200.0<<' '<<200.0<<endl;
    saver<<350.0<<' '<<200.0<<endl;
    saver<<380.0<<' '<<630.0<<endl;
    saver<<500.0<<' '<<600.0<<endl;
    saver<<650.0<<' '<<200.0<<endl;
    saver<<700.0<<' '<<200.0<<endl;*/

FirstLevel::FirstLevel(Game* pg, int diff, int np) : CM(),
Levels(pg, np)
{
    difficulty=diff;

    entitiesQuantity=new int[7];
    entitiesQuantity[0]=np;
    entitiesQuantity[1]=randomQuantity();
    entitiesQuantity[2]=randomQuantity();
    entitiesQuantity[5]=randomQuantity();
    entitiesQuantity[6]=randomQuantity();
    entitiesQuantity[7]=randomQuantity();

    createPlayers();
    createEnemies();
    createPlatforms();
    createTrenchs();
    createCannons();
    createBoxes();
    createSnipers();

    StaticEntityList.initAll();
    MovingEntityList.initAll();
    
    CM.init(&MovingEntityList, &StaticEntityList);
    setBackground();
}

FirstLevel::FirstLevel(Game* pg, int diff, int np, int recover):CM(),
Levels(pg, np)
{
    ifstream recover ("data/GameSave.dat", ios::in);
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }
    
    cout<<"Oi"<<endl;
}

FirstLevel::~FirstLevel()
{
    MovingEntityList.destroyAll();
    StaticEntityList.destroyAll();
    delete (entitiesQuantity);
}

/*SETTERS & GETTERS*/
int* FirstLevel::getEntitiesQuantity(){
    return entitiesQuantity;
}
int FirstLevel::getDifficulty(){
    return difficulty;
}
void FirstLevel::setBackground()
{
    backgroundTexture.loadFromFile("Images/backgroundlevel1.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);  
}

/*METHODS*/
void FirstLevel::input()
{
    sf::Event event;
    while ((pGM->getWindow())->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            (pGM->getWindow())->close();
        }
        break;

        case sf::Event::KeyPressed:
        {
            keyPressedAction(event);
        }
        break;

        default:
        {
        }
        break;
        }
    }
}

void FirstLevel::keyPressedAction(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Right:
    {
        if (getPlayer(1)->getLeftDirection())
            getPlayer(1)->setLeftDirection(false);
    }
    break;
    case sf::Keyboard::Left:
    {
        getPlayer(1)->setLeftDirection(true);
    }
    break;
    case sf::Keyboard::Up:
    {
        getPlayer(1)->jump(0.01666);
    }
    break;
    case sf::Keyboard::Space:
    {
        getPlayer(1)->attack();
    }
    break;

    case sf::Keyboard::Escape:
    {
        pGame -> pushState(new PauseMenu(pGame, this));
    }
    break;
    
    if (nPlayers==2)
        case sf::Keyboard::D:
        {
            if (getPlayer(2)->getLeftDirection())
                getPlayer(2)->setLeftDirection(false);
        }
        break;
        case sf::Keyboard::A:
        {
            getPlayer(2)->setLeftDirection(true);
        }
        break;
        case sf::Keyboard::W:
        {
            getPlayer(2)->jump(0.01666);
        }
        break;
        case sf::Keyboard::R:
        {
            getPlayer(2)->attack();
        }
        break;
    }
}

void FirstLevel::update(double timeFraction)
{
    for (int i=0; i<pPlayersList.size(); i++)
        pPlayersList[i]->operator-(0.01);
    MovingEntityList.updateAll(timeFraction);
    StaticEntityList.updateAll(timeFraction);
    CM.collision();
    CheckPlayerState();
    CheckLevelEnd();
}
void FirstLevel::CheckPlayerState()
{
    if (nPlayers==1){
        if (pPlayersList[0]->getPlayerState())
            endCurrentState();
    }

    else{
        if (pPlayersList[0]->getPlayerState() && pPlayersList[1]->getPlayerState())
            endCurrentState();
    } 
}
void FirstLevel::CheckLevelEnd()
{
    if (nPlayers==2){
        double px1, py1, px2, py2; 
        px1 = getPlayer(1) -> getPosition_x() + getPlayer(1) -> getSize_x();
        py1 = getPlayer(1) -> getPosition_y() + getPlayer(1) -> getSize_y();

        px2 = getPlayer(2) -> getPosition_x() + getPlayer(2) -> getSize_x();
        py2 = getPlayer(2) -> getPosition_y() + getPlayer(2) -> getSize_y();

        if((px1 > 1270 && py1 < 145) || (px2 > 1270 && py2 < 145))
            goToLevel2();
    }
    else{
        double px1, py1; 
        px1 = getPlayer(1) -> getPosition_x() + getPlayer(1) -> getSize_x();
        py1 = getPlayer(1) -> getPosition_y() + getPlayer(1) -> getSize_y();

        if (px1>1270 && py1<145)
            goToLevel2();
    }
}

void FirstLevel::goToLevel2()
{
    if(pGame && nPlayers==1){
        pGame -> popState();
        pGame -> pushState(new SecondLevel(pGame, 1));
    }
    else if(pGame && nPlayers==2){
        pGame -> popState();
        pGame -> pushState(new SecondLevel(pGame, 2));
    }
}

void FirstLevel::endCurrentState()
{   
    if(pGame)
        pGame -> popState();
}

void FirstLevel::createEnemies()
{
    ifstream recover ( "Data/lvl1-samurais.dat", ios::in);
    
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    int quantity=entitiesQuantity[6];
    
    double px, py;
    while (quantity>0){
        recover>>px>>py;
        if (nPlayers==2){
            if (px<640)
                MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, px, py, 35.0, 60.0, 0.0, 0.0, 6, pPlayersList[0], 1)));
            else
                MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, px, py, 35.0, 60.0, 0.0, 0.0, 6, pPlayersList[1], 1)));
        }
        else
            MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, px, py, 35.0, 60.0, 0.0, 0.0, 6, pPlayersList[0], 1)));
        quantity--;
    }
}

void FirstLevel::createPlatforms()
{
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 640.0, 1280.0, 80.0)));  // Floor
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 0.0, 1280.0, 5.0)));     // Ceil
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 0.0, 5.0, 5.0, 635.0)));      // LeftWall
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 1275.0, 5.0, 5.0, 635.0)));   // RightWall

    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 200.0, 540.0, 300.0, 30.0))); // Plataforma 1
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 400.0, 440.0, 200.0, 30.0))); // Plataforma 2
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 600.0, 340.0, 200.0, 30.0))); // Plataforma 3
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 800.0, 240.0, 200.0, 30.0))); // Plataforma 4
    StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, 1100.0, 140.0, 200.0, 30.0))); // Plataforma 4
}

void FirstLevel::createTrenchs()
{
    ifstream recover ( "Data/lvl1-trenchs.dat", ios::in );
    
    if ( !recover )
    {
        cerr << " Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar( );
    }

    int quantity=entitiesQuantity[6];
    
    double px, py;
    while (quantity>0){
        recover>>px>>py;
        StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, px, py, 40.0, 11.0)));
        quantity--;
    }

}

void FirstLevel::createCannons()
{
    ifstream recover ( "Data/lvl1-cannons.dat", ios::in );
    
    if ( !recover )
    {
        cerr << " Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar( );
    }

    int quantity=entitiesQuantity[2];
    
    double px, py;
    while (quantity>0){
        recover>>px>>py;
        StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, px, py, 40.0, 11.0)));
        quantity--;
    }
}

void FirstLevel::createBoxes()
{
    ifstream recover ( "Data/lvl1-boxes.dat", ios::in );
    
    if ( !recover )
    {
        cerr << " Arquivo não pode ser aberto" << endl;
        fflush ( stdin );
        getchar( );
    }

    int quantity=entitiesQuantity[2];
    
    double px, py;
    while (quantity>0){
        recover>>px>>py;
        StaticEntityList.includeEntity(static_cast<Entity *>(new Box(2, px, py, 30.0, 50.0)));
        quantity--;
    }
}

void FirstLevel::createSnipers()
{
    ifstream recover ( "Data/lvl1-snipers.dat", ios::in );
    
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    double px, py;
    int quatity=entitiesQuantity[5];
    for (int i=quatity; i>=0; i--){
        recover>>px>>py;
        if (nPlayers==2){
            if (px<640)
                pSniperList.push_back(new Sniper(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[0]));
            else
                pSniperList.push_back(new Sniper(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[1]));
        }
        else
            pSniperList.push_back(new Sniper(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[0]));
    }

    for(int i = 0; i < pSniperList.size(); i++)
    {
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i])); 
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i]->getBullet())); 
    }
}
 
void FirstLevel::createPlayers()
{
    if (nPlayers==1){
        if (difficulty==1){
            Player* pPlayer1=new Player(0, 15.0, 500.0, 35.00, 60.0, 0.0, 0.0, 10);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
            pPlayersList.push_back(pPlayer1);
        }
        else{
            Player* pPlayer1=new Player(0, 15.0, 500.0, 35.00, 60.0, 0.0, 0.0, 5);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
            pPlayersList.push_back(pPlayer1);
        }

    }

    else{
        if (difficulty==1){
            Player* pPlayer1=new Player(0, 15.0, 500.0, 35.00, 60.0, 0.0, 0.0, 10);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
            pPlayersList.push_back(pPlayer1);
        
            Player* pPlayer2=new Player(0, 1220.0, 500.0, 35.00, 60.0, 0.0, 0.0, 10);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer2));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer2-> getBullet()));
            pPlayersList.push_back(pPlayer2);
        }
        else{
            Player* pPlayer1=new Player(0, 15.0, 500.0, 35.00, 60.0, 0.0, 0.0, 5);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
            pPlayersList.push_back(pPlayer1);

            Player* pPlayer2=new Player(0, 1220.0, 500.0, 35.00, 60.0, 0.0, 0.0, 10);
            MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer2));
            MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer2-> getBullet()));
            pPlayersList.push_back(pPlayer2);
        }
    }
}

void FirstLevel::draw()
{
    pGM->getWindow()->draw(backgroundSprite);
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}

