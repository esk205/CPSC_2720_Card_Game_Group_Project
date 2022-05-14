#ifndef WARPLAYHANDLER_H
#define WARPLAYHANDLER_H

#include "AppConstants.h"
#include "StateHandler.h"
#include "Choices.h"
#include "Game.h"

class WarPlayHandler : public StateHandler
{
    /**
    * @brief The concrete implementation of War
    */
public:
    /**
    * @brief Constructor. Initializes the game variable
    */
    WarPlayHandler(Game* game);

    /**
    * @brief Deconstructor.
    */
    virtual ~WarPlayHandler();
protected:

    /**
    * @brief Loops a game until game over or quitting, and asks each player to choose an option and compares the cards
    */
    void handle();
private:

    /**
    * @brief Is the game type that is passed
    */
    Game* game;

    /**
    * @brief Menu object used throughout the game
    */
    Menu gameMenu;

    /**
    * @brief The cards that are played by each player which are held in pairs to be compared against
    **/
    vector<vector<Card>> playedCards;

    /**
    * @brief If the game is currently playing and not finished
    */
    bool isPlaying = true;

    /**
    * @brief If the game is told to quit this sets to true so that game loop will end.
    */
    bool isQuitting = false;

    /**
    * @brief Takes in options, and returns the vector of cards of the resulting round.
    **/
    int playRound();

    /**
    * @brief Take in the round index and determine the winner
    **/
    int determineRoundWinner(int roundIndex);
};

#endif // WARPLAYHANDLER_H
