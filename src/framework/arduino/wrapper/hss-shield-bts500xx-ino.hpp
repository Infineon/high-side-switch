/**
 * @file        hss-bts500xxShield.hpp
 * @details     Class for BTS500xx-1EPP (12V) Shield
 */

#ifndef HSS_SHIELD_BTS500XX_INO_HPP_
#define HSS_SHIELD_BTS500XX_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-bts500xx.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

/** 
 * @class    Bts500xxShieldIno
 * @details  Bts500xxShield Wrapper Class Declaration
*/
class Bts500xxShieldIno : public Bts500xxShield
{
    public:
                        Bts500xxShieldIno(BtxVariants_t *variantSel);
                        Bts500xxShieldIno(BtxVariants_t *variantSel, BTS500xxHwConfig_t config);
                        ~Bts500xxShieldIno();

};

#endif /** HSS_SHIELD_BTS500XX_INO_HPP_ **/
