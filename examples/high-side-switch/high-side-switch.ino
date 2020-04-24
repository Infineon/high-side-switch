#include <Arduino.h>
#include <stdint.h>
#include <hss-board-arduino.h>

HssBoardIno hssTest = HssBoardIno(&BTS7002);

void setup()
{
    Serial.begin(115200);
    delay(2000);
    Serial.println("Serial initialized");
    hssTest.init();
    delay(2000);
}

void loop()
{
    hssTest.switchesHxOn(1);
    Serial.print("Supply Voltage: ");
    Serial.println(hssTest.readVss());
    Serial.println("Diagnosis status = ");
    Serial.println(hssTest.readDiagx(1));
    Serial.println("Check raw ADC current value = ");
    Serial.println(hssTest.readIsx(1));
    delay(2000);
}