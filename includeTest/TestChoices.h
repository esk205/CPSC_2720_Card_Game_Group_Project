#ifndef TESTCHOICES_H
#define TESTCHOICES_H

#include <cppunit/extensions/HelperMacros.h>
#include "Choices.h"
#include "Exceptions.h"

class TestChoices : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestChoices);
    //CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    //CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST_SUITE_END();

public:
protected:
private:
};

#endif // TESTCHOICES_H
