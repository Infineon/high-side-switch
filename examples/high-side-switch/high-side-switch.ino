#include <Arduino.h>
#include <stdint.h>
#include <hss-arduino.h>

HssIno  hssTest(6, 9, A1);

void setup()
{
    Serial.begin(115200);
    delay(5000);
    Serial.println("Serial initialized");
    delay(2000);
    hssTest.init();
    delay(1000);
    hssTest.enableDiag();
}

void loop()
{
    Serial.println("Start");
    delay(2000);
    //hssTest.enable();
    delay(2000);
    Serial.println(hssTest.diagRead());
    delay(2000);
}