#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck
{
    /**
    * Deck object, holds the cards.
    */
public:

    /**
    * @brief Default constructor.
    */
    Deck();

    /**
    * @brief Deconstructor.
    */
    virtual ~Deck();

    /**
    * @brief adds a card to the deck
    */
    void addCard(Card card);

    /**
    * @brief removes card from the deck
    * @return object of type card
    */
    Card drawCard();

    /**
    * @brief shuffles the deck.
    */
    void shuffle(int times);

    /**
    * @brief does a "shuffle" that results in the same everytime, very useful for testing war and
    * rock paper scissors
    **/
    void badShuffle(int times);

    /**
    * @brief gives number of cards left in deck
    * @return number of cards left
    */
    int cardsRemaining();

    /**
    * @brief gets a card from an index location.
    */
    Card getCard(int location);

    /**
    * @brief Empty's a standard 52 card deck.
    * This is useful for creating discard piles.
    */
    void emptyStandardDeck();

    Deck* getDeckPtr();
protected:

    /**
    * @brief vector of cards.
    */
    vector<Card> cards;
private:
};

#endif // DECK_H
