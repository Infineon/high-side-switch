/**
 * @file        hss-bts700xShield-ino.hpp
 * @details     Class for BTS700x-1EPP (12V) Shield
 */

#ifndef HSS_SHIELD_BTS700X_INO_HPP_
#define HSS_SHIELD_BTS700X_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-bts700x.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

/** 
 * @class    Bts700xShieldIno
 * @details  Bts700xShield Wrapper Class Declaration
*/

class Bts700xShieldIno : public Bts700xShield
{
    public:
                        Bts700xShieldIno(BtxVariants_t *variantSel);
                        Bts700xShieldIno(BtxVariants_t *variantSel, Bts700xHwConfig_t config);
                        ~Bts700xShieldIno();
};

#endif /** HSS_SHIELD_BTS700X_INO_HPP_ **/