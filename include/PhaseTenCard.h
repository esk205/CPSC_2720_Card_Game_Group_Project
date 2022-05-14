#ifndef PHASETENCARDS_H
#define PHASETENCARDS_H

#include "Card.h"

class PhaseTenCard : public Card
{
public:
    /**
    * @brief Default constructor.
    * @param string suit.
    * @param string pip.
    */
    PhaseTenCard(string suit, string pip);

    /**
    * @brief Deconstructor.
    */
    virtual ~PhaseTenCard();
protected:
private:

    /**
    * @brief determines the value of the card?
    */
    void determine_value();
};

#endif // PHASETENCARDS_H
