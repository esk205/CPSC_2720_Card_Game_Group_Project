#ifndef TESTPHASETENCARD_H
#define TESTPHASETENCARD_H

#include <cppunit/extensions/HelperMacros.h>
#include "PhaseTenCard.h"
#include "Exceptions.h"

class TestPhaseTenCard : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPhaseTenCard);

    CPPUNIT_TEST_EXCEPTION(test_suit_invalid, invalid_parameter_error);
    CPPUNIT_TEST(test_suit_blue);
    CPPUNIT_TEST(test_suit_green);
    CPPUNIT_TEST(test_suit_red);
    CPPUNIT_TEST(test_suit_yellow);

    CPPUNIT_TEST_EXCEPTION(test_pip_invalid, invalid_parameter_error);
    CPPUNIT_TEST(test_pip_one);
    CPPUNIT_TEST(test_pip_two);
    CPPUNIT_TEST(test_pip_three);
    CPPUNIT_TEST(test_pip_four);
    CPPUNIT_TEST(test_pip_five);
    CPPUNIT_TEST(test_pip_six);
    CPPUNIT_TEST(test_pip_seven);
    CPPUNIT_TEST(test_pip_eight);
    CPPUNIT_TEST(test_pip_nine);
    CPPUNIT_TEST(test_pip_ten);
    CPPUNIT_TEST(test_pip_eleven);
    CPPUNIT_TEST(test_pip_twelve);
    CPPUNIT_TEST(test_pip_wild);

    CPPUNIT_TEST(test_skip);

    CPPUNIT_TEST_SUITE_END();

public:
    void test_suit_invalid();
    void test_suit_blue();
    void test_suit_green();
    void test_suit_red();
    void test_suit_yellow();

    void test_pip_invalid();
    void test_pip_one();
    void test_pip_two();
    void test_pip_three();
    void test_pip_four();
    void test_pip_five();
    void test_pip_six();
    void test_pip_seven();
    void test_pip_eight();
    void test_pip_nine();
    void test_pip_ten();
    void test_pip_eleven();
    void test_pip_twelve();

    void test_pip_wild();

    void test_skip();
protected:
private:
};

#endif // TESTPHASETENCARD_H
