/**
 * @file        hss-shield-profet24v.cpp
 * @details     Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 */
#ifndef HSS_SHIELD_PROFET24V_HPP_
#define HSS_SHIELD_PROFET24V_HPP_

#include "hss-shield.hpp"
#include "hss.hpp"
#include "hss-variants.hpp"

using namespace hss;

/**
 * @class    Profet24VBTTShield
 * @details  Class implementing HSS functionalities for Profet24VBTT Shield
 */
class Profet24VBTTShield : HssShield
{
    public:

                        Profet24VBTTShield(Hss * hsw0, Hss * hsw1, Hss * hsw2);
                        ~Profet24VBTTShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn   (uint8_t x);
        Error_t         switchHxOff  (uint8_t x);
        Error_t         switchesHxOn (bool h0_0 = false, bool h1_0 = false, bool h0_1 = false, bool h1_1 = false, bool h2 = false);
        Error_t         switchesHxOff(bool h0_0 = false, bool h1_0 = false, bool h0_1 = false, bool h1_1 = false, bool h2 = false);
        DiagStatus_t    readDiagx    (uint8_t x);
        float           readIsx      (uint8_t x);

    protected:

        static constexpr uint8_t hssNum = 3;    /**< Number of high side switches in the board */
        Hss      * switches[hssNum];

    private:

        const uint16_t  rSense = 1200;

};

#endif /** HSS_SHIELD_PROFET24V_HPP_ */