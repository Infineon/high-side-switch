#include <Arduino.h>
#include <stdint.h>
#include "pal/arduino/hss-arduino.h"

HssIno  hssTest(6, 9, 19);

void setup()
{
    Serial.begin(115200);
    delay(5000);
    Serial.println("Serial initialized");
    delay(2000);
    hssTest.init();
}

void loop()
{
    Serial.println("Start");
    delay(5000);
    hssTest.enable();
    delay(5000);
    hssTest.disable();
    delay(5000);
}