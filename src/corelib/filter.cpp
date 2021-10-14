/** 
 * @file        filter.cpp
 * @brief       Definition of the filter class functions
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "filter.hpp"

ExponentialFilter::ExponentialFilter()
{
    this->y = 0.0;
    this->y_last = 0.0;
    this->x = 0.0;
    this->tau = 1;
}

ExponentialFilter::ExponentialFilter(float y)
{
    this->y = y;
    this->y_last = y;
    this->x = y;
}

ExponentialFilter::ExponentialFilter(float y, uint16_t t)
{
    this->y = y;
    this->y_last = y;
    this->x = y;
    this->tau = pow2(t);  
}

void ExponentialFilter::setFilter(float y, uint16_t t)
{
    this->y = y;
    this->y_last = y;
    this->x = y;
    this->tau = pow2(t);
}

void ExponentialFilter::setTau(uint16_t t)
{
    this->tau = pow2(t);
}

void ExponentialFilter::setToNewValue(float y)
{
    this->y = y_last = x = y;
}

float ExponentialFilter::input(float x)
{
    y_last = y;
    this->x = x;

    y = y_last + ((x - y_last)/(float)tau);
}

float ExponentialFilter::output()
{
    return y;
}

uint16_t ExponentialFilter::pow2(uint16_t p)
{
    return 1<< p;
}

