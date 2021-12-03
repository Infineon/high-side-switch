/**
 * @file        hss-shield-bts500xx.hpp
 * @details     Class for BTS500xx (12V) Shield Implementation
 */

#ifndef HSS_SHIELD_BTS500XX_HPP_
#define HSS_SHIELD_BTS500XX_HPP_

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

/**
 * @class    Bts500xxShield
 * @details  Class implementing HSS functionalities for Bts500xx Shield
 */
class Bts500xxShield : public HssShield
{
    public:

                        Bts500xxShield(Hss * hsw1, GPIOPAL * led1, GPIOPAL * led2, ADCPAL * pushButton, ADCPAL * vBat);
                        ~Bts500xxShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x = 0);
        Error_t         switchHxOff(uint8_t x = 0);
        DiagStatus_t    readDiagx(uint8_t x = 0);

        float           readIsx(uint8_t x=1);
        float           readVss();
        bool            analogReadButton();

        void            setVoltageOffset(float offset);

    protected:

        ExponentialFilter *filterVbat;

        Hss      * hss1;
        GPIOPAL  * led1;
        GPIOPAL  * led2;
        ADCPAL   * pushButton;
        ADCPAL   * vBat;

    private:

        const uint16_t  rSense = 1000;
        float           vBatOffset = 0.0;

};

#endif /** HSS_SHIELD_BTS500XX_HPP_ */