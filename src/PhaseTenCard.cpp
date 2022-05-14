#include "PhaseTenCard.h"
#include "AppConstants.h"
#include "Exceptions.h"

PhaseTenCard::PhaseTenCard(string suit, string pip) : Card {suit, pip}
{
    if (suit != AppConstants::PHASETEN_SUIT_BLUE && suit != AppConstants::PHASETEN_SUIT_GREEN
    && suit != AppConstants::PHASETEN_SUIT_RED && suit != AppConstants::PHASETEN_SUIT_YELLOW
    && pip != AppConstants::PHASETEN_SKIP)
        throw invalid_parameter_error("Not a proper suit of Phase Ten");

    if (pip != AppConstants::PHASETEN_PIP_ONE && pip != AppConstants::PHASETEN_PIP_ELEVEN
    && pip != AppConstants::PHASETEN_PIP_TWELVE && pip != AppConstants::STANDARD_PIP_TWO
    && pip != AppConstants::STANDARD_PIP_THREE && pip != AppConstants::STANDARD_PIP_FOUR
    && pip != AppConstants::STANDARD_PIP_FIVE && pip != AppConstants::STANDARD_PIP_SIX
    && pip != AppConstants::STANDARD_PIP_SEVEN && pip != AppConstants::STANDARD_PIP_EIGHT
    && pip != AppConstants::STANDARD_PIP_NINE && pip != AppConstants::STANDARD_PIP_TEN
    && pip != AppConstants::PHASETEN_PIP_WILD && pip != AppConstants::PHASETEN_SKIP)
        throw invalid_parameter_error("Not a proper Pip of Phase Ten");

    PhaseTenCard::suit = suit;
    PhaseTenCard::pip = pip;
}

PhaseTenCard::~PhaseTenCard()
{
    //dtor
}
