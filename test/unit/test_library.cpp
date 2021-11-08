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

TEST_F(Hss_Test, init_nullptr_error)
{
    MockADC is;
    MockGPIO in;
    MockTimer timer;

    Hss hss(nullptr, &in, &is, &timer);

    ASSERT_EQ(NULLPTR_ERROR, hss.init());
}

TEST_F(Hss_Test, init_nullptr_error_2)
{
    MockADC is;
    MockGPIO den;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, nullptr, &is, &timer);

    ASSERT_EQ(NULLPTR_ERROR, hss.init());
}

TEST_F(Hss_Test, init_nullptr_error_3)
{
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, nullptr, &timer);

    ASSERT_EQ(NULLPTR_ERROR, hss.init());
}

TEST_F(Hss_Test, init_nullptr_error_4)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &is, nullptr);

    ASSERT_EQ(NULLPTR_ERROR, hss.init());
}

TEST_F(Hss_Test, den_init_conf_error)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.init());
}

TEST_F(Hss_Test, in_init_error)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.init());
}

TEST_F(Hss_Test, is_init_error)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.init());
}

TEST_F(Hss_Test, timer_init_error)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(den, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.init());
}

TEST_F(Hss_Test, init_success_with_dsel)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockGPIO dsel;
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

    EXPECT_CALL(dsel, init())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, init())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(OK, hss.init());
}

TEST_F(Hss_Test, init_error_with_dsel)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockGPIO dsel;
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

    EXPECT_CALL(dsel, init())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.init());
}

TEST_F(Hss_Test, deinit_success)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(is, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(OK, hss.deinit());
}

TEST_F(Hss_Test, deinit_error)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockTimer timer;

    EXPECT_CALL(is, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.deinit());
}

TEST_F(Hss_Test, deinit_success_with_dsel)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockGPIO dsel;
    MockTimer timer;

    EXPECT_CALL(is, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(dsel, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(OK, hss.deinit());
}

TEST_F(Hss_Test, deinit_error_with_dsel)
{
    MockADC is;
    MockGPIO den;
    MockGPIO in;
    MockGPIO dsel;
    MockTimer timer;

    EXPECT_CALL(is, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(dsel, deinit())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, deinit())
    .Times(1)
    .WillOnce(Return(CONF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(CONF_ERROR, hss.deinit());
}

TEST_F(Hss_Test, enable_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.enable());
}

TEST_F(Hss_Test, enable_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.enable());
}

TEST_F(Hss_Test, enable_not_initialized)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.enable());
}

TEST_F(Hss_Test, disable_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.disable());
}


TEST_F(Hss_Test, disable_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.disable());
}

TEST_F(Hss_Test, disable_not_initialized)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.disable());
}

TEST_F(Hss_Test, enableDiagnosis_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(den, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.enableDiag());
}


TEST_F(Hss_Test, enableDiagnosis_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(den, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.enableDiag());
}

TEST_F(Hss_Test, enableDiagnosis_not_initialized)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.enableDiag());
}

TEST_F(Hss_Test, disableDiagnosis_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(den, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.disableDiag());
}


TEST_F(Hss_Test, disableDiagnosis_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(den, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.disableDiag());
}

TEST_F(Hss_Test, disableDiagnosis_not_initialized)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.disableDiag());
}

TEST_F(Hss_Test, getEnDiagStatus_enabled)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enableDiag();

    ASSERT_EQ(DIAG_EN, hss.getEnDiagStatus());
}

TEST_F(Hss_Test, getEnDiagStatus_disabled)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.disableDiag();

    ASSERT_EQ(DIAG_DIS, hss.getEnDiagStatus());
}

TEST_F(Hss_Test, diagSelectChannelZero_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(dsel, disable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.diagSelCh0());
}

TEST_F(Hss_Test, diagSelectChannelZero_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(dsel, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.diagSelCh0());
}

TEST_F(Hss_Test, diagSelectChannelZero_not_init)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.diagSelCh0());
}

TEST_F(Hss_Test, diagSelectChannelOne_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(dsel, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.diagSelCh1());
}

TEST_F(Hss_Test, diagSelectChannelOne_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(dsel, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.diagSelCh1());
}

TEST_F(Hss_Test, diagSelectChannelOne_not_init)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.diagSelCh1());
}

TEST_F(Hss_Test, diagReset_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, delayMilli(100))
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(in, enable())
    .Times(1)
    .WillOnce(Return(OK));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(OK, hss.diagReset());
}

TEST_F(Hss_Test, diagReset_fail)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(in, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(timer, delayMilli(100))
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INTF_ERROR, hss.diagReset());
}

TEST_F(Hss_Test, diagReset_not_init)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(INIT_ERROR, hss.diagReset());
}

TEST_F(Hss_Test, getSwitchStatus_init)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(INITED, hss.getSwitchStatus());
}

TEST_F(Hss_Test, getSwitchStatus_uninit)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(UNINITED, hss.getSwitchStatus());
}

TEST_F(Hss_Test, getSwitchStatus_power_on)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enable();

    ASSERT_EQ(POWER_ON, hss.getSwitchStatus());
}

TEST_F(Hss_Test, getSwitchStatus_power_off)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.disable();

    ASSERT_EQ(POWER_OFF, hss.getSwitchStatus());
}

TEST_F(Hss_Test, readIs_value)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    EXPECT_CALL(timer, delayMilli(1))
    .Times(1);

    EXPECT_CALL(is, ADCRead())
    .Times(1)
    .WillOnce(Return(2000));

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enable();
    hss.enableDiag();

    ASSERT_EQ(2000, hss.readIs());
}

TEST_F(Hss_Test, readIs_not_init)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);

    ASSERT_EQ(0, hss.readIs());
}

TEST_F(Hss_Test, calibrateIs_success)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_FLOAT_EQ(2.4, hss.calibrateIs(20, 100, 0, 1.2));
}

TEST_F(Hss_Test, diagRead_not_enabled)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();

    ASSERT_EQ(NOT_ENABLED, hss.diagRead(2.0, 5));
}

TEST_F(Hss_Test, diagRead_overload)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enableDiag();

    ASSERT_EQ(OVERLOAD, hss.diagRead(2.0, 5));
}

TEST_F(Hss_Test, diagRead_open_load)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enableDiag();

    ASSERT_EQ(OPEN_LOAD, hss.diagRead(0.5, 40000));
}

TEST_F(Hss_Test, diagRead_normal)
{
    NiceMock<MockADC> is;
    NiceMock<MockGPIO> den;
    NiceMock<MockGPIO> in;
    NiceMock<MockGPIO> dsel;
    NiceMock<MockTimer> timer;

    Hss hss(&den, &in, &dsel, &is, &timer);
    hss.init();
    hss.enableDiag();

    ASSERT_EQ(NORMAL, hss.diagRead(0.78, 200));
}