#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include <cppunit/extensions/HelperMacros.h>
#include "TestPlayer.h"
#include "Exceptions.h"

class TestPlayer : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPlayer);
    //CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    //CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTPLAYER_H
