#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "Game.h"

class GameFactory
{
public:
    /**
    * @brief Generate a pointer to a new game base on integer choice.
    * @param int choice.
    */
    static Game *makeGame(int choice);
protected:
private:
};

#endif // GAMEFACTORY_H
