#include "hss.h"

class HssBoard : Hss
{
    public:

    HssBoard();
    ~HssBoard();
    Error_t init();

    Error_t switchHxOn(uint8_t x);
    Error_t switchHxOff(uint8_t x);
    Error_t switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL);
    Error_t switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL); // replace it only with one function e.g. switchHx()????

    DiagStatus_t readDiagx(uint8_t x);
    
    float readIsx(uint8_t x);
    

    float readVss();
    bool digitalReadButton();
    bool analogReadButton();

    protected:

    GPIO *led1;
    GPIO *led2;
    GPIO *led3;
    GPIO *led4;

    Hss *hss1;
    Hss *hss2;
    Hss *hss3;
    Hss *hss4;

    GPIO *oloff;
    GPIO *pushButtonDigital;

    ADC *pushButtonAnalog;        //only if a push button is assambled
    ADC *vBat;

    const float vBatGain = 1.045;
    const float vBatOffset = 0.0;
};