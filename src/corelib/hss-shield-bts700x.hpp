/**
 * @file        hss-shield-bts700x.hpp
 * @details     Class for BTS700x-1EPP (12V) Shield
 */

#ifndef HSS_SHIELD_BTS700x_HPP_
#define HSS_SHIELD_BTS700x_HPP_

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

/**
 * @class    Bts700xShield
 * @details  Class implementing HSS functionalities for Bts700x Shield
 */
class Bts700xShield : public HssShield
{
    public:

                        Bts700xShield(GPIOPAL *led1, GPIOPAL *led2, GPIOPAL *led3, GPIOPAL *led4, Hss *hsw1, Hss *hsw2, Hss *hsw3, Hss *hsw4, TimerPAL *timer,
                                      GPIOPAL *oloff, GPIOPAL *pushButtonDigital, ADCPAL *pushButtonAnalog, ADCPAL *vBat, BtxVariants_t* btxVariant);
                        ~Bts700xShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x);
        Error_t         switchHxOff(uint8_t x);
        Error_t         switchesHxOn(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);
        Error_t         switchesHxOff(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);

        DiagStatus_t    readDiagx(uint8_t x);

        float           readIsx(uint8_t x);
        float           readVss();

        bool            digitalReadButton();
        bool            analogReadButton();

        void            setVoltageOffset(float offset);

    protected:

        ExponentialFilter   *filterVbat;

        GPIOPAL             *led1;
        GPIOPAL             *led2;
        GPIOPAL             *led3;
        GPIOPAL             *led4;

        Hss                 *hss1;
        Hss                 *hss2;
        Hss                 *hss3;
        Hss                 *hss4;

        TimerPAL            *timer;

        GPIOPAL             *oloff;
        GPIOPAL             *pushButtonDigital;

        ADCPAL              *pushButtonAnalog;
        ADCPAL              *vBat;

        BtxVariants_t       *btxVariant;

    private:

        DiagStatus_t        diagnosisOff(float currentOn, float currentOff);

        float               vBatOffset = 0.0;
        const uint16_t      rSense = 1000;
};

#endif /** HSS_SHIELD_BTS700x_HPP_ */