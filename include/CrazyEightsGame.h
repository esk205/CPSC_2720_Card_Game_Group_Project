#ifndef CRAZYEIGHTSGAME_H
#define CRAZYEIGHTSGAME_H

#include "Game.h"
#include "State.h"
#include "StandardCard.h"
#include "AppConstants.h"
#include "GameStartHandler.h"
#include "CrazyEightsDealCardsHandler.h"
#include "CrazyEightsPlayHandler.h"

class CrazyEightsGame : public Game
{
    public:
        CrazyEightsGame();
        virtual ~CrazyEightsGame();

        /**
         * @brief This method updates the game state
         * which can be start, deal cards, play and end
         */
        void update();
    protected:
    private:

        /* Private Variables */

        string resultMessage;
};

#endif // CRAZYEIGHTSGAME_H
