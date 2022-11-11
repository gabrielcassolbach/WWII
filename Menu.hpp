#include "Enty.hpp"

class Menu: public Enty{
private:

public:
    /*CONSTRUCTORS & DESTRUCTORS*/
    Menu();
    ~Menu();
    void init ();

    /*SETTERS & GETTERS*/

    /*METHODS*/
    void drawThis(Graphic_Manager* pGM);
};