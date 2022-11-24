#include "SecondLevel.hpp"
#include "../Game.hpp"
#include "../Menus/Menu.hpp"
#include "../Entities/Characters/Boss.hpp"

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
    saver<<700.0<<' '<<200.0<<endl;
*/

SecondLevel::SecondLevel(Game* pg, int np, double p1, double p2) : CM(),
Levels(pg, np)
{
    entitiesQuantity= new int[8];
    entitiesQuantity[0]=np;
    entitiesQuantity[1]=randomQuantity();
    entitiesQuantity[2]=randomQuantity();
    entitiesQuantity[5]=randomQuantity();
    entitiesQuantity[6]=randomQuantity();
    entitiesQuantity[7]=randomQuantity();
 
    createPlayers(p1, p2);
    createEnemies();
    createPlatforms();
    createTrenchs();
    createCannons();
    createBoxes();
    //createSnipers();
    createBoss();

    StaticEntityList.initAll();
    MovingEntityList.initAll();

    CM.init(&MovingEntityList, &StaticEntityList);

    setBackground();
}
SecondLevel::SecondLevel(Game* pg, int np, double p1) : CM(),
Levels(pg, np)
{
    entitiesQuantity= new int[8];
    entitiesQuantity[0]=np;
    entitiesQuantity[1]=randomQuantity();
    entitiesQuantity[2]=randomQuantity();
    entitiesQuantity[5]=randomQuantity();
    entitiesQuantity[6]=randomQuantity();
    entitiesQuantity[7]=randomQuantity();
 
    createPlayers(p1);
    createEnemies();
    createPlatforms();
    createTrenchs();
    createCannons();
    createBoxes();
    //createSnipers();
    createBoss();

    StaticEntityList.initAll();
    MovingEntityList.initAll();

    CM.init(&MovingEntityList, &StaticEntityList);

    setBackground();
}
SecondLevel::SecondLevel(Game* pg, int np, int size):CM(),
Levels(pg, np)
{
    double px, py, vx, vy, nPoints1, level, s, nPoints2;
    int hp, id, i=0;
    ifstream recover ("Data/gameSave.dat", ios::in);
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }
     
    recover>>level;
    recover>>nPlayers;
    recover>>s;

    while (i<size){
        recover>>id;
        switch (id)
        {
        case 0:
        {
            //cout<<"0"<<endl;
            //system("pause");
            recoverPlayer(&recover);
            i++;
        }break;
        case 1:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy>>hp;
            double p;
            recover>>p;
            if (p==1)
                MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, px, py, 35.0, 60.0, vx, vy, hp, pPlayersList[0], 1)));
            else
                MovingEntityList.includeEntity(static_cast<Entity *>(new Samurai(1, px, py, 35.0, 60.0, vx, vy, hp, pPlayersList[1], 1)));
        }break;
        case 2:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy;
            StaticEntityList.includeEntity(static_cast<Entity *>(new Box(2, px, py, 30.0, 50.0)));

        }break;
        case 3:
        {
            //cout<<"1"<<endl;
            //system("pause");
            double sx, sy;
            recover>>px>>py>>vx>>vy;
            recover>>sx>>sy;
            StaticEntityList.includeEntity(static_cast<Entity *>(new Platform(3, px, py, sx, sy)));
        }break;
        case 4:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy>>hp;
        }break;
        case 5:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy>>hp;
            double p;
            recover>>p;
            Sniper* pSniper=nullptr;
            if (p==1)
                pSniper=new Sniper(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[0]);
            else
                pSniper=new Sniper(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[1]);
            pSniperList.push_back(pSniper);
            MovingEntityList.includeEntity(static_cast<Entity*>(pSniper));
            recover>>id;
            recover>>px>>py>>vx>>vy>>hp;
            pSniper->getBullet()->setPosition_x(px);
            pSniper->getBullet()->setPosition_y(py);
            pSniper->getBullet()->setVelocity_x(vx);
            pSniper->getBullet()->setVelocity_y(py);
            MovingEntityList.includeEntity(static_cast<Entity *>(pSniper-> getBullet()));
            i++;
        }break;
        case 6:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy;
            StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, px, py, 40.0, 11.0)));
        }break;
        case 7:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy;
            StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, px, py, 40.0, 11.0)));
        }break;
        case 8:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy;
        }break;
        case 9:
        {
            //cout<<"1"<<endl;
            //system("pause");
            recover>>px>>py>>vx>>vy>>hp;
            double p;
            recover>>p;
            Boss* pBoss=nullptr;
            if (p==1)
                pBoss=new Boss(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[0]);
            else
                pBoss=new Boss(5, px, py, 35.00, 60.00, 0.0, 0.0, 3, pPlayersList[1]);
            MovingEntityList.includeEntity(static_cast<Entity*>(pBoss));
            recover>>id;
            recover>>px>>py>>vx>>vy>>hp;
            pBoss->getBullet()->setPosition_x(px);
            pBoss->getBullet()->setPosition_y(py);
            pBoss->getBullet()->setVelocity_x(vx);
            pBoss->getBullet()->setVelocity_y(py);
            MovingEntityList.includeEntity(static_cast<Entity *>(pBoss-> getBullet()));
            i++;
        }
        
        default:
            break;
        }
        i++;
    }
    
    recover>>nPoints1;
    this->getPlayer(1)->setPoints(nPoints1);
    if (nPlayers==2){
        recover>>nPoints1;
        this->getPlayer(2)->setPoints(nPoints1);
    }

    StaticEntityList.initAll();
    MovingEntityList.initAll();
    
    CM.init(&MovingEntityList, &StaticEntityList);
    setBackground();
}
SecondLevel::~SecondLevel()
{
    MovingEntityList.destroyAll();
    StaticEntityList.destroyAll();
    delete (entitiesQuantity);
}

/*SETTERS & GETTERS*/
int* SecondLevel::getEntitiesQuantity(){
    return entitiesQuantity;
}

/*METHODS*/
void SecondLevel::input()
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
void SecondLevel::keyPressedAction(sf::Event event)
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
    }break;
    if (nPlayers==2){
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
        }break;
    }
    }

}
void SecondLevel::update(double timeFraction)
{
    for (int i=0; i<pPlayersList.size(); i++)
        pPlayersList[i]->operator-(0.01);
    
    MovingEntityList.updateAll(timeFraction);//ERRO AQUI
    StaticEntityList.updateAll(timeFraction);
    CM.collision();
    CheckPlayerState();
    CheckLevelEnd();
}
void SecondLevel::CheckPlayerState()
{
    if (nPlayers==2){
        if(getPlayer(1) -> getPlayerState() && getPlayer(2)->getPlayerState()) // adicionar verificação para o player 2.
            endCurrentState(); 
    }
    else{
        if (getPlayer(1) -> getPlayerState())    
            endCurrentState();
    }
}
void SecondLevel::endCurrentState()
{   
    if(pGame)
        pGame -> popState();
}
void SecondLevel::createEnemies()
{
    ifstream recover ( "Data/lvl2-samurais.dat", ios::in);
    
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    int quantity=entitiesQuantity[1];
    
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
void SecondLevel::createPlatforms()
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
void SecondLevel::createTrenchs()
{
    ifstream recover ( "Data/lvl2-trenchs.dat", ios::in );
    
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
        StaticEntityList.includeEntity(static_cast<Entity *>(new Trench(6, px, py, 40.0, 7.0)));
        quantity--;
    }
}
void SecondLevel::createCannons()
{
    ifstream recover ( "Data/lvl2-cannons.dat", ios::in );
    
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
        StaticEntityList.includeEntity(static_cast<Entity *>(new Cannon(7, px, py, 40.0, 7.0)));
        quantity--;
    }
}
void SecondLevel::createBoxes()
{
    ifstream recover ("Data/lvl2-boxes.dat", ios::in );
    
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


/*void SecondLevel::createSnipers()
{
    ifstream recover ( "Data/lvl2-snipers.dat", ios::in );
    
    if ( !recover ){
        cerr << " Arquivo não pode ser aberto " << endl;
        fflush ( stdin );
        getchar( );
        return;
    }

    double px, py;
    int quantity=entitiesQuantity[5];
    for (int i=1; i>=0; i--){
        recover>>px>>py;
        if (nPlayers==2){
            if (px<640)
                pSniperList.push_back(new Sniper(5, px, py, 45.00, 20.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));
            else
                pSniperList.push_back(new Sniper(5, px, py, 45.00, 20.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[1]));
        }
        else
            pSniperList.push_back(new Sniper(5, px, py, 45.00, 20.00, 0.0, 0.0, 3, 4, 0.0, pPlayersList[0]));
    }

    for(int i = 0; i < pSniperList.size(); i++)
    {
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i])); 
        MovingEntityList.includeEntity(static_cast<Entity *>(pSniperList[i]->getBullet())); 
    }
}*/

void SecondLevel::createPlayers(double p1){
    Player* pPlayer1=new Player(0, 20.0, 40.0, 35.00, 60.0, 0.0, 0.0, 10);
    MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
    MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
    pPlayersList.push_back(pPlayer1);
    pPlayer1->setPoints(p1);
}
void SecondLevel::createPlayers(double p1, double p2)
{
    Player* pPlayer1=new Player(0, 20.0, 40.0, 35.00, 60.0, 0.0, 0.0, 10);
    MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
    MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
    pPlayersList.push_back(pPlayer1);
    pPlayer1->setPoints(p1);

    Player* pPlayer2=new Player(0, 1240.0, 600.00, 35.00, 60.0, 0.0, 0.0, 10);
    MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer2));
    MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer2-> getBullet()));
    pPlayersList.push_back(pPlayer2);
    pPlayer2->setPoints(p2);
}
void SecondLevel::createBoss()
{
    Boss* pBoss1 = new Boss (9, 170.0, 590, 35.0, 60.0, 0.0, 0.0, 20.0, pPlayersList[0]);
    Boss* pBoss2 = new Boss (9, 700.0, 590, 35.0, 60.0, 0.0, 0.0, 20.0, pPlayersList[0]);
    Boss* pBoss3 = new Boss (9, 1000.0, 590, 35.0, 60.0, 0.0, 0.0, 20.0, pPlayersList[nPlayers-1]);

    pBossList.push_back(pBoss1);
    pBossList.push_back(pBoss2);
    pBossList.push_back(pBoss3);

    for(int i = 0; i < pBossList.size(); i++)
    {
        MovingEntityList.includeEntity(static_cast<Entity *>(pBossList[i])); 
        MovingEntityList.includeEntity(static_cast<Entity *>(pBossList[i]->getBullet())); 
    }
}
void SecondLevel::setBackground()
{
    backgroundTexture.loadFromFile("Images/backgroundlevel2.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setOrigin(0, 0);  
}
void SecondLevel::draw()
{
    pGM->getWindow()->draw(backgroundSprite);
    MovingEntityList.drawAll();
    StaticEntityList.drawAll();
}
void SecondLevel::CheckLevelEnd()
{
    if (nPlayers==2){
        double px1 = getPlayer(1) -> getPosition_x() + getPlayer(1) -> getSize_x();
        double py1 = getPlayer(1) -> getPosition_y() + getPlayer(1) -> getSize_y();

        double px2 = getPlayer(2) -> getPosition_x() + getPlayer(2) -> getSize_x();
        double py2 = getPlayer(2) -> getPosition_y() + getPlayer(2) -> getSize_y();

        if((px1 > 1270 && py1 < 145) || (px2>1270 && py2<145))
            pGame->pushState(new GameOverMenu(pGame, pPlayersList[0]->getPoints()));
    }
    else if (nPlayers==1){
        double px1 = getPlayer(1) -> getPosition_x() + getPlayer(1) -> getSize_x();
        double py1 = getPlayer(1) -> getPosition_y() + getPlayer(1) -> getSize_y();

        if(px1 > 1270 && py1 < 145)
            pGame->pushState(new GameOverMenu(pGame, pPlayersList[0]->getPoints()));
    }
}
void SecondLevel::recoverPlayer(ifstream* recover){
    double px, py, vx, vy;
    int id, hp;
    (*recover)>>px>>py>>vx>>vy>>hp;
    Player* pPlayer1=new Player(0, px, py, 35.00, 60.0, vx, vy, hp);
    MovingEntityList.includeEntity(static_cast<Entity*>(pPlayer1));
    (*recover)>>id;
    (*recover)>>px>>py>>vx>>vy>>hp;
    pPlayer1->getBullet()->setPosition_x(px);
    pPlayer1->getBullet()->setPosition_y(py);
    pPlayer1->getBullet()->setVelocity_x(vx);
    pPlayer1->getBullet()->setVelocity_y(py);
    MovingEntityList.includeEntity(static_cast<Entity *>(pPlayer1-> getBullet()));
    pPlayersList.push_back(pPlayer1);



}



