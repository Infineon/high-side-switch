/**
 * @file        hss-profet24VShield-ino.hpp
 * @brief       Profet (24V) BTT6030 Shield Implementation
 */

#ifndef HSS_SHIELD_PROFET24V_INO_HPP_
#define HSS_SHIELD_PROFET24V_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-profet24v.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

/** 
 * @class    Profet24VBTTShieldIno
 * @details  Profet24VBTTShield Wrapper Class Declaration
*/
class Profet24VBTTShieldIno : public Profet24VBTTShield
{
    public:
                        Profet24VBTTShieldIno();
                        Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config);
                        ~Profet24VBTTShieldIno();
};

#endif /** HSS_SHIELD_PROFET24V_INO_HPP_ **/