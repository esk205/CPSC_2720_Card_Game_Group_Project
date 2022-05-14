#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include <iostream>
#include "AppConstants.h"
#include "StateHandler.h"
#include "Game.h"

class PlayerHandler : public StateHandler
{
public:
    /**
    * @brief Default constructor.
    * @param Game* game pointer.
    */
    PlayerHandler(Game* game);

    /**
    * @brief Deconstructor.
    */
    virtual ~PlayerHandler();

    /**
    * @brief Handler.
    */
    void handle();
protected:
private:
    Game* game;
};

#endif // PLAYERHANDLER_H
