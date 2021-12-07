/**
 * @file        hss-profet24VShield-ino.cpp
 * @details     Profet (24V) BTT6030 Shield Implementation
 */

#include "hss-shield-profet24v-ino.hpp"
#include <Arduino.h>

using namespace hss;

/**
 * @brief   Profet (24V) BTT6030 Shield constructor
 * @details Initialize all protected class pointers.
 */
Profet24VBTTShieldIno::Profet24VBTTShieldIno():
Profet24VBTTShield  (
                        switches[0] = new HssIno(PROFET24VBTT_HWCONFIG.den_0, PROFET24VBTT_HWCONFIG.in0_0, PROFET24VBTT_HWCONFIG.in1_0, PROFET24VBTT_HWCONFIG.dsel_0, PROFET24VBTT_HWCONFIG.is_0, &BTT6030),
                        switches[1] = new HssIno(PROFET24VBTT_HWCONFIG.den_1, PROFET24VBTT_HWCONFIG.in0_1, PROFET24VBTT_HWCONFIG.in1_1, PROFET24VBTT_HWCONFIG.dsel_1, PROFET24VBTT_HWCONFIG.is_1, &BTT6030),
                        switches[2] = new HssIno(PROFET24VBTT_HWCONFIG.den_2, PROFET24VBTT_HWCONFIG.in0_2, PROFET24VBTT_HWCONFIG.is_2, &BTT6020)
                    )
{

}

/**
 * @brief   Profet (24V) BTT6030 Shield constructor for custom configuration
 * @details Initialize all class pointers. This constructor allows to pass custom shield configuration.
 */
Profet24VBTTShieldIno::Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config):
Profet24VBTTShield  (
                        switches[0] = new HssIno(config.den_0, config.in0_0, config.in1_0, config.dsel_0, config.is_0, &BTT6030),
                        switches[1] = new HssIno(config.den_1, config.in0_1, config.in1_1, config.dsel_1, config.is_1, &BTT6030),
                        switches[2] = new HssIno(config.den_2, config.in0_2, config.is_2, &BTT6020)
                    )
{

}

/**
 * @brief Destructor of the Profet (24V) BTT6030 Shield
 *
 */
Profet24VBTTShieldIno::~Profet24VBTTShieldIno()
{

}