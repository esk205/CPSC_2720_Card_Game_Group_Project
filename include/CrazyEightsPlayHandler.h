#ifndef CRAZYEIGHTSPLAYHANDLER_H
#define CRAZYEIGHTSPLAYHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"
#include "StandardCard.h"
#include "Menu.h"
#include "Deck.h"

class CrazyEightsPlayHandler : public StateHandler
{
    public:
        CrazyEightsPlayHandler(Game* game);
        virtual ~CrazyEightsPlayHandler();

        /**
        * @brief Player chooses between adding another card to their hand
        * or simply playing the card that they have in their hand.
        */
        unsigned int selectingCard(unsigned int i);

        /**
        * @brief Shows all the cards in the current players hand
        */
        void displayCardsInHand();

        /**
        * @brief calculates the score for player with a given index
        * parameter
        */
        int calculateScore(int index);

        /**
        * @brief Displays the scores for all the players
        */
        void displayScores();

        /**
        * @brief If the player has an 8 card they can pick any suit
        * for the next player to match by either suit or by the number 8
        */
        void pickSuit();

        /**
        * @brief checks if the current player has no cards
        * and if there are cards in the deck to draw from
        * skip the players turn
        */
        void checkDeckAndHand(unsigned int i);

        /**
        * @brief checks if the playedCard matches the matchCard.
        * If it does not match, the player will select another card.
        * The cardSelected parameter is the location of the card in the
        * players hand.
        */
        void checkPlayedCard(unsigned int i, unsigned int cardSelected);

        /**
        * @brief displays the player that drew their playedCard
        * and shows how many cards are left in the players hand
        */
        void displayGameStatus();

        /**
        * @brief this is where the game starts
        */
        void handle();

        /**
        * @brief displays what the next card to match
        */
        void nextCardToMatchIs();

        /**
        * @brief draws card from the deck
        */
        void drawCardFromDeck();

        /**
        * @brief sets the matchCard with a given Card parameter
        */
        void setMatchCard(Card);

        /**
        * @brief Goes to the next player with the given index i parameter
        * and returns the new index number
        */
        void nextPlayer(unsigned int i);

        /**
        * @brief checks if the playedCard matches the
        * matchCard in suit or rank
        */
        bool matchesSuitOrRank();

        /**
        * @brief checks if the playedCard matches the
        * matchCard in suit AND rank
        */
        bool matchesSuitAndRank();

        /**
        * @brief sets the matchCard with a given Card parameter
        */
        void badMatch(unsigned int i, unsigned int cardSelected);

        /**
        * @brief returns the matchCard object.
        * This is used for crazy8's random bot player
        */
        Card* getMatchCard();

    protected:
    private:
        Card matchCard;
        Card playedCard;
        Card checkCard;
        Game* game;
        Menu gameMenu;
        string resultMessage;
        void playRound();
};

#endif // CRAZYEIGHTSPLAYHANDLER_H
