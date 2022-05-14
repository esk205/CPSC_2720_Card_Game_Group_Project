#ifndef BLACKJACKPLAYHANDLER_H
#define BLACKJACKPLAYHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class BlackjackPlayHandler : public StateHandler
{
    /**
    * A state handler for handling the blackjack game logic.
    */
    public:
        /**
        * @brief Constructor for the Black Jack Play Handler object.
        * @param Game pointer.
        */
        BlackjackPlayHandler(Game* game);

        /**
        * @brief Deconstructor
        */
        virtual ~BlackjackPlayHandler();

        /**
        * @brief interface handle method used for all statehandlers.
        */
        void handle();

        /**
        * @brief Counts the player's hand assuming ace is 1
        */
        int countWorstHand(Hand* h);

        /**
        * @brief Counts the player's hand assuming the best case for aces
        */
        int countBestHand(Hand* h);

        /**
        * @brief Print out each card in the player's hand
        */
        void displayHand(Hand* h);

        /**
        * @brief Determine the next player
        */
        void nextPlayer();
    protected:
    private:

        /**
        * @brief Pointer to the game object.
        */
        Game* game;

        /**
        * @brief Tracks the current player index.
        */
        int currentPlayerIndex;

        /**
        * @brief The dealers hand object.
        */
        Hand dealerHand;

        /**
        * @brief Dealer hand count.
        */
        int dealerHandCount;
};

#endif // BLACKJACKPLAYHANDLER_H
