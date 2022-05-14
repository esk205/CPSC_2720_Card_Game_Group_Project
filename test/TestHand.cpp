#include "TestHand.h"
#include "PhaseTenCard.h"
#include "StandardCard.h"
#include "AppConstants.h"


/// Register to the test fixture.
CPPUNIT_TEST_SUITE_REGISTRATION(TestHand);

void TestHand::test_add_card()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(ptc);
    h.addCard(sc);

    CPPUNIT_ASSERT(h.getCard(0) == ptc && h.getCard(1) == sc && h.cardsRemaining() == 2);
}

void TestHand::test_empty_hand()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(ptc);
    h.addCard(sc);
    h.emptyHand();

    /// When the hand gets emptied that means there should be 0 cards remaining in Hand.
    CPPUNIT_ASSERT(h.cardsRemaining() == 0);
}

void TestHand::test_remove_card_obj()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(ptc);
    h.addCard(sc);
    h.removeCard(ptc);

    /// Since the ptc card is removed then the index should shift and sc card should be the first element.
    CPPUNIT_ASSERT(h.getCard(0) == sc && h.cardsRemaining() == 1);
}

void TestHand::test_remove_card_pos()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc1 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    StandardCard sc2 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_KING);
    h.addCard(ptc);
    h.addCard(sc1);
    h.addCard(sc2);
    h.removeCard(1);

    CPPUNIT_ASSERT(h.getCard(1) == sc2 && h.cardsRemaining() == 2);
}

void TestHand::test_get_card()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(ptc);
    h.addCard(sc);

    CPPUNIT_ASSERT(h.getCard(0) == ptc && h.cardsRemaining() == 2);
}

#include <iostream>
void TestHand::test_sort_by_value()
{
    Hand h = Hand();
    StandardCard sc1 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_KING);
    StandardCard sc2 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc3 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(sc1);
    h.addCard(sc2);
    h.addCard(sc3);
    h.sortByValue();

    CPPUNIT_ASSERT(h.getCard(0) == sc2 && h.getCard(1) == sc3
                   && h.getCard(2) == sc1 && h.cardsRemaining() == 3);
}

void TestHand::test_sort_by_suit()
{
    Hand h = Hand();
    StandardCard sc1 = StandardCard(AppConstants::STANDARD_SUIT_SPADES, AppConstants::STANDARD_PIP_QUEEN);
    StandardCard sc2 = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_QUEEN);
    StandardCard sc3 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_KING);
    StandardCard sc4 = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(sc1);
    h.addCard(sc2);
    h.addCard(sc3);
    h.addCard(sc4);
    h.sortBySuit();

    CPPUNIT_ASSERT(h.getCard(0) == sc4 && h.getCard(1) == sc3 && h.getCard(2) == sc1
                   && h.getCard(3) == sc2 && h.cardsRemaining() == 4);
}

void TestHand::test_cards_remaining()
{
    Hand h = Hand();
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    h.addCard(ptc);
    h.addCard(sc);

    CPPUNIT_ASSERT(h.cardsRemaining() == 2);
}
