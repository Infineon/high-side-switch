/**
 * @file        high-side-switch.ino
 * @brief       High-Side-Switch Example for the Arduino form factor
 *
 *              This example is showing an example how to use the optional user button.
 *              The button functionallty is not included in the main example, because the
 *              button is not populated on the board by default.
 *
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */
#include <Arduino.h>
#include <hss-board-arduino.hpp>

/**
 * Here we create an object of the High-Side-Switch-Board class with the Name HSS.
 * The constructor needs the used version of the PROFET.
 *
 * Available versions are:
 * - BTS7002
 * - BTS7004
 * - BTS7006
 * - BTS7008
 *
 * Make sure you chose the right one. Otherwise the diagnosis functions can may work incorrectly.
 */
HssBoardIno HSS = HssBoardIno(&BTS7002);

void setup()
{
    /** Serial initialization */
    Serial.begin(115200);
    delay(2000);
    Serial.println("Serial initialized");

    /** Initialization of the High-Side-Switch-Board */
    HSS.init();
    delay(1000);
    Serial.println("High-Side-Switch is initialized");
}

/**
 * In this example we're using the the digitReadButton() functionality of the library
 * to read out the VSS of the attached power supply. You can of course also use the
 * analogReadButton() function. Which one you have to use depends on the configuration
 * of your jumper. If you're using jumper J2 you have to use the analogReadButton() function.
 * If you're using jumper J3 you have to use the digitalReadButton() function.
 */
void loop()
{
    float voltage = 0.0;
    static bool button_pressed = false;                         // The flag is used to avoid printing constantly

    if(HSS.digitalReadButton() && button_pressed == false){
        button_pressed = true;
        voltage = HSS.readVss();
        Serial.print("Supply voltage is: ");
        Serial.println(voltage);
    }

    if(!HSS.digitalReadButton()){
        button_pressed = false;
    }
}