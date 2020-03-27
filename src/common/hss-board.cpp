#include "hss-board.h"

HssBoard::HssBoard()
{

}

HssBoard::~HssBoard()
{

}

HssBoard::Error_t HssBoard::init()
{

}

HssBoard::Error_t HssBoard::switchHxOn(uint8_t x)
{
    switch (x)
    {
        case 1:
            in1->enable();
            break;
        case 2:
            in2->enable();
            break;
        case 3:
            in3->enable();
            break;
        case 4:
            in4->enable();
            break;
    }
    return OK;
}

HssBoard::Error_t HssBoard::switchHxOff(uint8_t x)
{
    switch (x)
    {
        case 1:
            in1->disable();
            break;
        case 2:
            in2->disable();
            break;
        case 3:
            in3->disable();
            break;
        case 4:
            in4->disable();
            break;
    }
    return OK;
}

// HssBoard::Error_t HssBoard::enableDiag1_3()
// {
//     den1_den3->enable();
//     return OK;
// }

// HssBoard::Error_t HssBoard::enableDiag2_4()
// {
//     den2_den4->enable();
//     return OK;
// }

HssBoard::DiagStatus_t HssBoard::readIsx(uint8_t x)
{
    uint16_t result;

    switch (x)
    {
        case 1:
            den1_den3->enable();
            result = is1_is2->ADCRead();
            den1_den3->disable();
            break;
        
        case 2:
            den2_den4->enable();
            result = is1_is2->ADCRead();
            den2_den4->enable();
            break;
        
        case 3:
            den1_den3->enable();
            result = is3_is4->ADCRead();
            den1_den3->disable;
            break;

        case 4:
            den2_den4->enable();
            result = is3_is4->ADCRead();
            den2_den4->disable();
            break;
    }

    //depending on the ADC value the Diagstatus have to change
    //for now we just return NOMRAL
    // if(result ...)
    return NORMAL;
}

HssBoard::Error_t HssBoard::ledxOn(uint8_t x)
{
    switch (x)
    {
        case 1:
            led1->enable();
            break;

        case 2:
            led2->enable();
            break;
        
        case 3:
            led3->enable();
            break;
        
        case 4:
            led4->enable();
            break;
    }

    return OK;
}




