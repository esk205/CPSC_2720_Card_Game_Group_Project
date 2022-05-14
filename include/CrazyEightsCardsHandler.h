#ifndef CRAZYEIGHTSDEALCARDSHANDLER_H
#define CRAZYEIGHTSDEALCARDSHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class CrazyEightsDealCardsHandler : public StateHandler
{
    /**
    * Handle the dealing logic for the Crazy Eights game.
    */
    public:
        /**
        * @brief Constructor
        * @param Game, pointer to the game.
        */
        CrazyEightsDealCardsHandler(Game* game);

        /**
        * @brief Deconstructor
        */
        virtual ~CrazyEightsDealCardsHandler();

        /**
        * @brief Handler method.
        */
        void handle();
    protected:
    private:

        /**
        * @brief Pointer to the game object.
        */
        Game* game;
};

#endif // CRAZYEIGHTSDEALCARDSHANDLER_H
