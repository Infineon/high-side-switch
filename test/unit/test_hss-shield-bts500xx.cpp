#include "test_hss-mock.hpp"
#include "hss-shield-bts500xx.hpp"

/**
 *  Class C++ High-Side-Switch Profet 24V Class Test Suite
 */
class Bts500xxShield_Test : public ::testing::Test
{

    public:

        NiceMock<MockGPIO> den, in, dsel, led1, led2;
        NiceMock<MockADC> is, pushButton, vBat;
        NiceMock<MockTimer> timer;

        Hss * hsw;
        Bts500xxShield * shield;

        /**
         * Is called before every individual test is executed
         */
        void SetUp()
        {
            hsw    = new Hss(&den, &in, &dsel, &is, &timer);
            shield = new Bts500xxShield(hsw, &led1, &led2);

            ON_CALL(den,init())
            .WillByDefault(Return(OK));

            ON_CALL(in,init())
            .WillByDefault(Return(OK));

            ON_CALL(dsel,init())
            .WillByDefault(Return(OK));

            ON_CALL(is,init())
            .WillByDefault(Return(OK));

            ON_CALL(timer,init())
            .WillByDefault(Return(OK));

            ON_CALL(den,deinit())
            .WillByDefault(Return(OK));

            ON_CALL(in,deinit())
            .WillByDefault(Return(OK));

            ON_CALL(dsel,deinit())
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

TEST_F(Bts500xxShield_Test, init_Error)
{
    // EXPECT_CALL(den, init())
    // .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(OK, shield->init());
}
