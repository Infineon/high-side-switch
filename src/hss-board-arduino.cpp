#include "hss-board-arduino.h"

HssBoardIno::HssBoardIno(BtsVariants_t *variantSel)
{
    led1 = new GPIOIno(xmc_1100_bootkit.led1, OUTPUT, GPIOIno::POSITIVE);
    led2 = new GPIOIno(xmc_1100_bootkit.led2, OUTPUT, GPIOIno::POSITIVE);
    led3 = new GPIOIno(xmc_1100_bootkit.led3, OUTPUT, GPIOIno::POSITIVE);
    led4 = new GPIOIno(xmc_1100_bootkit.led4, OUTPUT, GPIOIno::POSITIVE);

    hss1 = new HssIno(xmc_1100_bootkit.den1_den3, xmc_1100_bootkit.in1, xmc_1100_bootkit.is1_is2, variantSel);
    hss2 = new HssIno(xmc_1100_bootkit.den2_den4, xmc_1100_bootkit.in2, xmc_1100_bootkit.is1_is2, variantSel);
    hss3 = new HssIno(xmc_1100_bootkit.den1_den3, xmc_1100_bootkit.in3, xmc_1100_bootkit.is3_is4, variantSel);
    hss4 = new HssIno(xmc_1100_bootkit.den2_den4, xmc_1100_bootkit.in4, xmc_1100_bootkit.is3_is4, variantSel);
    
    oloff = new GPIOIno(xmc_1100_bootkit.oloff, OUTPUT, GPIOIno::POSITIVE);
    pushButtonDigital = new GPIOIno(xmc_1100_bootkit.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);

    pushButtonAnalog = new ADCIno(xmc_1100_bootkit.pushButtonAnalog);
    vBat = new ADCIno(xmc_1100_bootkit.vBat);
}

HssBoardIno::HssBoardIno(BtsVariants_t *variantSel, hardwareconfig_t config)
{
    led1 = new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE);
    led2 = new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE);
    led3 = new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE);
    led4 = new GPIOIno(config.led4, OUTPUT, GPIOIno::POSITIVE);

    hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2, variantSel);
    hss2 = new HssIno(config.den2_den4, config.in2, config.is1_is2, variantSel);
    hss3 = new HssIno(config.den1_den3, config.in3, config.is3_is4, variantSel);
    hss4 = new HssIno(config.den2_den4, config.in4, config.is3_is4, variantSel);

    oloff = new GPIOIno(config.oloff, OUTPUT, GPIOIno::POSITIVE);
    pushButtonDigital = new GPIOIno(config.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);
    
    pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
    vBat =  new ADCIno(config.vBat);
}

HssBoardIno::~HssBoardIno()
{
    //TODO: Find a way to properly distruct the instance
}



