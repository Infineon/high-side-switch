/**
 * @file        hss-shield-profet24v.cpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_SHIELD_PROFET24V_HPP_
#define HSS_SHIELD_PROFET24V_HPP_

#include "hss-shield.hpp"
#include "hss.hpp"
#include "hss-variants.hpp"

using namespace hss;

class Profet24VBTTShield : HssShield
{
    public:

                        Profet24VBTTShield(Hss * hsw0, Hss * sw1, Hss * hsw2);
                        ~Profet24VBTTShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn   (uint8_t x); //Hss_Output_t OUTPUT1, OUTPUTALL
        Error_t         switchHxOff  (uint8_t x);
        Error_t         switchesHxOn (bool h0_0 = false, bool h1_0 = false, bool h0_1 = false, bool h1_1 = false, bool h2 = false);
        Error_t         switchesHxOff(bool h0_0 = false, bool h1_0 = false, bool h0_1 = false, bool h1_1 = false, bool h2 = false);
        DiagStatus_t    readDiagx    (uint8_t x);
        float           readIsx      (uint8_t x);

    protected:

        static constexpr uint8_t hssNum = 3;    /**< Number of high side switches in the baord */
        Hss      * switches[hssNum];

        float getIs(uint8_t x);

    private:

        const uint16_t ris_Ohm         = 1200;
        const float    iisFault        = 0.006;
        const float    iisOl_btt6030   = 0.000005;
        const float    iisOl_btt6020   = 0.000004;


};

#endif /** HSS_SHIELD_PROFET24V_HPP_ */