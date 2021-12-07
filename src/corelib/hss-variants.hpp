/**
 * @file        hss-variants.hpp
 * @brief       High-Side-Switch Variant Specific Defines
 * @details     Defines the characteristic values of the different high side switches variants
 */

#ifndef HSS_VARIANTS_HPP_
#define HSS_VARIANTS_HPP_

#include <stdint.h>

/**
 * @addtogroup hssConfig
 * @{
 */

/**
 * @brief   Definition of the different High-Side-Switch types
 *
 */
enum HssType_t
{
    BTS700X,
    BTS5001X,
    BTT60X0
};

/**
 * @brief   Structure for the different types of the BTS700x
 * @details It contains all important parameters for the correct usage of
 *          of the diagnosis functions of the Switch
 */
struct BtxVariants_t
{
    HssType_t       type;           /**< Type of the chosen High side switch */
    const uint16_t  kilis;          /**< Current sense ratio */
    float           iisFault;       /**< Current in case of fault event */
    float           iisOl;          /**< Current in case of an open load */
    float           iisEn;          /**< Leakage current when channel is enabled */
    float           iisO;           /**< Senseoffset */
};

extern BtxVariants_t BTS7002;
extern BtxVariants_t BTS7004;
extern BtxVariants_t BTS7006;
extern BtxVariants_t BTS7008;

extern BtxVariants_t BTT6030;
extern BtxVariants_t BTT6020;

extern BtxVariants_t BTS50015;
extern BtxVariants_t BTS50010;

/** @} */

#endif /** HSS_VARIANTS_HPP_ **/