#ifndef ROCKPAPERSCISSORSDEALCARDSHANDLER_H
#define ROCKPAPERSCISSORSDEALCARDSHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Game.h"

// TODO REMOVE WHEN DECK IS FIXED
#include "RockPaperScissorsCard.h"

class RockPaperScissorsDealCardsHandler : public StateHandler
{
    public:
        /**
        * @brief Default constructor.
        * @param Game* game pointer.
        */
        RockPaperScissorsDealCardsHandler(Game* game);

        /**
        * @brief pDeconstructor.
        */
        virtual ~RockPaperScissorsDealCardsHandler();

        /**
        * @brief Populates the deck, shuffles, then deals 3 cards to each player.
        **/
        void handle();
    protected:
    private:
        Game* game;
};

#endif // ROCKPAPERSCISSORSDEALCARDSHANDLER_H
