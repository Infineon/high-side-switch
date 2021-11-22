/**
 * @file        hss-variants.hpp
 * @brief       Defines the characteristic values of the different high side switches variants
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_VARIANTS_HPP_
#define HSS_VARIANTS_HPP_

#include <stdint.h>

/**
 * @addtogroup hssConfig
 * @{
 */

/**
 * @brief   Structure for the different types of the BTS700x
 *          It contains all important parameters for the correct usage of
 *          of the diagnosis functions of the Switch
 */
struct BtsVariants_t
{
    const uint16_t kilis;       /**< Current sense ratio */
    float ampsGain;             /**< Gain factor for the current, may has to be adjusted */
    float ampsOffset;           /**< Current offset, can be used to correct the measured current */
    float vBatGain;             /**< Gain factor for the battery voltage, may has to be adjusted */
    float vBatOffset;           /**< Battery voltage offset, can be used to correct the measured battery voltage */
};

struct BttVariants_t
{
    const uint16_t kilis;       /**< Current sense ratio */
    float ampsGain;             /**< Gain factor for the current, may has to be adjusted */
    float ampsOffset;           /**< Current offset, can be used to correct the measured current */
    float vBatGain;             /**< Gain factor for the battery voltage, may has to be adjusted */
    float vBatOffset;           /**< Battery voltage offset, can be used to correct the measured battery voltage */
};

extern BtsVariants_t BTS7002;
extern BtsVariants_t BTS7004;
extern BtsVariants_t BTS7006;
extern BtsVariants_t BTS7008;

extern BttVariants_t BTT6030;
extern BttVariants_t BTT6020;

extern BtsVariants_t BTS50015;
extern BtsVariants_t BTS50010;
/** @} */

#endif /** HSS_VARIANTS_HPP_ **/