#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "hss.hpp"
#include "hss-pal-adc.hpp"
#include "hss-pal-gpio.hpp"
#include "hss-pal-timer.hpp"


using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;
using ::testing::DoAll;
using ::testing::SetArgReferee;
using ::testing::SetArgPointee;
using ::testing::SetArrayArgument;
using ::testing::NiceMock;
using ::testing::AtLeast;
using ::testing::AnyNumber;
using ::testing::Assign;
using ::testing::SaveArg;
using ::testing::SafeMatcherCast;
using ::testing::NotNull;


class MockADC : public ADCPAL
{
    public:
        MOCK_METHOD(Error_t, init, (), (override));
        MOCK_METHOD(Error_t, deinit, (), (override));
        MOCK_METHOD(Error_t, enable, (), (override));
        MOCK_METHOD(Error_t, disable, (), (override));
        MOCK_METHOD(Error_t, setReadResolution, (uint8_t resolution), (override));
        MOCK_METHOD(Error_t, setWriteResolution, (uint8_t resolution), (override));
        MOCK_METHOD(uint16_t, ADCRead, (), (override));
        MOCK_METHOD(Error_t, ADCWrite, (uint8_t value), (override));
};

class MockTimer: public TimerPAL
{
    public:
        MOCK_METHOD(Error_t, init, (), (override));
        MOCK_METHOD(Error_t, deinit, (), (override));
        MOCK_METHOD(Error_t, start, (), (override));
        MOCK_METHOD(Error_t, elapsed, (uint32_t &elapsed), (override));
        MOCK_METHOD(Error_t, stop, (), (override));
        MOCK_METHOD(Error_t, delayMilli, (uint32_t timeout), (override));
        MOCK_METHOD(Error_t, delayMicro, (uint32_t timeout), (override));
};

class MockGPIO: public GPIOPAL
{
    public:
        MOCK_METHOD(Error_t, init, (), (override));
        MOCK_METHOD(Error_t, deinit, (), (override));
        MOCK_METHOD(VLevel_t, read, (), (override));
        MOCK_METHOD(Error_t, write, (VLevel_t level), (override));
        MOCK_METHOD(Error_t, enable, (), (override));
        MOCK_METHOD(Error_t, disable, (), (override));
};

// class MockHss : public Hss
// {
//     public:
//     MockHss(GPIOPAL *den, GPIOPAL *in, GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer) : Hss(den, in, dsel, is, timer){};

//     MOCK_METHOD(Error_t, init, ());
//     MOCK_METHOD(Error_t, deinit, ());
//     MOCK_METHOD(Error_t, enable, ());
//     MOCK_METHOD(Error_t, disable, ());
//     MOCK_METHOD(Error_t, enableDiag, ());
//     MOCK_METHOD(Error_t, disableDiag, ());
//     MOCK_METHOD(Error_t, diagReset, ());
//     MOCK_METHOD(Status_t, getSwitchStatus, ());
//     MOCK_METHOD(DiagStatus_t, diagRead, (float amps, float iisFault, float iisOl, uint16_t kilis, Channel_t ch));
//     MOCK_METHOD(uint16_t, readIs, (Channel_t ch));
//     MOCK_METHOD(float, calibrateIs, (float inVal, uint16_t kilis, float ampsOffset, float ampsGain));
// };