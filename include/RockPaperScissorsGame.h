#ifndef ROCKPAPERSCISSORSGAME_H
#define ROCKPAPERSCISSORSGAME_H

#include "AppConstants.h"
#include "Game.h"
#include "Deck.h"
#include "RockPaperScissorsCard.h"
#include "GameStartHandler.h"
#include "RockPaperScissorsDealCardsHandler.h"
#include "RockPaperScissorsPlayHandler.h"
#include "EndGameHandler.h"

class RockPaperScissorsGame : public Game
{
public:
    /**
    * @brief Default constructor.
    */
    RockPaperScissorsGame();

    /**
    * @brief Deconstructor.
    */
    virtual ~RockPaperScissorsGame();
protected:
    void update();
private:
};

#endif // ROCKPAPERSCISSORS_H
