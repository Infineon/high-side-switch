/**
 * @file        high-side-switch.ino
 * @brief       High-Side-Switch Example for the Arduino form factor
 *              
 *              This example shows the usage of the Arduino API.
 *              It covers all functions of the PROFET-Shield and shows how the functions are used.
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * 
 * @copyright   Copyright (c) 2020 Infineon Technologies AG   
 */
#include <Arduino.h>
#include <hss-bts500xxShield-ino.hpp>

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
Bts500xxShieldIno HSS = Bts500xxShieldIno(&BTS50015);

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

void loop()
{   
    /*int incomingSerial = 0;
    static int counter = 0;
    static int oldCounter = 0;

    float readAmps = 0.0;
    float batteryVoltage = 0.0;

    int switchStatus = 0;*/

    /**
     * This small if-case is checking for an user input.
     * To use this press the "+" symbol on your keyboard, this is equal to "43" in ASCII.
     */
    /*if(Serial.available() > 0){
        incomingSerial = Serial.read();

        if(incomingSerial == 43){
            counter++;
        }
    }*/

    /**
     * This if-case are used to show all functions of the board.
     * Depending on the value of the counter the board will do the following:
     *      - From 1 to 4:
     *          Switch on all four channels, one after the other starting with channel 1
     *          Also reads out the diagnostic channel of the corresponding channel
     *      - From 5 to 8:
     *          Switch off all four channels, one after the other starting with channel 1
     *          Also reads out the diagnostic channel of the corresponding channel
     *      - From 9 to 10:
     *          First turns on all channels at once
     *          Then turns off all channels at once
     *      - After that the counter will be reset and you can use the program again
     * 
     * The status of the switch can be determined with the following table:
     *      || Diagnosis Status || Description                                                      ||
     *      ------------------------------------------------------------------------------------------
     *      ||          0       || NORMAL = Everything is working correctly                         ||
     *      ||          1       || OVERLOAD = Exceeded the board's current limit                    ||
     *      ||          2       || SHORT_TO_GND = Short the ground of the board                     ||
     *      ||          3       || OVERTEMPERATURE = Board got to hot                               ||
     *      ||          4       || SHORT_TO_VSS = Short to the Battery pad of the board             ||
     *      ||          5       || OPEN_LOAD = No load is connected                                 ||
     *      ||          6       || UNDER_LOAD = Not enough voltage/current to turn on the switch    ||
     *      ||          7       || INVERSE_CURRENT = Inverse current flows into the board           ||
     * 
     * Please note: If you use the diagnosis function when the switch is off and no load is connected
     * the status will be SHORT_TO_GND, because this state is not clear because of the provided IS signal
     * of the board. Read more about this in the data sheet of the PROFET on page 40.
     */
    /*if(counter > 0 && counter < 5 && oldCounter != counter){
        HSS.switchHxOn(counter);
        Serial.print("Switched half bridge ");
        Serial.print(counter);
        Serial.println(" on");

        Serial.println("Reading the current and diagnosis status of this switch ...");
        readAmps = HSS.readIsx(counter);
        Serial.print("Current flowing through the switch: ");
        Serial.print(readAmps);Serial.println(" A");

        switchStatus = HSS.readDiagx(counter);
        Serial.print("Diagnosis status of the switch: ");
        Serial.println(switchStatus);

        batteryVoltage = HSS.readVss();
        Serial.print("Current battery voltage : ");
        Serial.print(batteryVoltage);Serial.println(" V\n");

        oldCounter = counter;
    }
    else if(counter > 4 && counter < 9 && oldCounter != counter){
        HSS.switchHxOff(counter - 4);
        Serial.print("Switched half bridge ");
        Serial.print(counter - 4);
        Serial.println(" off");

        Serial.println("Reading the current and diagnosis status of this switch ...");
        readAmps = HSS.readIsx(counter - 4);
        Serial.print("Current flowing through the switch: ");
        Serial.print(readAmps);Serial.println(" A");

        switchStatus = HSS.readDiagx(counter - 4);
        Serial.print("Diagnosis status of the switch: ");
        Serial.println(switchStatus);

        batteryVoltage = HSS.readVss();
        Serial.print("Current battery voltage : ");
        Serial.print(batteryVoltage);Serial.println(" V\n");

        oldCounter = counter;
    }
    else if(counter > 8 && counter < 11 && oldCounter != counter){
        if(counter == 9){
            Serial.println("\nTurn on all switches at once!");
            HSS.switchesHxOn(1,1,1,1);
            oldCounter = counter;
        }
        else if(counter == 10){
            Serial.println("\nTurn off all switches at once and reset counter!");
            HSS.switchesHxOff(1,1,1,1);
            oldCounter = counter;
            counter = 0;
        }
    }*/
}