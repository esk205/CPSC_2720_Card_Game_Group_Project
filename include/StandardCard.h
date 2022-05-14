#ifndef STANDARDCARD_H
#define STANDARDCARD_H

#include "Card.h"

class StandardCard : public Card
{
/**
* @brief Standard cards
*/
public:
    /**
    * @brief Constructor.
    */
    StandardCard();

    /**
    * @brief Constructor
    * @param suit is the type of card. ex spades
    * @param pip is the value of the card ex. 10, Queen.
    */
    StandardCard(string suit, string pip);

    /**
    * @brief Deconstructor.
    */
    virtual ~StandardCard();
protected:
private:
    void determine_value();

};

#endif // STANDARDCARD_H
