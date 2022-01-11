#include "test_hss-mock.hpp"
#include "hss-shield-bts5001x.hpp"

/**
 *  Class C++ High-Side-Switch Profet 24V Class Test Suite
 */
class Bts5001xShield_Test : public ::testing::Test
{

    public:

        NiceMock<MockGPIO> den, in, led1, led2;
        NiceMock<MockADC> is, pushButton, vBat;
        NiceMock<MockTimer> timer;

        Hss * hsw;
        Bts5001xShield * shield;

        /**
         * Is called before every individual test is executed
         */
        void SetUp()
        {
            hsw    = new Hss(&den, &in, &is, &timer, &BTS50015);
            shield = new Bts5001xShield(hsw, &led1, &led2, &pushButton, &vBat);

            ON_CALL(den,init())
            .WillByDefault(Return(OK));

            ON_CALL(in,init())
            .WillByDefault(Return(OK));

            ON_CALL(is,init())
            .WillByDefault(Return(OK));

            ON_CALL(timer,init())
            .WillByDefault(Return(OK));

            ON_CALL(den,deinit())
            .WillByDefault(Return(OK));

            ON_CALL(in,deinit())
            .WillByDefault(Return(OK));

            ON_CALL(is,deinit())
            .WillByDefault(Return(OK));

            ON_CALL(timer,deinit())
            .WillByDefault(Return(OK));

        }

        /**
         * Is called after every individual test was executed
         */
        void TearDown()
        {
            delete hsw;
            delete shield;
        }
};

/**
 * init()
 */

TEST_F(Bts5001xShield_Test, init_Error)
{
    EXPECT_CALL(den, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts5001xShield_Test, init_Nullptr_Error)
{
    Bts5001xShield shield2(nullptr, &led1, &led2, &pushButton, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, shield2.init());
}

TEST_F(Bts5001xShield_Test, init_Success)
{
    ASSERT_EQ(OK, shield->init());
}

/**
 * deinit()
 */

TEST_F(Bts5001xShield_Test, deinit_Error)
{
    EXPECT_CALL(den, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts5001xShield_Test, deinit_Nullptr_Error)
{
    Bts5001xShield shield2(nullptr, &led1, &led2, &pushButton, &vBat);

    ASSERT_EQ(NULLPTR_ERROR, shield2.deinit());
}

TEST_F(Bts5001xShield_Test, deinit_Success)
{
    ASSERT_EQ(OK, shield->deinit());
}

/**
 * switchHxOn()
 */

TEST_F(Bts5001xShield_Test, switchHxOn_Error)
{
    EXPECT_CALL(in, enable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();

    ASSERT_EQ(INTF_ERROR, shield->switchHxOn());
}

TEST_F(Bts5001xShield_Test, switchHxOn_Success)
{
    shield->init();

    ASSERT_EQ(OK, shield->switchHxOn());
}

/**
 * switchHxOn()
 */

TEST_F(Bts5001xShield_Test, switchHxOff_Error)
{
    EXPECT_CALL(in, disable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();

    ASSERT_EQ(INTF_ERROR, shield->switchHxOff());
}

TEST_F(Bts5001xShield_Test, switchHxOff_Success)
{
    shield->init();

    ASSERT_EQ(OK, shield->switchHxOff());
}

/**
 * readDiagx()
 */

TEST_F(Bts5001xShield_Test, readDiagx_Error)
{
    shield->init();

    ASSERT_EQ(NORMAL, shield->readDiagx());
}

/**
 * readIsx()
 */

TEST_F(Bts5001xShield_Test, readIsx_Success)
{
    shield->init();

    ASSERT_EQ(0, shield->readIsx());
}

/**
 * readDiagx()
 */

TEST_F(Bts5001xShield_Test, readDiagx_Openload_InverseCurrent)
{
    shield->init();
    shield->switchHxOn();

    ASSERT_EQ(FAULT_OL_IC, shield->readDiagx());
}

/**
 * analogReadButton()
 */

TEST_F(Bts5001xShield_Test, analogReadButton_true_Success)
{
    shield->init();

    ASSERT_EQ(true, shield->analogReadButton());
}

TEST_F(Bts5001xShield_Test, analogReadButton_false_Success)
{
    EXPECT_CALL(pushButton, ADCRead())
    .WillOnce(Return(30));

    shield->init();

    ASSERT_EQ(false, shield->analogReadButton());
}