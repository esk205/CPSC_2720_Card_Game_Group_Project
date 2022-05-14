#ifndef BLACKJACKDEALHANDLER_H
#define BLACKJACKDEALHANDLER_H

#include "Exceptions.h"
#include "Deck.h"
#include "AppConstants.h"
#include "BlackjackCard.h"
#include "Game.h"
#include "StateHandler.h"

class BlackjackDealHandler : public StateHandler
{
    /**
    * Handles the deal logic for the blackjack game.
    */
    public:
        /**
        * @brief Constructor for the blackjack deal handler.
        * @param Game is a pointer to a game object.
        */
        BlackjackDealHandler(Game* game);

        /**
        * @brief Deconstructor
        */
        virtual ~BlackjackDealHandler();

        /**
        * @brief interface handle method used for all statehandlers.
        */
        void handle();
    protected:
    private:
        /**
        * @brief Returns a deck with n sets of 52 cards
        */
        Deck createDeck(int sets);

        /**
        * @brief Deals two cards to each player including the dealer
        */
        void dealCards();

        /**
        * @brief Storage for the game pointer.
        */
        Game* game;
};

#endif // BLACKJACKGAMEHANDLER_H
