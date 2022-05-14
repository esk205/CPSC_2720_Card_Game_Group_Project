#ifndef TESTCARD_H
#define TESTCARD_H

#include <cppunit/extensions/HelperMacros.h>
#include "StandardCard.h"
#include "Exceptions.h"

class TestStandardCard : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestStandardCard);

    CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    CPPUNIT_TEST(test_suit);

    CPPUNIT_TEST_EXCEPTION(test_rank_invalid, invalid_parameter_error);
    CPPUNIT_TEST(test_rank);

    CPPUNIT_TEST(test_equality_suit_false);
    CPPUNIT_TEST(test_equality_pip_false);
    CPPUNIT_TEST(test_equality_false);
    CPPUNIT_TEST(test_equality_true);

    CPPUNIT_TEST_SUITE_END();

public:
    void test_suit_invalid();
    void test_suit();

    void test_rank_invalid();
    void test_rank();

    void test_equality_suit_false();
    void test_equality_pip_false();
    void test_equality_false();
    void test_equality_true();

protected:
private:
};

#endif
