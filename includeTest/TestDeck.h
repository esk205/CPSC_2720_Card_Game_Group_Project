#ifndef TESTDECK_H
#define TESTDECK_H

#include <cppunit/extensions/HelperMacros.h>
#include "Deck.h"
#include "Exceptions.h"

class TestDeck : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestDeck);
    CPPUNIT_TEST(test_addCard);
    CPPUNIT_TEST(test_drawCard);
    CPPUNIT_TEST(test_shuffle);
    CPPUNIT_TEST(test_badShuffle);
    CPPUNIT_TEST(test_cardsRemaining);
    CPPUNIT_TEST(test_getCard);
    CPPUNIT_TEST(test_emptyStandardDeck);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
    * @brief
    */
    void test_addCard();

    /**
    * @brief
    */
    void test_drawCard();

    /**
    * @brief
    */
    void test_shuffle();

    /**
    * @brief
    **/
    void test_badShuffle();

    /**
    * @brief
    */
    void test_cardsRemaining();

    /**
    * @brief
    */
    void test_getCard();

    /**
    * @brief
    */
    void test_emptyStandardDeck();
protected:
private:
};

#endif // TESTDECK_H
