/**
 * @file        hss-board-arduino.hpp
 * @brief       Definition of the High-Side-Switch-Board class in Arduino
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_BOARD_ARDUINO_HPP_
#define HSS_BOARD_ARDUINO_HPP_

#include "hss-board.hpp"
#include "hss-arduino.hpp"
#include "config.hpp"

/**
 * @brief Arduino Class of the High-Side-Switch-Board
 *
 */
class HssBoardIno : public HssBoard
{
    public:

    HssBoardIno(BtsVariants_t *variantSel);
    HssBoardIno(BtsVariants_t *variantSel, hardwareconfig_t config);
    ~HssBoardIno();
};

#endif /** HSS_BOARD_ARDUINO_HPP_ **/