#include "test_hss-mock.hpp"
#include "hss-bts700xShield.hpp"

/**
 *  Class C++ High-Side-Switch BTS700x Class Test Suite
 */
class Hss_BTS700xShield_Test : public ::testing::Test
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

TEST_F(Hss_BTS700xShield_Test, init_successful)
{
    // MockADC is;
    // MockGPIO den;
    // MockGPIO in;
    // MockGPIO dsel;
    // MockTimer timer;

    // EXPECT_CALL(is, init())
    // .Times(1)
    // .WillOnce(Return(OK));

    // MockADC is2;
    // MockGPIO den2;
    // MockGPIO in2;
    // MockGPIO dsel2;
    // MockTimer timer2;

    // MockADC is3;
    // MockGPIO den3;
    // MockGPIO in3;
    // MockGPIO dsel3;
    // MockTimer timer3;

    // MockADC is4;
    // MockGPIO den4;
    // MockGPIO in4;
    // MockGPIO dsel4;
    // MockTimer timer4;

    // MockHss hsw1(&den, &in, &dsel, &is, &timer);
    // MockHss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    // MockHss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    // MockHss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    // EXPECT_CALL(hsw1, init())
    // .Times(1)
    // .WillOnce(Return(OK));

    // EXPECT_CALL(hsw2, init())
    // .Times(1)
    // .WillOnce(Return(OK));

    // EXPECT_CALL(hsw3, init())
    // .Times(1)
    // .WillOnce(Return(OK));

    // EXPECT_CALL(hsw4, init())
    // .Times(1)
    // .WillOnce(Return(OK));

    // Bts700xShield hssShield(&hsw1, &hsw2, &hsw3, &hsw4);

    // ASSERT_EQ(OK, hssShield.init());
}