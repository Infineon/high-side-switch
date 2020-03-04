/**
 * @file hss.h
 * @brief High-Side-Switch Abstraction Layer
 * @date March 2020
 * @copyright Copyright (c) 2019 Infineon Technologies AG
*/

#ifndef HSS_H
#define HSS_H


#include <stdlib.h>
#include <stdint.h>

/**
 * @class Hss(High-Side-Switch)
 */

class Hss
{
    public:
    /**
     * @addtogroup HssData
     * @{
     */

    /**
     * @name Error codes
     * @{
     */

    enum Error_t{
        OK = 0,             /**< No error */
        INTF_ERROR = -1,    /**< Interface error */
        CONF_ERROR = -2,    /**< Configuration error */
    };
    /** @} */

    /**
     * @name Status
     * @{
     */

    enum Status_t{
        UNINITED    = 0,    /**< Not initialized */
        INITED      = 1,    /**< Initiliazed */
        POWER_ON    = 2,    /**< Power on */
        POWER_OFF   = 3,    /**< Power off */
    };
    /** @} */

    /**
     * @name Diagnosis enabled
     * @{
     */

    enum DiagEnable_t{
        DISABLED    = 0,    /**< Disabled */
        ENABLED     = 1,    /**< Enabled */
    };
    /** @} */

    /**
     * @brief GPIO Hardware Interface
     */
    class GPIO;

    /**
     * @brief   Interrupt Handler
     */
    class Interrupt;

    /**
     * @brief ADC
     */
    class ADC;

    Hss();
    ~Hss();

    protected:


};

/**
 * @class GPIO
 */
/**
 * @addtogroup hallswitchhwi
 * @{
 */ 

class Hss::GPIO
{
    public:
    /**
     * @name Error codes
     * @{
     */
    enum Error_t{
        OK               =  0,      /**< No error */
        INIT_ERROR       = -1,      /**< Initialization error */
        READ_ERROR       = -2,      /**< Read error */
        WRITE_ERROR      = -3,      /**< Write error */
    };
    /** @} */

    /**
     * @name   Interrupt event
     * @{
     */
    enum IntEvent_t
    {
        INT_FALLING_EDGE   = 0,     /**< Interrupt on falling edge */
        INT_RISING_EDGE    = 1,     /**< Interrupt on rising edge */
    };
    /** @} */
    
    /**
     * @name    Voltage level
     * @{
     */
    enum VLevel_t
    {
        GPIO_LOW   = 0,        /**< Level low */
        GPIO_HIGH  = 1         /**< Level high */
    };        
    /** @} */      
    
    /**
     * @name    Voltage logic
     * @{
     */
    enum VLogic_t
    {
        NEGATIVE = 1,       /**< Negative logic. 0 on voltage level high, 1 on voltage low */
        POSITIVE = 2,       /**< Positive logic. 1 on voltage level high, 0 on voltage low */
    };
    /** @} */

    /**
     * @brief       Initializes the GPIO
     * @return      GPIO error code
     * @retval      OK if success
     * @retval      INIT_ERROR if initialization error
     */
    virtual Error_t        init        () = 0;
    
    /**
         * @brief       Deinitializes the GPIO
         * @return      GPIO error code
         * @retval      OK if success
         * @retval      INIT_ERROR if deinitialization error
     */
        virtual Error_t       deinit      () = 0;

    /**
     * @brief       Enables the hardware interrupt
     * @param[in]   *ptr HallSwith object pointer which holds the interrupt
     * @return      GPIO error code
     * @retval      OK if success
     * @retval      INIT_ERROR if initialization error
     */
    virtual Error_t        enableInt   (Hss *ptr) = 0;
    
    /**
     * @brief       Disables the hardware interrupt
     * @return      GPIO error code
     * @retval      OK if success
     * @retval      INIT_ERROR if disable error
     */
    virtual Error_t        disableInt  () = 0;

    /**
     * @brief       Gets the latest interrupt event 
     * @return      GPIO interrupt event
     * @retval      INT_FALLING_EDGE if falling edge event
     * @retval      INT_RISING_EDGE if rising edge event
     */
    virtual IntEvent_t     intEvent    () = 0;
    
    /**
     * @brief       Reads the GPIO voltage level
     * @return      GPIO voltage level
     * @retval      GPIO_LOW if voltage low
     * @retval      GPIO_HIGH if voltage high
     */
    virtual VLevel_t       read        () = 0;
    
    /**
     * @brief       Writes the GPIO output voltage level
     * @param[in]   level  Voltage level
     * @return      GPIO error code
     * @retval      OK if success
     * @retval      WRITE_ERROR if write error
     */
    virtual Error_t        write       (VLevel_t level) = 0;

    /**
     * @brief       Enables the GPIO output according to the GPIO logic
     *              - Low if negative
     *              - High if positive
     * @return      GPIO interrupt event
     * @retval      OK if success
     * @retval      WRITE_ERROR if write error
     */
    virtual Error_t        enable      () = 0;

    /**
     * @brief       Disables the GPIO output according to the GPIO logic
     *              - Low if positive
     *              - High if negative
     * @return      GPIO error code
     * @retval      OK if success
     * @retval      WRITE_ERROR if write error
     */
    virtual Error_t        disable     () = 0;


};
/** @} */

/**
 * @class Interrupt
 */ 
/**
 * @addtogroup hallswitchhwi
 * @{
 */ 
class Hss::Interrupt
{
    private:
        #define             GPIO_INT_PINS       4           /**< Maximum hardware interrupt signals */
        static uint8_t      idxNext;                        /**< Interrupt array allocation index*/
        static Hss          *objPtrVector[GPIO_INT_PINS];   /**< Hall switch object pointers vector */
        static void         *fnPtrVector[GPIO_INT_PINS];    /**< Hall switch interrupt function handlers vector */
        static void         int0Handler ();
        static void         int1Handler ();
        static void         int2Handler ();
        static void         int3Handler ();
    public:
        static void         *isrRegister(Hss *objPtr);
};
/** @} */

class Hss::ADC
{

};

#endif /** HSS_H **/
 