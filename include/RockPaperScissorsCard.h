#ifndef ROCKPAPERSCISSORSCARD_H
#define ROCKPAPERSCISSORSCARD_H

#include "Card.h"
#include "AppConstants.h"
#include "Exceptions.h"

class RockPaperScissorsCard : public Card
{
public:
    /**
    * @brief Default constructor.
    * @param string suit.
    * @param string pip.
    */
    RockPaperScissorsCard(string suit, string pip);

    /**
    * @brief prompts user with a message and choices
    */
    virtual ~RockPaperScissorsCard();
protected:
private:
    void determineValue();
};

#endif // ROCKPAPERSCISSORSCARD_H
