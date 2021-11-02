/**
 * @file        hss-profet24VShield.hpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_PROFET24VSHIELD_HPP_
#define HSS_PROFET24VSHIELD_HPP_

#include "hss-shield.hpp"
#include "hss.hpp"
#include "hss-variants.hpp"

using namespace hss;

class Profet24VBTTShield : HssShield
{
    public:
//
        enum BttTypes_t{
            BTT6030T = 0,
            BTT6020T = 1
        };
                        Profet24VBTTShield();
                        ~Profet24VBTTShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x, Channel_t ch);
        Error_t         switchHxOff(uint8_t x, Channel_t ch);
        Error_t         switchesHxOn(bool h1_0 = false, bool h2_0 = false, bool h1_1 = false, bool h2_1 = false, bool h2 = false);
        Error_t         switchesHxOff(bool h1_0 = false, bool h2_0 = false, bool h1_1 = false, bool h2_1 = false, bool h2 = false);
        DiagStatus_t    readDiagx(uint8_t x, Channel_t ch=NULL_CHANNEL);
        float           readIsx(uint8_t x, Channel_t ch);

    protected:

        Hss *hss0;
        Hss *hss1;
        Hss *hss2;
        Hss *hss3;
        Hss *hss4;

        TimerPAL *timer;

        uint16_t ris_Ohm = 1200;

        float           getIs(uint8_t x, Channel_t ch=NULL_CHANNEL);
        DiagStatus_t    diagRead(BttTypes_t bttType, float amps, uint16_t kilis);

};

#endif /**HSS_PROFET24VSHIELD_HPP_*/