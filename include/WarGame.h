#ifndef WARGAME_H
#define WARGAME_H

#include "AppConstants.h"
#include "Game.h"
#include "Deck.h"
#include "StandardCard.h"
#include "GameStartHandler.h"
#include "WarDealCardsHandler.h"
#include "WarPlayHandler.h"
#include "EndGameHandler.h"

class WarGame : public Game
{
public:
    /**
    * @brief Constructor. Clears the screen, welcomes the person to the game and
    *   sets the state to start and the gametype to War
    */
    WarGame();

    /**
    * @brief Deconstructor
    */
    virtual ~WarGame();
protected:

    /**
    * @brief Updates based on the state and chooses which handler should be used
    */
    void update();
private:
};

#endif // WARGAME_H
