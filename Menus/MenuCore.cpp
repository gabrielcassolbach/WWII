#include "MenuCore.hpp"

namespace Menus
{

    MenuCore::MenuCore(Game *pg)
    {
        pGame = pg;
    }
    MenuCore::~MenuCore()
    {
        pGame = nullptr;
    }

}