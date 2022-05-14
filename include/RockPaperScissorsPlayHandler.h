#ifndef ROCKPAPERSCISSORSPLAYHANDLER_H
#define ROCKPAPERSCISSORSPLAYHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class RockPaperScissorsPlayHandler : public StateHandler
{
public:
    /**
    * @brief Default constructor.
    * @param Game* game pointer.
    */
    RockPaperScissorsPlayHandler(Game* game);

    /**
    * @brief Default deconstructor.
    */
    virtual ~RockPaperScissorsPlayHandler();

    void handle();
protected:
private:
    Game* game;
    Menu gameMenu;
    vector<vector<Card>> playedCards;

    // Private Methods
    int playRound();
    Card selectCard();
    int determineRoundWinner(int roundIndex);
    bool isPlaying = true;
    bool isQuitting = false;
};

#endif // ROCKPAPERSCISSORSPLAYHANDLER_H
