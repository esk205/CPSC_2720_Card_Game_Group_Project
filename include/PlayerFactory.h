#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "Player.h"
#include "Game.h"

class PlayerFactory
{
public:
    /**
    * @brief returns a pointer to player object.
    * @param int choice.
    * @param game* game for player.
    */
    static Player *makePlayer(int choice, Game* game);
protected:
private:
};

#endif // PLAYERFACTORY_H
