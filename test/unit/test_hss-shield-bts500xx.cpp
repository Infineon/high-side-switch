#include "test_hss-mock.hpp"
#include "hss-shield-bts500xx.hpp"

/**
 * Class C++ High-Side-Switch Power Profet 12V Class Test Suite
 */
class Bts500xxShield_Test : public ::testing::Test
{
    public:
        NiceMock<MockGPIO> den1, in1, den2, in2;
        NiceMock<MockADC> is1, is2, vs, vOut, temp;
        NiceMock<MockTimer> timer1, timer2;

        Hss * hss1;
        Hss * hss2;
        Bts500xxShield * shield;

        /**
         * Is called before every individual test is executed
         */
        void SetUp()
        {
            hss1 = new Hss(&den1, &in1, &is1, &timer1, &BTS50005_1LUA);
            hss2 = new Hss(&den2, &in2, &is2, &timer2, &BTS50010_1LUA);
            shield = new Bts500xxShield(hss1, hss2, &vs, &vOut, &temp, &BTS50005_1LUA, &BTS50010_1LUA);

            /** Init */
            ON_CALL(den1, init())
            .WillByDefault(Return(OK));

            ON_CALL(in1, init())
            .WillByDefault(Return(OK));

            ON_CALL(is1, init())
            .WillByDefault(Return(OK));

            ON_CALL(timer1, init())
            .WillByDefault(Return(OK));

            ON_CALL(den2, init())
            .WillByDefault(Return(OK));

            ON_CALL(in2, init())
            .WillByDefault(Return(OK));

            ON_CALL(is2, init())
            .WillByDefault(Return(OK));

            ON_CALL(timer2, init())
            .WillByDefault(Return(OK));

            /** De-Init */
            ON_CALL(den1, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(in1, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(is1, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(timer1, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(den2, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(in2, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(is2, deinit())
            .WillByDefault(Return(OK));

            ON_CALL(timer2, deinit())
            .WillByDefault(Return(OK));

        }

        /**
         * Is called after every individual test was executed
         */
        void TearDown()
        {
            delete hss1;
            delete hss2;
            delete shield;
        }
};

/**
 * init()
 */
TEST_F(Bts500xxShield_Test, inti_Error_den1)
{
    EXPECT_CALL(den1, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_den2)
{
    EXPECT_CALL(den2, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_in1)
{
    EXPECT_CALL(in1, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_in2)
{
    EXPECT_CALL(in2, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_is1)
{
    EXPECT_CALL(is1, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_is2)
{
    EXPECT_CALL(is2, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_timer1)
{
    EXPECT_CALL(timer1, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Error_timer2)
{
    EXPECT_CALL(timer2, init())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->init());
}

TEST_F(Bts500xxShield_Test, inti_Nullptr_Error1)
{
    Bts500xxShield shield2(nullptr, hss2, &vs, &vOut, &temp, &BTS50005_1LUA, &BTS50010_1LUA);

    ASSERT_EQ(NULLPTR_ERROR, shield2.init());
}

TEST_F(Bts500xxShield_Test, inti_Nullptr_Error2)
{
    Bts500xxShield shield2(hss1, nullptr, &vs, &vOut, &temp, &BTS50005_1LUA, &BTS50010_1LUA);

    ASSERT_EQ(NULLPTR_ERROR, shield2.init());
}

TEST_F(Bts500xxShield_Test, inti_Nullptr_Error3)
{
    Bts500xxShield shield2(hss1, hss2, &vs, &vOut, &temp, nullptr, &BTS50010_1LUA);

    ASSERT_EQ(NULLPTR_ERROR, shield2.init());
}

TEST_F(Bts500xxShield_Test, inti_Nullptr_Error4)
{
    Bts500xxShield shield2(hss1, hss2, &vs, &vOut, &temp, &BTS50005_1LUA, nullptr);

    ASSERT_EQ(NULLPTR_ERROR, shield2.init());
}

TEST_F(Bts500xxShield_Test, inti_Success)
{
    ASSERT_EQ(OK, shield->init());
}

/**
 * deinit()
 */
TEST_F(Bts500xxShield_Test, deinti_Error_den1)
{
    EXPECT_CALL(den1, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_den2)
{
    EXPECT_CALL(den2, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_in1)
{
    EXPECT_CALL(in1, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_in2)
{
    EXPECT_CALL(in2, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_is1)
{
    EXPECT_CALL(is1, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_is2)
{
    EXPECT_CALL(is2, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_timer1)
{
    EXPECT_CALL(timer1, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Error_timer2)
{
    EXPECT_CALL(timer2, deinit())
    .WillOnce(Return(INTF_ERROR));

    ASSERT_EQ(INTF_ERROR, shield->deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Nullptr_Error1)
{
    Bts500xxShield shield2(nullptr, hss2, &vs, &vOut, &temp, &BTS50005_1LUA, &BTS50010_1LUA);

    ASSERT_EQ(NULLPTR_ERROR, shield2.deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Nullptr_Error2)
{
    Bts500xxShield shield2(hss1, nullptr, &vs, &vOut, &temp, &BTS50005_1LUA, &BTS50010_1LUA);

    ASSERT_EQ(NULLPTR_ERROR, shield2.deinit());
}

TEST_F(Bts500xxShield_Test, deinti_Success)
{
    ASSERT_EQ(OK, shield->deinit());
}

/**
 * switchHxOn(Switch_t x)
 */
TEST_F(Bts500xxShield_Test, switchHxOn_Out_Of_Boundaries_Error)
{
    shield->init();
    ASSERT_EQ(INVALID_CH_ERROR, shield->switchHxOn(3));
}

TEST_F(Bts500xxShield_Test, switchHxOn_Enable_Error)
{
    EXPECT_CALL(in1, enable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchHxOn(1));
}

TEST_F(Bts500xxShield_Test, switchHxOn_Enable_Error2)
{
    EXPECT_CALL(in2, enable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchHxOn(2));
}

TEST_F(Bts500xxShield_Test, switchHxOn_Enable_Success1)
{
    EXPECT_CALL(in1, enable())
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchHxOn(1));
}

TEST_F(Bts500xxShield_Test, switchHxOn_Enable_Success2)
{
    EXPECT_CALL(in2, enable())
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchHxOn(2));
}

/**
 * switchHxOff(uint8_t x)
 */
TEST_F(Bts500xxShield_Test, switchHxOff_Out_Of_Boundaries_Error)
{
    shield->init();
    ASSERT_EQ(INVALID_CH_ERROR, shield->switchHxOff(3));
}

TEST_F(Bts500xxShield_Test, switchHxOff_Disable_Error)
{
    EXPECT_CALL(in1, disable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchHxOff(1));
}

TEST_F(Bts500xxShield_Test, switchHxOff_Disable_Error2)
{
    EXPECT_CALL(in2, disable())
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchHxOff(2));
}

TEST_F(Bts500xxShield_Test, switchHxOff_Disable_Success1)
{
    EXPECT_CALL(in1, disable())
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchHxOff(1));
}

TEST_F(Bts500xxShield_Test, switchHxOff_Disable_Success2)
{
    EXPECT_CALL(in2, disable())
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchHxOff(2));
}

/**
 * readDiagx(uint8_t x)
 */
TEST_F(Bts500xxShield_Test, readDiagx_Out_Of_Boundaries)
{
    shield->init();
    ASSERT_EQ(DIAG_READ_ERROR, shield->readDiagx(10));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_Off_Short_To_Vss)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillOnce(Return(662));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    shield->init();
    shield->switchHxOff(1);
    ASSERT_EQ(SHORT_TO_VSS, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_Off_Open_Load_With_Issfault)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillOnce(Return(662));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(60));

    shield->init();
    shield->switchHxOff(1);
    ASSERT_EQ(OPEN_LOAD, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_Off_Open_Load_Without_Issfault)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillRepeatedly(Return(330));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(2)
    .WillRepeatedly(Return(11));

    shield->init();
    shield->switchHxOff(1);

    ASSERT_NEAR(1.0, shield->readVOut(), 0.1);
    ASSERT_EQ(OPEN_LOAD, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_On_Short_To_GND_Or_Ot)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillOnce(Return(662));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(11));

    shield->init();
    shield->switchHxOn(1);
    ASSERT_EQ(SHORT_TO_GND_OR_OT, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_On_Open_Load)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillOnce(Return(2));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(11));

    shield->init();
    shield->switchHxOn(1);
    ASSERT_EQ(OPEN_LOAD, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch1_On_Normal)
{
    EXPECT_CALL(den1, enable())
    .Times(1);

    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is1, ADCRead())
    .Times(1)
    .WillOnce(Return(10));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(120));

    shield->init();
    shield->switchHxOn(1);
    ASSERT_EQ(NORMAL, shield->readDiagx(1));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch2_Off_Fault)
{
    EXPECT_CALL(den2, enable())
    .Times(1);

    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is2, ADCRead())
    .Times(1)
    .WillOnce(Return(662));

    shield->init();
    shield->switchHxOff(2);
    ASSERT_EQ(FAULT, shield->readDiagx(2));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch2_On_Fault)
{
    EXPECT_CALL(den2, enable())
    .Times(1);

    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is2, ADCRead())
    .Times(1)
    .WillOnce(Return(662));

    shield->init();
    shield->switchHxOn(2);
    ASSERT_EQ(SHORT_TO_GND_OR_OT, shield->readDiagx(2));
}

TEST_F(Bts500xxShield_Test, readDiagx_Switch2_On_Open_Load)
{
    EXPECT_CALL(den2, enable())
    .Times(1);

    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(is2, ADCRead())
    .Times(1)
    .WillOnce(Return(0));

    shield->init();
    shield->switchHxOn(2);
    ASSERT_EQ(OPEN_LOAD, shield->readDiagx(2));
}

/**
 * readIsx(uint8_t x)
 */
TEST_F(Bts500xxShield_Test, readIsx_Out_Of_Boundaries_Error)
{
    shield->init();
    ASSERT_FLOAT_EQ(-1.2345, shield->readIsx(3));

}

TEST_F(Bts500xxShield_Test, readIsx_1)
{
    EXPECT_CALL(den1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_FLOAT_EQ(0.0, shield->readIsx(1));
}

TEST_F(Bts500xxShield_Test, readIsx_2)
{
    EXPECT_CALL(den2, enable())
    .Times(1)
    .WillOnce(Return(OK));

    EXPECT_CALL(den2, disable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_FLOAT_EQ(0.0, shield->readIsx(2));
}

/**
 * switchesHxOn(bool h1, bool h2)
 */
TEST_F(Bts500xxShield_Test, switchesHxOn_Error1)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchesHxOn(true, true));
}

TEST_F(Bts500xxShield_Test, switchesHxOn_Error2)
{
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchesHxOn(true, true));
}

TEST_F(Bts500xxShield_Test, switchesHxOn_One_Switch_Success1)
{
    EXPECT_CALL(in1, enable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchesHxOn(true, false));
}

TEST_F(Bts500xxShield_Test, switchesHxOn_One_Switch_Success2)
{
    EXPECT_CALL(in2, enable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchesHxOn(false, true));
}

/**
 * switchesHxOff(bool h1, bool h2)
 */
TEST_F(Bts500xxShield_Test, switchesHxOff_Error1)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchesHxOff(true, true));
}

TEST_F(Bts500xxShield_Test, switchesHxOff_Error2)
{
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(INTF_ERROR));

    shield->init();
    ASSERT_EQ(INTF_ERROR, shield->switchesHxOff(true, true));
}

TEST_F(Bts500xxShield_Test, switchesHxOff_One_Switch_Success1)
{
    EXPECT_CALL(in1, disable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchesHxOff(true, false));
}

TEST_F(Bts500xxShield_Test, switchesHxOff_One_Switch_Success2)
{
    EXPECT_CALL(in2, disable())
    .Times(1)
    .WillOnce(Return(OK));

    shield->init();
    ASSERT_EQ(OK, shield->switchesHxOff(false, true));
}

/**
 * readVs()
 */
TEST_F(Bts500xxShield_Test, readVs_Success)
{
    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    shield->init();
    ASSERT_NEAR(12.02, shield->readVs(), 0.1);
}

/**
 * readVs()
 */
TEST_F(Bts500xxShield_Test, readVOut_Success)
{
    EXPECT_CALL(vOut, ADCRead())
    .Times(1)
    .WillOnce(Return(54));

    shield->init();
    ASSERT_NEAR(5.0, shield->readVOut(), 0.1);
}

/**
 * readTemperature()
 */
TEST_F(Bts500xxShield_Test, readTemperature_Success)
{
    EXPECT_CALL(temp, ADCRead())
    .Times(1)
    .WillOnce(Return(18));

    EXPECT_CALL(vs, ADCRead())
    .Times(1)
    .WillOnce(Return(131));

    shield->init();
    ASSERT_NEAR(25.0, shield->readTemperature(), 0.2);
}