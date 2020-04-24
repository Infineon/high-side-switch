#include <stdint.h>

struct hardwareconfig_t
{
    uint8_t led1;
    uint8_t led2;
    uint8_t led3;
    uint8_t led4;

    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;

    uint8_t oloff;

    uint8_t den1_den3;
    uint8_t den2_den4;

    uint8_t pushButtonDigital;

    uint8_t pushButtonAnalog;
    uint8_t vBat;
    uint8_t is1_is2;
    uint8_t is3_is4;    
};

extern hardwareconfig_t xmc_1100_bootkit;
