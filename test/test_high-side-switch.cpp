#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/corelib/high-side-switch.h"

using ::testing::Return;
//using ::testing::Matcher;
// using ::testing::NotNull;
// using ::testing::Sequence;
using ::testing::_;

/**
 * Class High Side Switch Test Suite
 */
class HSSwitchAPI: public ::testing::Test
{
    public:
    	
        HighSideSwitch hsswitch;

        void setUp()
        {

        }

        void TearDown()
        {

        }
};

TEST_F(HSSwitchAPI, checkBegin)
{
    ASSERT_EQ(hsswitch.begin(),0);
}



/**
 * Mock Utility Class
 */
// class MockUtility: public Utility
// {
//     public:
//         MOCK_METHOD(char, someUtilFunction, (char a),(override));
// };

// TEST_F(ArduinoAPI, checkSomeFunctionError)
// {
//     MockUtility mocku;

//     EXPECT_CALL(mocku, someUtilFunction(_))
//         .WillOnce(Return((char)'e'));

//     ASSERT_EQ(object.someFunction(mocku),1);
// }