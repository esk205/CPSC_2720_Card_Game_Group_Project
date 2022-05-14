#ifndef BLACKJACKCARD_H
#define BLACKJACKCARD_H

#include "Card.h"
#include "AppConstants.h"
#include "Exceptions.h"

class BlackjackCard : public Card
{
    /**
    * Card used specifically for black jack.
    */
    public:
        /**
        * @brief Constructor
        * @param suit a string suit see: AppConstants.h
        * @param pip a string pip see: AppConstants.h
        */
        BlackjackCard(string suit, string pip);

        /**
        * @brief Deconstructor
        */
        virtual ~BlackjackCard();
    protected:
    private:

        /**
        * @brief Function to determine the value of the blackjack card.
        */
        void determineValue();
};

#endif // BLACKJACKCARD_H
