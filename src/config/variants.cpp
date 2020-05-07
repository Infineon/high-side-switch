/** 
 * @file        variants.cpp
 * @brief       Defines the characteristic values of the different BTS700x variants  
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "variants.hpp"

/**
 * @brief BTS7002.
 * Is rated for nominal 21 A and is the Profet with the highest useable power
 */
BtsVariants_t BTS7002 {
    .kilis = 22700,
    .ampsGain = 1.08,
    .ampsOffset = 0.0,
    .vBatGain = 1.045,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7002.
 * Is rated for nominal 15 A
 */
BtsVariants_t BTS7004 {
    .kilis = 20000,
    .ampsGain = 1.08,
    .ampsOffset = 0.0,
    .vBatGain = 1.045,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7006.
 * Is rated for nominal 12.5 A
 */
BtsVariants_t BTS7006 {
    .kilis = 17700,
    .ampsGain = 1.08,
    .ampsOffset = 0.0,
    .vBatGain = 1.045,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7008.
 * Is rated for nominal 11 A
 */
BtsVariants_t BTS7008 {
    .kilis = 14500,
    .ampsGain = 1.08,
    .ampsOffset = 0.0,
    .vBatGain = 1.045,
    .vBatOffset = 0.0
};


