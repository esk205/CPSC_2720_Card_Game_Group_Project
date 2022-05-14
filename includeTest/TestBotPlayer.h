#ifndef TESTBOTPLAYER_H
#define TESTBOTPLAYER_H

#include <cppunit/extensions/HelperMacros.h>
#include "TestBotPlayer.h"
#include "Exceptions.h"

class TestBotPlayer : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBotPlayer);
    //CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    //CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTBOTPLAYER_H
