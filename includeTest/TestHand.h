#ifndef TESTHAND_H
#define TESTHAND_H

#include <cppunit/extensions/HelperMacros.h>
#include "Hand.h"
#include "Exceptions.h"

class TestHand : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestHand);

    CPPUNIT_TEST(test_add_card);
    CPPUNIT_TEST(test_empty_hand);
    CPPUNIT_TEST(test_remove_card_obj);
    CPPUNIT_TEST(test_remove_card_pos);
    CPPUNIT_TEST(test_get_card);
    CPPUNIT_TEST(test_sort_by_value);
    CPPUNIT_TEST(test_sort_by_suit);
    CPPUNIT_TEST(test_cards_remaining);

    CPPUNIT_TEST_SUITE_END();

public:
    void test_add_card();
    void test_empty_hand();
    void test_remove_card_obj();
    void test_remove_card_pos();
    void test_get_card();
    void test_sort_by_value();
    void test_sort_by_suit();
    void test_cards_remaining();

protected:
private:
};

#endif // TESTHAND_H
