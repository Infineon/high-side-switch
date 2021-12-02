#include "test_hss-mock.hpp"
// #include "hss.hpp"
// #include "hss-variants.hpp"
#include "hss-shield-profet24v.hpp"

/**
 *  Class C++ High-Side-Switch Profet 24V Class Test Suite
 */
class Profet24VBTTShield_Test : public ::testing::Test
{

    public:

        NiceMock<MockGPIO> den[3];
        NiceMock<MockGPIO> in[5];   
        NiceMock<MockGPIO> dsel[2];
        NiceMock<MockADC> is[3];
        NiceMock<MockTimer> timer[3];

        Hss * hsw[3];
        Profet24VBTTShield * shieldProfet24V;

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

            shieldProfet24V = new Profet24VBTTShield(hsw[0], hsw[1], hsw[2]);
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

            delete shieldProfet24V;
        }
};

/**
 * init()
 */

TEST_F(Profet24VBTTShield_Test, init_Error)
{
    EXPECT_CALL(den[0],init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shieldProfet24V->init());
}

TEST_F(Profet24VBTTShield_Test, init_Success)
{
    ASSERT_EQ(OK, shieldProfet24V->init());
}

/**
 * deinit()
 */

TEST_F(Profet24VBTTShield_Test, deinit_Error)
{
    EXPECT_CALL(den[0],deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shieldProfet24V->deinit());
}

TEST_F(Profet24VBTTShield_Test, deinit_Success)
{
    ASSERT_EQ(OK, shieldProfet24V->deinit());
}

/**
 * switchHxOn()
 */

TEST_F(Profet24VBTTShield_Test, switchHxOn_Error)
{
    shieldProfet24V->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(INTF_ERROR));

        ASSERT_EQ(INTF_ERROR, shieldProfet24V->switchHxOn(i));
    }
}

TEST_F(Profet24VBTTShield_Test, switchHxOn_Success)
{
    shieldProfet24V->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(OK));

        ASSERT_EQ(OK, shieldProfet24V->switchHxOn(i));
    }
}

/**
 * switchHxOff()
 */

TEST_F(Profet24VBTTShield_Test, switchHxOff_Error)
{
    shieldProfet24V->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(INTF_ERROR));

        ASSERT_EQ(INTF_ERROR, shieldProfet24V->switchHxOff(i));
    }
}

TEST_F(Profet24VBTTShield_Test, switchHxOff_Success)
{
    shieldProfet24V->init();

    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(OK));

        ASSERT_EQ(OK, shieldProfet24V->switchHxOff(i));
    }
}

/**
 * switchesHxOn()
 */

TEST_F(Profet24VBTTShield_Test, switchesHxOn_Error)
{
    EXPECT_CALL(in[0],enable())
    .WillOnce(Return(INTF_ERROR));

    shieldProfet24V->init();
    
    ASSERT_EQ(INTF_ERROR, shieldProfet24V->switchesHxOn(true, true, true, true, true));
}

TEST_F(Profet24VBTTShield_Test, switchesHxOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],enable())
        .WillOnce(Return(OK));
    }

    shieldProfet24V->init();

    ASSERT_EQ(OK, shieldProfet24V->switchesHxOn(true, true, true, true, true));
}

/**
 * switchesHxOff()
 */

TEST_F(Profet24VBTTShield_Test, switchesHxOff_Error)
{
    EXPECT_CALL(in[0],disable())
    .WillOnce(Return(INTF_ERROR));

    shieldProfet24V->init();
    
    ASSERT_EQ(INTF_ERROR, shieldProfet24V->switchesHxOff(true, true, true, true, true));
}

TEST_F(Profet24VBTTShield_Test, switchesHxOff_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        EXPECT_CALL(in[i],disable())
        .WillOnce(Return(OK));
    }

    shieldProfet24V->init();

    ASSERT_EQ(OK, shieldProfet24V->switchesHxOff(true, true, true, true, true));
}

/**
 * readIsx()
 */

TEST_F(Profet24VBTTShield_Test, readIsx_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        shieldProfet24V->init();
    
        ASSERT_EQ(0, shieldProfet24V->readIsx(i));
    }
}

/**
 * readDiagx()
 */


TEST_F(Profet24VBTTShield_Test, readDiagx_NotPowerOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        shieldProfet24V->init();
    
        ASSERT_EQ(0, shieldProfet24V->readDiagx(i));
    }
}

TEST_F(Profet24VBTTShield_Test, readDiagx_PowerOn_Success)
{
    for(uint8_t i = 0; i < 5; i++)
    {
        shieldProfet24V->init();
        shieldProfet24V->switchesHxOn(true, true, true, true, true);
    
        ASSERT_EQ(OPEN_LOAD, shieldProfet24V->readDiagx(i));
    }
}
