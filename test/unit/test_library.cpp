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
    .WillOnce(Return(AnalogDigitalConverter::Error_t::OK));

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(GPIO::Error_t::OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(GPIO::Error_t::OK));

    // EXPECT_CALL(timer, init())
    // .Times(1)
    // .WillOnce(Return(Timer::Error_t::OK));

    Hss hss(&den, &in, &is, &timer, &BTS7002);

    ASSERT_EQ(Hss::Error_t::OK, hss.init());
}