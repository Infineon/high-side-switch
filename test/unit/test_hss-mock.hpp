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

using namespace hss;

class MockADC : public ADCPAL
{
    public:
        MOCK_METHOD(Error_t, init, (), (override));
        MOCK_METHOD(Error_t, deinit, (), (override));
        MOCK_METHOD(Error_t, enable, (), (override));
        MOCK_METHOD(Error_t, disable, (), (override));
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
