#include "TestStandardCard.h"
#include "AppConstants.h"

/// Register to the test suite.
CPPUNIT_TEST_SUITE_REGISTRATION(TestStandardCard);

/**** Suit Test ****/

void TestStandardCard::test_suit_invalid()
{
    /// Return an invalid_parameter_error
    StandardCard sc = StandardCard("Crippeling Depression", AppConstants::STANDARD_PIP_KING);
}

void TestStandardCard::test_suit()
{
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_SPADES, AppConstants::STANDARD_PIP_KING);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_SUIT_SPADES, sc.getSuit());
}

/**** Rank Test ****/

void TestStandardCard::test_rank_invalid()
{
    /// Return an invalid_parameter_error
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_HEARTS, "Osteoporosis");
}

void TestStandardCard::test_rank()
{
    StandardCard sc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_KING);
    CPPUNIT_ASSERT_EQUAL(AppConstants::STANDARD_PIP_KING, sc.getPip());
}

/** Equality Test **/
void TestStandardCard::test_equality_suit_false()
{
    /// Compares two standard cards with differing suits
    StandardCard fsc = StandardCard(AppConstants::STANDARD_SUIT_HEARTS, AppConstants::STANDARD_PIP_ACE);
    StandardCard lsc = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_ACE);

    CPPUNIT_ASSERT(fsc != lsc);
}

void TestStandardCard::test_equality_pip_false()
{
    /// Compares two standard cards with equal suits
    StandardCard fsc = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_TWO);
    StandardCard lsc = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_ACE);

    CPPUNIT_ASSERT(fsc != lsc);
}

void TestStandardCard::test_equality_false()
{
    /// Where neither the Suit or the Pip are equal
    StandardCard fsc = StandardCard(AppConstants::STANDARD_SUIT_SPADES, AppConstants::STANDARD_PIP_ACE);
    StandardCard lsc = StandardCard(AppConstants::STANDARD_SUIT_DIAMONDS, AppConstants::STANDARD_PIP_TWO);

    CPPUNIT_ASSERT(fsc != lsc);
}

void TestStandardCard::test_equality_true()
{
    /// Where neither the Suit or the Pip are equal
    StandardCard fsc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);
    StandardCard lsc = StandardCard(AppConstants::STANDARD_SUIT_CLUBS, AppConstants::STANDARD_PIP_QUEEN);

    CPPUNIT_ASSERT(fsc == lsc);
}
