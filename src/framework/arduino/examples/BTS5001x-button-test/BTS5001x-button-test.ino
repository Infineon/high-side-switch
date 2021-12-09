/**
 * @file        BTS5001x-button-test.ino
 * @brief       Button Test Example for Profet 12V BTS5001x Arduino form factored Shields
 * @details     SHIELD_BTS5001x-1TAD Shield have optional user button to
 *              perform switching. This example demonstrates the use of optional user button.
 *
 *              You can configure following variants for this shield:
 *              - BTS50010
 *              - BTS50015
 *
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-bts5001x-ino.hpp>

Bts5001xShieldIno HSS = Bts5001xShieldIno(&BTS50015);

Error_t err = OK;

void setup()
{
    /** Serial initialization */
    Serial.begin(9600);
    Serial.println("Serial initialized");

    /** Initialization of the High-Side-Switch-Board */
    err = HSS.init();
    if(OK!=err)
    {
        Serial.println("Initialization failed!");
    }
    else
        Serial.println("Initialization successful!");

    delay(1000);
}

void loop()
{
    float voltage = 0.0;
    static bool button_pressed = false;                         // The flag is used to avoid printing constantly

    if(HSS.analogReadButton() && button_pressed == false){
        button_pressed = true;
        for(int i = 0; i<10; i++){                              // Measure more than once to make use of the internal exponential filter
            voltage = HSS.readVss();
        }
        Serial.print("Supply voltage is: ");
        Serial.println(voltage);
    }

    if(!HSS.analogReadButton()){
        button_pressed = false;
    }
}