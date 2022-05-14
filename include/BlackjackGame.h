#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Game.h"
#include "AppConstants.h"
#include "Deck.h"
#include "BlackjackCard.h"
#include "Exceptions.h"
#include "GameStartHandler.h"
#include "BlackjackDealHandler.h"
#include "BlackjackPlayHandler.h"
#include "EndGameHandler.h"

class BlackjackGame : public Game
{
    /**
    * This is the concrete implemenation of the BlackJackGame.
    */
public:
    /**
    * Default constructor.
    */
    BlackjackGame();

    /**
    * Deconstructor
    */
    virtual ~BlackjackGame();

    /**
    * @brief Override Game's update
    */
    void update();
protected:
private:
};

#endif // BLACKJACKGAME_H
