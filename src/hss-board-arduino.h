#include "common/hss-board.h"
#include "pal/arduino/config.h"
#include "pal/arduino/adc-arduino.h"
#include "pal/arduino/gpio-arduino.h"
#include "hss-arduino.h"

class HssBoardIno : public HssBoard
{
    public:

    HssBoardIno(BtsVariants_t *variantSel);
    HssBoardIno(BtsVariants_t *variantSel, hardwareconfig_t config);
    ~HssBoardIno();
};