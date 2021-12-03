/**
 * @file        hss-filter.hpp
 * @details     Definition of the filter class
 */

#ifndef HSS_FILTER_HPP_
#define HSS_FILTER_HPP_

#include <stdint.h>

/**
 * @addtogroup hssCorelib
 * @{
 */

class ExponentialFilter
{
    public:

        ExponentialFilter();
        ExponentialFilter(float y);
        ExponentialFilter(float y, uint16_t t);

        void setFilter(float y, uint16_t t);
        void setTau(uint16_t t);
        void setToNewValue(float y);
        void input(float x);
        float output();
        uint16_t pow2(uint16_t p);

        private:
        uint16_t tau;

        float y;
        float y_last;
        float x;
};

/** @} */

#endif /** FILTER_HPP_ **/