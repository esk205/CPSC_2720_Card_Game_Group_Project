#ifndef CRAZYEIGHTSDEALCARDSHANDLER_H
#define CRAZYEIGHTSDEALCARDSHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class CrazyEightsDealCardsHandler : public StateHandler
{
    /**
    * Handles the dealing logic for the crazy eights card game.
    */
     public:
         /**
         * @brief Constructor
         * @param Game, pointer to the game object.
         */
        CrazyEightsDealCardsHandler(Game* game);

        /**
        * @param Destructor.
        */
        virtual ~CrazyEightsDealCardsHandler();

        /**
        * @param Handler
        */
        void handle();


    protected:
    private:
        bool isCardsDealt;
        /**
        * @param Pointer to the game object.
        */
        Game* game;
};

#endif // CRAZYEIGHTSDEALCARDSHANDLER_H
