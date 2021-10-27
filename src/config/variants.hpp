/** 
 * @file        variants.hpp
 * @brief       Defines the characteristic values of the different BTS700x variants  
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef VARIANTS_HPP_
#define VARIANTS_HPP_

#include <stdint.h>

/**
 * @addtogroup hssConfig
 * @{
 */


/**
 * @brief   Structure for the differen types of the BTS700x
 *          It contains all important parameters for the correct usage of
 *          of the diagnosis functions of the Switch
 */
typedef struct BtsVariants_t
{
    const uint16_t kilis;       /**< Current sense ratio */
    float ampsGain;             /**< Gain factor for the current, may has to be adjusted */  
    float ampsOffset;           /**< Current offset, can be used to correct the measured current */
    float vBatGain;             /**< Gain factor for the battery voltage, may has to be adjusted */
    float vBatOffset;           /**< Battery voltage offset, can be used to correct the measured battery voltage */
};

typedef struct BttVariants_t
{
    const uint16_t kilis;       /**< Current sense ratio */
};

extern BtsVariants_t BTS7002;
extern BtsVariants_t BTS7004;
extern BtsVariants_t BTS7006;
extern BtsVariants_t BTS7008;
extern BtsVariants_t BTS50015;
extern BtsVariants_t BTS50010;
/** @} */

#endif /** VARIANTS_HPP_ **/
