#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Hand.h"
#include "Deck.h"
#include "Choices.h"

class Player
{
public:
    /**
    * @brief Defualt constructor.
    */
    Player();

    /**
    * @brief Deconstructor.
    */
    virtual ~Player();

    /**
    * @brief play method used to either prompt the player, or generate bot action.
    * @param string message.
    * @param Choices choice options.
    */
    virtual int play(string message, Choices c);

    /**
    * @brief returns the name of the player.
    */
    string getName();

    /**
    * @brief sets the player name.
    */
    void setName(string playerName);

    /**
    * @brief gets the player score.
    */
    double getScore();

    /**
    * @brief sets the player score.
    */
    void setScore(double value);

    /**
    * @brief Gets the player hand.
    */
    Hand* getHand();

    /**
    * @brief Gets the player discard pile.
    */
    Deck* getDiscard();

protected:
    string name;
    double score;
    Hand hand;
    Deck discard;

private:
};

#endif // PLAYER_H
