#ifndef GOFISHPLAYHANDLER_H
#define GOFISHPLAYHANDLER_H

#include <algorithm>
#include "AppConstants.h"
#include "GoFishGame.h"
#include "StateHandler.h"
#include "SaveHandler.h"
#include "Choices.h"

class GoFishPlayHandler : public StateHandler
{
    public:
        GoFishPlayHandler(Game* game);
        virtual ~GoFishPlayHandler();
        void handle();
    protected:
    private:
        /**
        * @brief draws the game on the console.
        */
        void drawGame();

        /**
        * @brief shows the players hand.
        */
        void showHand();

        /**
        * @brief shows current player name and shows the players card pile
        */
        void showGameStats();

        /**
        * @brief prompts the player to either ask for a opponents card, pause, or quit
        */
        void promptPlayer();

        /**
        * @brief checks to see if the game win condition has been met.
        */
        bool winCondition();

        /**
        * @brief prompts the user to select an opponent to fish from.
        */
        Player* selectOpponentToFish();

        /**
        * @brief asks an opponent for some cards.
        */
        void askOpponentForCards(Player* opponent);

        /**
        * @brief handles the fishing from an opponent.
        */
        void handleFish(Player* opponent, string pip);

        /**
        * @brief takes cards from an opponent.
        */
        int takeCards(Player* opponent, string pip);

        /**
        * @brief checks the current players hand for a pile.
        */
        void checkForPile(string pip);

        /**
        * @brief passes the turn.
        */
        void passTurn();

        /**
        * @brief moves the game to the next player.
        */
        void nextPlayer();

        /**
        * @brief draws the winner.
        */
        void drawWinner();

        map<string, int> piles;
        Game* game;
        string lastMessage;
        string winner;
};

#endif // GOFISHPLAYHANDLER_H
