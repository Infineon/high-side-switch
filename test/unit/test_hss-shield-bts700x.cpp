#include "test_hss-mock.hpp"
#include "hss-shield-bts700x.hpp"

using namespace hss;

/**
 *  Class C++ High-Side-Switch BTS700x Class Test Suite
 */
class Hss_BTS700xShield_Test : public ::testing::Test
{
    public:

        NiceMock<MockADC> is1;
        NiceMock<MockGPIO> den1;
        NiceMock<MockGPIO> in1;
        NiceMock<MockGPIO> dsel1;
        NiceMock<MockTimer> timer1;

        NiceMock<MockADC> is2;
        NiceMock<MockGPIO> den2;
        NiceMock<MockGPIO> in2;
        NiceMock<MockGPIO> dsel2;
        NiceMock<MockTimer> timer2;

        NiceMock<MockADC> is3;
        NiceMock<MockGPIO> den3;
        NiceMock<MockGPIO> in3;
        NiceMock<MockGPIO> dsel3;
        NiceMock<MockTimer> timer3;

        NiceMock<MockADC> is4;
        NiceMock<MockGPIO> den4;
        NiceMock<MockGPIO> in4;
        NiceMock<MockGPIO> dsel4;
        NiceMock<MockTimer> timer4;

        NiceMock<MockGPIO> led1;
        NiceMock<MockGPIO> led2;
        NiceMock<MockGPIO> led3;
        NiceMock<MockGPIO> led4;

        NiceMock<MockTimer> timer;

        NiceMock<MockGPIO> oloff;
        NiceMock<MockGPIO> pushButtonDigital;

        NiceMock<MockADC> pushButtonAnalog;
        NiceMock<MockADC> vBat;

    /**
     * Is called before every individual test is executed
     */
    void SetUp()
    {
        ON_CALL(den1, init())
        .WillByDefault(Return(OK));
        ON_CALL(in1, init())
        .WillByDefault(Return(OK));
        ON_CALL(dsel1, init())
        .WillByDefault(Return(OK));
        ON_CALL(is1, init())
        .WillByDefault(Return(OK));
        ON_CALL(timer1, init())
        .WillByDefault(Return(OK));

        ON_CALL(den2, init())
        .WillByDefault(Return(OK));
        ON_CALL(in2, init())
        .WillByDefault(Return(OK));
        ON_CALL(dsel2, init())
        .WillByDefault(Return(OK));
        ON_CALL(is2, init())
        .WillByDefault(Return(OK));
        ON_CALL(timer2, init())
        .WillByDefault(Return(OK));

        ON_CALL(den3, init())
        .WillByDefault(Return(OK));
        ON_CALL(in3, init())
        .WillByDefault(Return(OK));
        ON_CALL(dsel3, init())
        .WillByDefault(Return(OK));
        ON_CALL(is3, init())
        .WillByDefault(Return(OK));
        ON_CALL(timer3, init())
        .WillByDefault(Return(OK));

        ON_CALL(den4, init())
        .WillByDefault(Return(OK));
        ON_CALL(in4, init())
        .WillByDefault(Return(OK));
        ON_CALL(dsel4, init())
        .WillByDefault(Return(OK));
        ON_CALL(is4, init())
        .WillByDefault(Return(OK));
        ON_CALL(timer4, init())
        .WillByDefault(Return(OK));

        ON_CALL(den1, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(in1, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(dsel1, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(is1, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(timer1, deinit())
        .WillByDefault(Return(OK));

        ON_CALL(den2, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(in2, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(dsel2, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(is2, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(timer2, deinit())
        .WillByDefault(Return(OK));

        ON_CALL(den3, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(in3, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(dsel3, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(is3, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(timer3, deinit())
        .WillByDefault(Return(OK));

        ON_CALL(den4, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(in4, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(dsel4, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(is4, deinit())
        .WillByDefault(Return(OK));
        ON_CALL(timer4, deinit())
        .WillByDefault(Return(OK));

        ON_CALL(in1, enable())
        .WillByDefault(Return(OK));
        ON_CALL(in2, enable())
        .WillByDefault(Return(OK));
        ON_CALL(in3, enable())
        .WillByDefault(Return(OK));
        ON_CALL(in4, enable())
        .WillByDefault(Return(OK));

        ON_CALL(in1, disable())
        .WillByDefault(Return(OK));
        ON_CALL(in2, disable())
        .WillByDefault(Return(OK));
        ON_CALL(in3, disable())
        .WillByDefault(Return(OK));
        ON_CALL(in4, disable())
        .WillByDefault(Return(OK));
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
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(vBat, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(OK, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led1_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led2_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led3_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led4_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_timer_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_oloff_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_pushButtonDigital_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_pushButtonAnalog_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_vBat_failed)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(vBat, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led1_nullptr)
{
    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(nullptr, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led2_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, nullptr, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led3_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, nullptr, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_led4_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, nullptr, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_hss1_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, nullptr, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_hss2_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, nullptr, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_hss3_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, nullptr, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_hss4_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, nullptr, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_timer_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, nullptr, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_oloff_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, nullptr, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_pushButtonDigital_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));


    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, nullptr, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_pushButtonAnalog_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, nullptr, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, init_vBat_nullptr)
{
    EXPECT_CALL(led1, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, init())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, nullptr);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.init());
}

TEST_F(Hss_BTS700xShield_Test, deinit_successful)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(vBat, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(OK, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led1_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led2_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led3_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led4_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_timer_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_oloff_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_pushButtonDigital_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_pushButtonAnalog_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_vBat_failed)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(vBat, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(CONF_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led1_nullptr)
{
    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(nullptr, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led2_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, nullptr, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led3_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, nullptr, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_led4_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, nullptr, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_hss1_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, nullptr, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_hss2_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, nullptr, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_hss3_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, nullptr, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_hss4_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, nullptr, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_timer_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, nullptr, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_oloff_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, nullptr, &pushButtonDigital, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_pushButtonDigital_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));


    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, nullptr, &pushButtonAnalog, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_pushButtonAnalog_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, nullptr, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, deinit_vBat_nullptr)
{
    EXPECT_CALL(led1, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(oloff, deinit())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(pushButtonDigital, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(pushButtonAnalog, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, nullptr);

    ASSERT_EQ(NULLPTR_ERROR, hssShield.deinit());
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_1_successful)
{
    EXPECT_CALL(led1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOn(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_2_successful)
{
    EXPECT_CALL(led2, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOn(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_3_successful)
{
    EXPECT_CALL(led3, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOn(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_4_successful)
{
    EXPECT_CALL(led4, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOn(4));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_1_failed)
{
    EXPECT_CALL(led1, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_2_failed)
{
    EXPECT_CALL(led2, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_3_failed)
{
    EXPECT_CALL(led3, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_4_failed)
{
    EXPECT_CALL(led4, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(4));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_1_hss_failed)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_2_hss_failed)
{
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_3_hss_failed)
{
    EXPECT_CALL(in3, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOn_4_hss_failed)
{
    EXPECT_CALL(in4, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOn(4));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_1_successful)
{
    EXPECT_CALL(led1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOff(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_2_successful)
{
    EXPECT_CALL(led2, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOff(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_3_successful)
{
    EXPECT_CALL(led3, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOff(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_4_successful)
{
    EXPECT_CALL(led4, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchHxOff(4));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_1_failed)
{
    EXPECT_CALL(led1, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_2_failed)
{
    EXPECT_CALL(led2, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_3_failed)
{
    EXPECT_CALL(led3, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_4_failed)
{
    EXPECT_CALL(led4, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(4));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_1_hss_failed)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(1));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_2_hss_failed)
{
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(2));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_3_hss_failed)
{
    EXPECT_CALL(in3, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(3));
}

TEST_F(Hss_BTS700xShield_Test, switchHxOff_4_hss_failed)
{
    EXPECT_CALL(in4, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchHxOff(4));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_success_all)
{
    EXPECT_CALL(led1, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchesHxOn(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_success_only_third)
{
    EXPECT_CALL(led3, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchesHxOn(false, false, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_1_fail)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOn(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_2_fail)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));


    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOn(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_3_fail)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in3, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOn(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOn_4_fail)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in3, enable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in4, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOn(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_success_all)
{
    EXPECT_CALL(led1, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led2, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led3, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(led4, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchesHxOff(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_success_only_third)
{
    EXPECT_CALL(led3, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(OK, hssShield.switchesHxOff(false, false, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_1_fail)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOff(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_2_fail)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));


    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOff(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_3_fail)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in3, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOff(true, true, true, true));
}

TEST_F(Hss_BTS700xShield_Test, switchesHxOff_4_fail)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in3, disable())
    .Times(1)
    .WillOnce(Return(OK));
    EXPECT_CALL(in4, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
    Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
    Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
    Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

    Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
    hssShield.init();

    ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOff(true, true, true, true));
}

// TEST_F(Hss_BTS700xShield_Test, readIsx_1)
// {
//     EXPECT_CALL(den1, enable())
//     .Times(1)
//     .WillOnce(Return(OK));
//     EXPECT_CALL(den1, disable())
//     .Times(1)
//     .WillOnce(Return(OK));


//     Hss hsw1(&den1, &in1, &dsel1, &is1, &timer1);
//     Hss hsw2(&den2, &in2, &dsel2, &is2, &timer2);
//     Hss hsw3(&den3, &in3, &dsel3, &is3, &timer3);
//     Hss hsw4(&den4, &in4, &dsel4, &is4, &timer4);

//     Bts700xShield hssShield(&led1, &led2, &led3, &led4, &hsw1, &hsw2, &hsw3, &hsw4, &timer, &oloff, &pushButtonDigital, &pushButtonAnalog, &vBat);
//     hssShield.init();

//     ASSERT_EQ(INTF_ERROR, hssShield.switchesHxOff(true, true, true, true));
// }
