#ifndef GAMESTARTHANDLER_H
#define GAMESTARTHANDLER_H

#include "AppConstants.h"
#include "LoadHandler.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class GameStartHandler : public StateHandler
{
public:
    GameStartHandler(Game* game, int maxPlayers, string file);
    virtual ~GameStartHandler();
    /**
    * @brief Initializes the game which calls
    * methods in other classes to set the opponents, player name, etc.
    */
    void handle();
protected:
private:
    Game* game;
    int maxPlayers;
    string file;
};

#endif // GAMESTARTHANDLER_H
