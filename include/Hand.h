#ifndef HAND_H
#define HAND_H

#include <vector>

#include "Card.h"

class Hand
{
public:
    Hand();
    virtual ~Hand();

    /**
    * @brief empty's the players hand of all cards
    */
    void emptyHand();

    /**
    * @brief adds a card to the players hand
    */
    void addCard(Card c);

    /**
    * @brief removes a card from the players hand with a given card parameter
    */
    void removeCard(Card c);

    /**
    * @brief removes a card from the players hand with a given location parameter
    */
    Card removeCard(int location);

    /**
    * @brief gets a card from the players hand with a given location parameter
    */
    Card getCard(int location);

    /**
    * @brief sorts the players hand of cards by their value
    */
    void sortByValue();

    /**
    * @brief sorts the players hand of cards by their suit
    */
    void sortBySuit();

    /**
    * @return the number of cards remaining in players hand
    */
    int cardsRemaining();

    /**
    * @return returns what cards are in hand
    */
    string to_string();

    /**
    * @return returns what card at location i
    */
    string to_stringOnce(unsigned int i);

    /**
    * @return returns a vector of cards
    */
    vector<Card> getCards();

protected:
    vector<Card> cards;

private:

    /**
    * @brief sorts the players hand by suit first then value
    */
    void sortByValueAfterSuit(int startIndex, int endIndex);
};

#endif // HAND_H
