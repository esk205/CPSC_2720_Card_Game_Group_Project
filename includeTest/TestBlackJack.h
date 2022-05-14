#ifndef TESTBLACKJACK_H
#define TESTBLACKJACK_H

#include <cppunit/extensions/HelperMacros.h>
#include "TestBlackJack.h"
#include "Exceptions.h"

class TestBlackJack : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBlackJack);
    //CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    //CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTBLACKJACK_H
