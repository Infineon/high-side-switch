/**
 * @file        hss-variants.cpp
 * @brief       Defines the characteristic values of the different high side switches variants
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-variants.hpp"

/**
 * @brief BTS7002.
 * Is rated for nominal 21 A and is the Profet with the highest useable power
 */
BtxVariants_t BTS7002 {
    .kilis = 22700,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7002.
 * Is rated for nominal 15 A
 */
BtxVariants_t BTS7004 {
    .kilis = 20000,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7006.
 * Is rated for nominal 12.5 A
 */
BtxVariants_t BTS7006 {
    .kilis = 17700,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTS7008.
 * Is rated for nominal 11 A
 */
BtxVariants_t BTS7008 {
    .kilis = 14500,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};
/**
 * @brief BTS50015-1TAD.
 * Is rated for nominal 33 A
 */
BtxVariants_t BTS50015 {
    .kilis = 51500,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTS50010-1TAD.
 * Is rated for nominal 40 A
 */
BtxVariants_t BTS50010 {
    .kilis = 52100,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTT6030.
 * Is rated for nominal 5 A per channel
 */
BtxVariants_t BTT6030 {
    .kilis = 2240,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};

/**
 * @brief BTT6020.
 * Is rated for nominal 7 A
 */
BtxVariants_t BTT6020 {
    .kilis = 2950,
    .ampsOffset = 0.0,
    .vBatOffset = 0.0
};