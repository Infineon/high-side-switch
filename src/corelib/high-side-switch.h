/** 
 * @file        high-side-switch.h
 * @brief       ####
 * @date        February 2020
 * @copyright   Copyright (c) 2020 Infineon Technologies AG
 */

#ifndef HIGH_SIDE_SWITCH_H_
#define HIGH_SIDE_SWITCH_H_

// #include "library-types.h"
// #include "library-pal.h"

// void                Library_Config         (Library_Handle_t      *handle);
// Library_Error_t     Library_Init           (Library_Handle_t      *handle);
// Library_Error_t     Library_Deinit         (Library_Handle_t      *handle);
// Library_Error_t     Library_SomeFunction   (Library_Handle_t      *handle);

class HighSideSwitch
{
    public:
        int begin();
        int end();
};

#endif /** HIGH_SIDE_SWITCH_H_ **/