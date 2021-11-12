/**
 * @file        hss-types.hpp
 * @brief       High-Side Switch Core Types
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_TYPES_HPP_
#define HSS_TYPES_HPP_

namespace hss
{

	/**
	* @addtogroup hsscorelib
	* @{
	*/

	/**
	* @name   Error codes
	* @{
	*/
	enum Error_t
	{
		OK          	     =  0,   /**< No error */
		INTF_ERROR  	     = -1,   /**< Interface error */
		CONF_ERROR  	     = -2,   /**< Configuration error */
		READ_ERROR  	     = -3,   /**< Read error */
		WRITE_ERROR 	     = -4,   /**< Write error */
		NULLPTR_ERROR        = -5,   /**< Null pointer error */
		INVALID_CH_ERROR     = -6,   /**< Invalid channel error */
        UNSUPPORTED_OP_ERROR = -7,   /**< Invalid channel error */
        INIT_ERROR           = -8    /**< Not initialized */
	};
	/** @} */

	/**
	* @name   Channel numbers
	* @{
	*/
	enum Channel_t
	{
		CHANNEL0 	 = 0,           /**< Channel 1 : Valid for BTT shields */
		CHANNEL1 	 = 1,           /**< Channel 2 : Valid for BTT shields */
		ALL_CHANNELS = 2,           /**< Select all channels : Valid for BTT shields */
        NO_CHANNEL   = 3            /**< No channel to select */
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
        DIAG_EN      = 0,    /**< Enabled */
        DIAG_DIS     = 1,    /**< Disabled */
    };
    /** @} */

    /**
     * @name Diagnosis enabled
     * @{
     */
    enum DiagStatus_t{
        DIAG_READ_ERROR = -1,   /**< Read Error */
        NOT_ENABLED = -2,       /**< Diagnosis not enabled */
        NORMAL = 0,             /**< Switch works correctly */
        OVERLOAD = 1,           /**< Overload of the Switch */
        SHORT_TO_GND = 2,       /**< Short to the ground */
        OVERTEMPERATURE = 3,    /**< Overtemperature */
        SHORT_TO_VSS = 4,       /**< Short to the supply voltage */
        OPEN_LOAD = 5,          /**< Open load detected */
        UNDER_LOAD = 6,         /**< Under load condition */
        INVERSE_CURRENT = 7,    /**< Inverse current */
    };
    /** @} */
}

/** @} */

#endif /** HSS_TYPES_HPP_ **/