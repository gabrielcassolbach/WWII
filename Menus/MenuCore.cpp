#include "MenuCore.hpp"

MenuCore::MenuCore(Game* pg){
    pGame=pg;
}
MenuCore::~MenuCore(){
    pGame=nullptr;
}
