#include "test_hss-mock.hpp"
#include "hss-shield-btt60xx.hpp"

/**
 *  Class C++ High-Side-Switch Profet 24V Class Test Suite
 */
class Btt60xxShield_Test : public ::testing::Test
{

    public:

        NiceMock<MockGPIO> den[3];
        NiceMock<MockGPIO> in[5];
        NiceMock<MockGPIO> dsel[2];
        NiceMock<MockADC> is[3];
        NiceMock<MockTimer> timer[3];

        Hss * hsw[3];
        Btt60xxShield * btt60xxShield;

        /**
         * Is called before every individual test is executed
         */
        void SetUp()
        {
            for(uint8_t i = 0; i < 3; i++)
            {
                if(2 == i)
                {
                    hsw[i] = new Hss(&den[i], &in[2*i], &is[i], &timer[i], &BTT6020);
                }
                else
                {
                    hsw[i] = new Hss(&den[i], &in[2*i], &in[2*i + 1], &dsel[i], &is[i], &timer[i], &BTT6030);
                }

                ON_CALL(den[i],init())
                .WillByDefault(Return(OK));

                ON_CALL(in[i],init())
                .WillByDefault(Return(OK));

                ON_CALL(dsel[i],init())
                .WillByDefault(Return(OK));

                ON_CALL(is[i],init())
                .WillByDefault(Return(OK));

                ON_CALL(timer[i],init())
                .WillByDefault(Return(OK));

                ON_CALL(den[i],deinit())
                .WillByDefault(Return(OK));

                ON_CALL(in[i],deinit())
                .WillByDefault(Return(OK));

                ON_CALL(dsel[i],deinit())
                .WillByDefault(Return(OK));

                ON_CALL(is[i],deinit())
                .WillByDefault(Return(OK));

                ON_CALL(timer[i],deinit())
                .WillByDefault(Return(OK));
            }

            btt60xxShield = new Btt60xxShield(hsw[0], hsw[1], hsw[2]);
        }

        /**
         * Is called after every individual test was executed
         */
        void TearDown()
        {
            for(uint8_t i = 0; i < 3; i++)
            {
                delete hsw[i];
            }

            delete btt60xxShield;
        }
};

/**
 * init()
 */

TEST_F(Btt60xxShield_Test, init_Error)
{
    EXPECT_CALL(den[0],init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, btt60xxShield->init());
}

TEST_F(Btt60xxShield_Test, init_Success)
{
    ASSERT_EQ(OK, btt60xxShield->init());
}

/**
 * deinit()
 */

TEST_F(Btt60xxShield_Test, deinit_Error)
{
    EXPECT_CALL(den[0],deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, btt60xxShield->deinit());
}

TEST_F(Btt60xxShield_Test, deinit_Success)
{
    ASSERT_EQ(OK, btt60xxShield->deinit());
}

/**
 * switchHxOn()
 */

TEST_F(Btt60xxShield_Test, switchHxOn_Error)
{
    btt60xxShield->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(INTF_ERROR));

        ASSERT_EQ(INTF_ERROR, btt60xxShield->switchHxOn(i));
    }
}

TEST_F(Btt60xxShield_Test, switchHxOn_Success)
{
    btt60xxShield->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(OK));

        ASSERT_EQ(OK, btt60xxShield->switchHxOn(i));
    }
}

/**
 * switchHxOff()
 */

TEST_F(Btt60xxShield_Test, switchHxOff_Error)
{
    btt60xxShield->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(INTF_ERROR));

        ASSERT_EQ(INTF_ERROR, btt60xxShield->switchHxOff(i));
    }
}

TEST_F(Btt60xxShield_Test, switchHxOff_Success)
{
    btt60xxShield->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(OK));

        ASSERT_EQ(OK, btt60xxShield->switchHxOff(i));
    }
}

/**
 * switchesHxOn()
 */

TEST_F(Btt60xxShield_Test, switchesHxOn_Error)
{
    EXPECT_CALL(in[0],enable())
    .WillOnce(Return(INTF_ERROR));

    btt60xxShield->init();

    ASSERT_EQ(INTF_ERROR, btt60xxShield->switchesHxOn(true, true, true, true, true));
}

TEST_F(Btt60xxShield_Test, switchesHxOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(OK));
    }

    btt60xxShield->init();

    ASSERT_EQ(OK, btt60xxShield->switchesHxOn(true, true, true, true, true));
}

/**
 * switchesHxOff()
 */

TEST_F(Btt60xxShield_Test, switchesHxOff_Error)
{
    EXPECT_CALL(in[0],disable())
    .WillOnce(Return(INTF_ERROR));

    btt60xxShield->init();

    ASSERT_EQ(INTF_ERROR, btt60xxShield->switchesHxOff(true, true, true, true, true));
}

TEST_F(Btt60xxShield_Test, switchesHxOff_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(OK));
    }

    btt60xxShield->init();

    ASSERT_EQ(OK, btt60xxShield->switchesHxOff(true, true, true, true, true));
}

/**
 * readIsx()
 */

TEST_F(Btt60xxShield_Test, readIsx_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        btt60xxShield->init();

        ASSERT_EQ(0, btt60xxShield->readIsx(i));
    }
}

/**
 * readDiagx()
 */


TEST_F(Btt60xxShield_Test, readDiagx_NotPowerOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        btt60xxShield->init();

        ASSERT_EQ(0, btt60xxShield->readDiagx(i));
    }
}

TEST_F(Btt60xxShield_Test, readDiagx_PowerOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        btt60xxShield->init();
        btt60xxShield->switchesHxOn(true, true, true, true, true);

        ASSERT_EQ(FAULT_OL_IC, btt60xxShield->readDiagx(i));
    }
}
