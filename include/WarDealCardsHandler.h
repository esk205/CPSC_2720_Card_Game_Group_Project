#ifndef WARDEALCARDSHANDLER_H
#define WARDEALCARDSHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Game.h"

class WarDealCardsHandler : public StateHandler
{
    /**
    * @brief Deals the cards to the players
    **/
public:

    /**
    * @brief Constructor. Sets the game variable.
    * @param game. The game type that is passed in.
    */
    WarDealCardsHandler(Game* game);

    /**
    * @brief Deconstructor.
    */
    virtual ~WarDealCardsHandler();

    /**
    * @brief Initializes the deck then shuffles. Then deals the entire deck to the players.
    **/
    void handle();
protected:
private:

    /**
    * @brief Game type that is passed in
    */
    Game* game;
};

#endif // WARDEALCARDSHANDLER_H
