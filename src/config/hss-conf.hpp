/**
 * @file        hss-conf.hpp
 * @details     High-Side-Switch Library Configuration
 */

#ifndef HSS_CONF_HPP_
#define HSS_CONF_HPP_

#include "hss-conf-opts.hpp"

#ifndef HSS_LOGGER_ENABLED
#define HSS_LOGGER_ENABLED    0   /**< (1) Enabled, (0) Disabled */
#endif

/**
 * @brief Enable each logger module
 */
#if (HSS_LOGGER_ENABLED == 1)
#endif

#include "hss-conf-dfl.hpp"

/** @} */

#endif /** HSS_CONF_HPP_ **/