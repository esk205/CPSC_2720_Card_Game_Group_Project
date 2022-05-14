#include "BlackjackCard.h"

/**
* Similar to StandardCard but face cards are 10 and ace is 11.
*/
BlackjackCard::BlackjackCard(string suit, string pip) : Card {suit, pip}
{
    if (suit != AppConstants::STANDARD_SUIT_SPADES && suit != AppConstants::STANDARD_SUIT_CLUBS
    && suit != AppConstants::STANDARD_SUIT_DIAMONDS && suit != AppConstants::STANDARD_SUIT_HEARTS)
        throw invalid_parameter_error("The Suit must be a standard suit");

    /// I personally don't like this way but it will have to do
    if (pip != AppConstants::STANDARD_PIP_ACE && pip != AppConstants::STANDARD_PIP_TWO
    && pip != AppConstants::STANDARD_PIP_THREE && pip != AppConstants::STANDARD_PIP_FOUR
    && pip != AppConstants::STANDARD_PIP_FIVE && pip != AppConstants::STANDARD_PIP_SIX
    && pip != AppConstants::STANDARD_PIP_SEVEN && pip != AppConstants::STANDARD_PIP_EIGHT
    && pip != AppConstants::STANDARD_PIP_NINE && pip != AppConstants::STANDARD_PIP_TEN
    && pip != AppConstants::STANDARD_PIP_JACK && pip != AppConstants::STANDARD_PIP_QUEEN
    && pip != AppConstants::STANDARD_PIP_KING)
        throw invalid_parameter_error("The Pip must be a standard card pip, discluding jokers");

    BlackjackCard::suit = suit;
    BlackjackCard::pip = pip;

    determineValue();
}

BlackjackCard::~BlackjackCard()
{
    //dtor
}

void BlackjackCard::determineValue()
{
    if(pip == AppConstants::STANDARD_PIP_JACK ||
        pip == AppConstants::STANDARD_PIP_QUEEN ||
        pip == AppConstants::STANDARD_PIP_KING)
        rankingValue = 10;
    else if(pip == AppConstants::STANDARD_PIP_ACE)
        rankingValue = 11;
    else if (pip == AppConstants::STANDARD_PIP_TWO)
        rankingValue = AppConstants::STANDARD_PIP_TWO_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_THREE)
        rankingValue = AppConstants::STANDARD_PIP_THREE_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_FOUR)
        rankingValue = AppConstants::STANDARD_PIP_FOUR_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_FIVE)
        rankingValue = AppConstants::STANDARD_PIP_FIVE_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_SIX)
        rankingValue = AppConstants::STANDARD_PIP_SIX_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_SEVEN)
        rankingValue = AppConstants::STANDARD_PIP_SEVEN_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_EIGHT)
        rankingValue = AppConstants::STANDARD_PIP_EIGHT_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_NINE)
        rankingValue = AppConstants::STANDARD_PIP_NINE_VALUE;
    else if (pip == AppConstants::STANDARD_PIP_TEN)
        rankingValue = AppConstants::STANDARD_PIP_TEN_VALUE;

    // Suits don't matter
    suitRanking = rankingValue;
}
