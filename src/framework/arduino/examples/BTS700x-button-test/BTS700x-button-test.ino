/**
 * @file        BTS700x-button-test.ino
 * @brief       Button Test Example for Profet 12V BTS700x Arduino form factored Shields
 * @details     SHIELD_BTS700x-1EPP Shield has an optional user button to
 *              perform switching. This example demonstrates the use of optional user button.
 *
 *              You can configure following variants for this shield:
 *              - BTS7002
 *              - BTS7004
 *              - BTS7006
 *              - BTS7008
 *
 *             This shield supports both digital and analog read button functionality
 *             which is configurable through jumpers (Refer manual for details).
 *             ____________________________________________________
 *                Jumper being used       Read Button Functions
 *             ____________________________________________________
 *                        J2             analogReadButton(Analog)
 *                        J3             digitalReadButton(Digital)
 *             ____________________________________________________
 *
 *              In this example we use the digitalReadButton() functionality of the library
 *              to read out the VSS of the attached power supply. In case you wish to use analogReadButton()
 *              functionality, replace digitalReadButton() by analogReadButton().
 *
 * @note        Ensure always that you have right function being called in correspondance to the jumper configurations.
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-bts700x-ino.hpp>

Bts700xShieldIno HSS = Bts700xShieldIno(&BTS7002);

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

    if(HSS.digitalReadButton() && button_pressed == false){
        button_pressed = true;
        for(int i = 0; i<10; i++){
            voltage = HSS.readVss();                            // Measure more than once to make use of the internal exponential filter
        }
        Serial.print("Supply voltage is: ");
        Serial.println(voltage);
    }

    if(!HSS.digitalReadButton()){
        button_pressed = false;
    }
}