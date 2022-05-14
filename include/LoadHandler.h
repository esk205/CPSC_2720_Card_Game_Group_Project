#ifndef LOADHANDLER_H
#define LOADHANDLER_H

#include "AppConstants.h"
#include <StateHandler.h>
#include <fstream>
#include <Game.h>
#include "Tools.h"
#include "State.h"


class LoadHandler : public StateHandler
{
public:

    /**
    * @brief Default constructor.
    */
    LoadHandler(Game* game, string file);

    /**
    * @brief Deconstructor.
    */
    virtual ~LoadHandler();

    /**
    * @brief Handles the load logic.
    */
    void handle();

    /**
    * @brief Loads a deck, not sure why this is in here at all...
    */
    Deck loadDeck(vector<string> data, int startIndex, int endIndex);
protected:
private:
    Game* game;
    string file;
};

#endif // LOADHANDLER_H
