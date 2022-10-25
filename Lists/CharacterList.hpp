#include "List.hpp"
#include "../Entities/Characters/Character.hpp"

class CharacterList{
private:
    List<Character*> CharactersList;

public:
/*CONSTRUCTOS & DESTRUCTORS*/
    CharacterList();
    ~CharacterList();

/*SETTERS & GETTERS*/

/*METHODS*/
    void includeCharacter(Character* p);
    void drawAll();
    void updateAll();
    void initAll();
    void destroyAll();
};
