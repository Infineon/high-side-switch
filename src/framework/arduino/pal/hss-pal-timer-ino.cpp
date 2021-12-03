/**
 * @file        hss-pal-timer-ino.cpp
 * @details     Arduino Timer Platform Abstraction Layer
 */

#include <Arduino.h>
#include "hss-pal-timer-ino.hpp"

/**
 * @brief Constructor of the Arduino Timer class
 *
 */
TimerIno::TimerIno()
{

}

/**
 * @brief Destructor of the Arduino Timer class
 *
 */
TimerIno::~TimerIno()
{

}

/**
 * @brief   Initialization of the Timer
 * @details This function is initializing the Timer and sets
 *          the elapsed time to zero.
 * @return  Error_t
 */
Error_t TimerIno::init()
{
    startTime = 0;
    return OK;
}

/**
 * @brief   Deinitialize the Timer
 * @details This function deinitialize the Timer and also
 *          resets the elapsed time variable.
 * @return  Error_t
 */
Error_t TimerIno::deinit()
{
    startTime = 0;
    return OK;
}

/**
 * @brief   Start the timer
 * @details This function is starting the timer.
 * @return  Error_t
 */
Error_t TimerIno::start()
{
    startTime = millis();
    return OK;
}

/**
 * @brief   Calculate the elapsed time
 * @details This function is calculating the elapsed time since the
 *          start of the timer. The value stored in the given variable
 *          is in milliseconds.
 * @param[in]   &elapsed      Address of a value where the elapsed time should be stored
 * @return  Error_t
 */
Error_t TimerIno::elapsed(uint32_t &elapsed)
{
    elapsed = millis() - startTime;
    return OK;
}

/**
 * @brief   Stop the timer
 * @details This function stops the timer and resets the
 *          start time variable.
 * @return  Error_t
 */
Error_t TimerIno::stop()
{
    startTime = 0;
    return OK;
}

/**
 * @brief   Time delay
 * @details This function is causing a desired delay of the application.
 *          The input value is given in milliseconds.
 * @param[in]   timeout                 Desired timeout in ms
 * @return  Error_t
 */
Error_t TimerIno::delayMilli(uint32_t timeout)
{
    delay(timeout);
    return OK;
}

/**
 * @brief   Time delay
 * @details This function is causing a desired delay of the application.
 *          The input value is given in microseconds.
 * @param[in]   timeout                 Desired timeout in us
 * @return  Error_t
 */
Error_t TimerIno::delayMicro(uint32_t timeout)
{
    delayMicroseconds(timeout);
    return OK;
}

