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
 * @brief   Structure for the differen types of the BTS700x
 *          It contains all important parameters for the correct usage of
 *          of the diagnosis functions of the Switch
 */
typedef struct
{
    const uint16_t kilis;
    float ampsGain;
    float ampsOffset;
    float vBatGain;
    float vBatOffset;
}BtsVariants_t;

extern BtsVariants_t BTS7002;
extern BtsVariants_t BTS7004;
extern BtsVariants_t BTS7006;
extern BtsVariants_t BTS7008;

#endif /** VARIANTS_HPP_ **/
