#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "hss.hpp"
#include "adc.hpp"
#include "gpio.hpp"
#include "timer.hpp"


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


class MockADC : public AnalogDigitalConverter
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

class MockTimer: public Timer
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

class MockGPIO: public GPIO
{
    public:
        MOCK_METHOD(Error_t, init, (), (override));
        MOCK_METHOD(Error_t, deinit, (), (override));
        MOCK_METHOD(VLevel_t, read, (), (override));
        MOCK_METHOD(Error_t, write, (VLevel_t level), (override));
        MOCK_METHOD(Error_t, enable, (), (override));
        MOCK_METHOD(Error_t, disable, (), (override));
};