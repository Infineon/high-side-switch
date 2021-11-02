#include "test_hss-mock.hpp"
#include "hss.hpp"

/**
 *  Class C++ High-Side-Switch Class Test Suite
 */
class Hss_Test : public ::testing::Test
{
    public:

    /**
     * Is called before every individual test is executed
     */
    void SetUp()
    {

    }

    /**
     * Is called after every individual test was executed
     */
    void TearDown()
    {

    }
};

TEST_F(Hss_Test, init_success)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(is, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(OK, hss.init());
}