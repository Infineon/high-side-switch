#include "hss.h"


class HssBoard : Hss
{
    public:

    HssBoard();
    ~HssBoard();
    Error_t init();

    Error_t switchHxOn(uint8_t x);
    Error_t switchHxOff(uint8_t x);


    // Error_t enableDiag1_3();
    // Error_t enableDiag2_4();

    Error_t disableDiag1_3();
    Error_t disableDiag2_4();

    DiagStatus_t readIsx(uint8_t x);

    Error_t ledxOn(uint8_t x);
    Error_t ledxOff(uint8_t x);


    protected:

    GPIO *led1;
    GPIO *led2;
    GPIO *led3;
    GPIO *led4;

    GPIO *in1;  //Or put them in a GPIO-Struct and call them depending on X ???
    GPIO *in2;
    GPIO *in3;
    GPIO *in4;

    GPIO *den1_den3;
    GPIO *den2_den4;

    ADC *vBat;
    ADC *is1_is2;
    ADC *is3_is4;
};