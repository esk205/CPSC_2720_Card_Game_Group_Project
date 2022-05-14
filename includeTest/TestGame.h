#ifndef TESTGAME_H
#define TESTGAME_H

#include <cppunit/extensions/HelperMacros.h>
#include "Game.h"
#include "Exceptions.h"

class TestGame : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestGame);

    // CPPUNIT_TEST(test_suit_blue);

    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTGAME_H
