/** 
 * @file        filter.hpp
 * @brief       Definition of the filter class 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef FILTER_H_
#define FILTER_H_

#include <stdint.h>

class ExponentialFilter
{
    public:

        ExponentialFilter();
        ExponentialFilter(float y);
        ExponentialFilter(float y, uint16_t t);

        void setFilter(float y, uint16_t t);
        void setTau(uint16_t t);
        void setToNewValue(float y);
        float input(float x);
        float output();
        uint16_t pow2(uint16_t p);
        
        private:
        uint16_t tau;

        float y;
        float y_last;
        float x;
};

#endif /** FILTER_H_ **/