#include "TestPhaseTenCard.h"
#include "AppConstants.h"

/// Register to the test fixture.
CPPUNIT_TEST_SUITE_REGISTRATION(TestPhaseTenCard);

/** Suit tests **/
void TestPhaseTenCard::test_suit_invalid()
{
    PhaseTenCard ptc = PhaseTenCard("Ayy Lmao", AppConstants::PHASETEN_PIP_ONE);
}

void TestPhaseTenCard::test_suit_blue()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::PHASETEN_PIP_ONE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_SUIT_BLUE, ptc.getSuit());
}

void TestPhaseTenCard::test_suit_green()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_GREEN, AppConstants::PHASETEN_PIP_ONE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_SUIT_GREEN, ptc.getSuit());
}

void TestPhaseTenCard::test_suit_red()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_RED, AppConstants::PHASETEN_PIP_ONE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_SUIT_RED, ptc.getSuit());
}

void TestPhaseTenCard::test_suit_yellow()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_YELLOW, AppConstants::PHASETEN_PIP_ONE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_SUIT_YELLOW, ptc.getSuit());
}

/** Pip tests **/
void TestPhaseTenCard::test_pip_invalid()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, "Dreaming of Cheese");
}

void TestPhaseTenCard::test_pip_one()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::PHASETEN_PIP_ONE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_PIP_ONE, ptc.getPip());
}

void TestPhaseTenCard::test_pip_two()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_TWO);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_TWO, ptc.getPip());
}

void TestPhaseTenCard::test_pip_three()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_THREE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_THREE, ptc.getPip());
}

void TestPhaseTenCard::test_pip_four()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_FOUR);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_FOUR, ptc.getPip());
}

void TestPhaseTenCard::test_pip_five()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_FIVE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_FIVE, ptc.getPip());
}

void TestPhaseTenCard::test_pip_six()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_SIX);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_SIX, ptc.getPip());
}

void TestPhaseTenCard::test_pip_seven()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_SEVEN);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_SEVEN, ptc.getPip());
}

void TestPhaseTenCard::test_pip_eight()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_EIGHT);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_EIGHT, ptc.getPip());
}

void TestPhaseTenCard::test_pip_nine()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_NINE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_NINE, ptc.getPip());
}

void TestPhaseTenCard::test_pip_ten()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::STANDARD_PIP_TEN);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_TEN, ptc.getPip());
}

void TestPhaseTenCard::test_pip_eleven()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::PHASETEN_PIP_ELEVEN);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_PIP_ELEVEN, ptc.getPip());
}

void TestPhaseTenCard::test_pip_twelve()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_BLUE, AppConstants::PHASETEN_PIP_TWELVE);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_PIP_TWELVE, ptc.getPip());
}

/** Wild Card **/
void TestPhaseTenCard::test_pip_wild()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SUIT_RED, AppConstants::PHASETEN_PIP_WILD);
    CPPUNIT_ASSERT_EQUAL(AppConstants::PHASETEN_PIP_WILD, ptc.getPip());
}

/** Skip Card **/
void TestPhaseTenCard::test_skip()
{
    PhaseTenCard ptc = PhaseTenCard(AppConstants::PHASETEN_SKIP, AppConstants::PHASETEN_SKIP);
    CPPUNIT_ASSERT(AppConstants::PHASETEN_SKIP == ptc.getSuit() && AppConstants::PHASETEN_SKIP == ptc.getPip());
}
