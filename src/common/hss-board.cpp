#include "hss-board.h"

HssBoard::HssBoard()
{
    led1 = NULL;
    led2 = NULL;
    led3 = NULL;
    led4 = NULL;

    hss1 = NULL;
    hss2 = NULL;
    hss3 = NULL;
    hss4 = NULL;

    oloff = NULL;
    pushButtonDigital = NULL;
    
    pushButtonAnalog = NULL;
    vBat = NULL;
}

HssBoard::~HssBoard()
{

}

HssBoard::Error_t HssBoard::init()
{
    led1->init();
    led2->init();
    led3->init();
    led4->init();

    hss1->init();
    hss2->init();
    hss3->init();
    hss4->init();

    oloff->init();
    pushButtonDigital->init();

    pushButtonAnalog->init();
    vBat->init();

    return OK;
}

HssBoard::Error_t HssBoard::switchHxOn(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->enable();
            led1->enable();
            break;
        
        case 2:
            hss2->enable();
            led2->enable();
            break;
        
        case 3:
            hss3->enable();
            led3->enable();
            break;
        
        case 4:
            hss4->enable();
            led4->enable();
            break;
    }
    return OK;
}

HssBoard::Error_t HssBoard::switchHxOff(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->disable();
            led1->disable();
            break;
        
        case 2:
            hss2->disable();
            led2->disable();
            break;
        
        case 3:
            hss3->disable();
            led3->disable();
            break;
        
        case 4:
            hss4->disable();
            led4->disable();
            break;
    }
    return OK;
}

HssBoard::Error_t HssBoard::switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == TRUE){
        hss1->enable();
        led1->enable();
    }

    if(h2 == TRUE){
        hss2->enable();
        led2->enable();
    }

    if(h3 == TRUE){
        hss3->enable();
        led3->enable();
    }

    if(h4 == TRUE){
        hss4->enable();
        led4->enable();
    }

    return OK;
}

HssBoard::Error_t HssBoard::switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == TRUE){
        hss1->disable();
        led1->disable();
    }

    if(h2 == TRUE){
        hss2->disable();
        led2->disable();
    }

    if(h3 == TRUE){
        hss3->disable();
        led3->disable();
    }

    if(h4 == TRUE){
        hss4->disable();
        led4->disable();
    }

    return OK;
}

float HssBoard::readIsx(uint8_t x)
{
    uint16_t result;

    switch (x)
    {
        case 1:
            hss1->enableDiag();
            result = hss1->readIs();
            hss1->disableDiag();
            break;
        
        case 2:
            hss2->enableDiag();
            result = hss2->readIs();
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            result = hss3->readIs();
            hss3->disableDiag();
            break;

        case 4:
            hss4->enableDiag();
            result = hss4->readIs();
            hss4->disableDiag();
            break;
    }
    return result;
}

HssBoard::DiagStatus_t HssBoard::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus;

    switch(x)
    {
        case 1:
            hss1->enableDiag();
            diagStatus = hss1->diagRead();
            hss1->disableDiag();
            break;

        case 2:
            hss2->enableDiag();
            diagStatus = hss2->diagRead();
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            diagStatus = hss3->diagRead();
            hss3->disableDiag();
            break;
        
        case 4:
            hss4->enableDiag();
            diagStatus = hss4->diagRead();
            hss4->disableDiag();
            break;
    }
    
    return diagStatus;
}

float HssBoard::readVss()
{
    uint16_t adcResult = 0;
    float voltage = 0.0;
    
    adcResult = vBat->ADCRead();
    voltage = adcResult * ((float)5.0/(float)4096);  // Vmax/4096 LSB = Resolution of the ADC, 57/10 = Reverse Voltage devider to get the Supplyvoltage
    voltage = (voltage - vBatOffset) * vBatGain;
    voltage = voltage * ((float)57/(float)10);

    //TODO: Include Filter

    return voltage;
}

bool HssBoard::digitalReadButton()
{
    if(pushButtonDigital->read() == GPIO::GPIO_HIGH)
    return TRUE;
    else
    return FALSE;
}

bool HssBoard::analogReadButton()
{
    uint16_t result = 0;

    result = pushButtonAnalog->ADCRead();
    if(result > 3000){
        return TRUE;
    }
    else{
        return FALSE;
    }
}




