#ifndef TESTMENU_H
#define TESTMENU_H

#include <cppunit/extensions/HelperMacros.h>
#include "Menu.h"
#include "Exceptions.h"

class TestMenu : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestMenu);
    //CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    //CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTMENU_H
