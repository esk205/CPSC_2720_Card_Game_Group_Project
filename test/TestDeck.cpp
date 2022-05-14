#include "TestDeck.h"
#include "Hand.h"
#include "StandardCard.h"
#include "PhaseTenCard.h"
#include "AppConstants.h"

/// Register to the test fixture.
CPPUNIT_TEST_SUITE_REGISTRATION(TestDeck);

void TestDeck::test_addCard() {

}

void TestDeck::test_drawCard() {

}

void TestDeck::test_shuffle() {

}

void TestDeck::test_badShuffle() {

}

void TestDeck::test_cardsRemaining() {

}

void TestDeck::test_getCard() {
    Hand h = Hand();
    Card testCard = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::STANDARD_PIP_TWO);

    h.addCard(testCard);
    h.getCard(0);
    h.emptyHand();


    CPPUNIT_ASSERT(h.cardsRemaining() == 0);
}

void TestDeck::test_emptyStandardDeck() {
    Hand h = Hand();
    CPPUNIT_ASSERT(h.cardsRemaining() == 0);
}
