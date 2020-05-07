/**
 * @file        high-side-switch.ino
 * @brief       High-Side-Switch Exmpale for the Arduino form factor
 *              
 *              This exmaple shows the usage of the Arduino API.
 *              It covers all functions of the PROFET-Shield and shows how the functions are used.
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * 
 * @copyright   Copyright (c) 2020 Infineon Technologies AG   
 */
#include <Arduino.h>
#include <hss-board-arduino.hpp>

/**
 * Here we create an object of the High-Side-Switch-Board class with the Name HSS.
 * The constructor needs the used version of the Profet.
 * 
 * Available verison are:
 * - BTS7002
 * - BTS7004
 * - BTS7006
 * - BTS7008
 * 
 * Make sure you chose the right one. Otherwise the diagnosis functions can may work incorrectly.
 */
HssBoardIno HSS = HssBoardIno(&BTS7002);

void setup()
{   /** Serial intitialization */
    Serial.begin(115200);
    delay(2000);
    Serial.println("Serial initialized");

    /** Initialization of the High-Side-Switch-Board */
    HSS.init();
    delay(1000);
}

void loop()
{   
    int incomingSerial = 0;
    static int counter = 0;
    static int oldCounter = 0;

    float readAmps = 0.0;
    float batteryVoltage = 0.0;

    int switchStatus = 0;

    if(Serial.available() > 0){
        incomingSerial = Serial.read();

        if(incomingSerial == 43){
            counter++;
        }
    }

    if(counter > 0 && counter < 5 && oldCounter != counter){
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
    }
}