/**
 * @file        BTS-hss-single-ch.ino
 * @brief       High-Side-Switch Basic Example for the Arduino form factored shields
 * @details     This example demonstrates how to switch on/off single channel in thr BTT shield. It also 
 *              calls API to read the current value.
 *    
 *              Find below the Profet 24V shield part details and its offered channels: 
 *              _________________________________________________________________________________
 *                  Shield Name            Included parts          Supported number of channels
 *              _________________________________________________________________________________
 *               24V_SHIELD_BTT6030    Profet 0 (BTT6030-2ERA)                2         
 *                                     Profet 1 (BTT6030-2ERA)                2                                 
 *                                     Profet 2 (BTT6020-1ERA)                1                          
 *              _________________________________________________________________________________
 * 
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-profet24v-ino.hpp>

/* Create an object of the shield with High-side-switch by passing the correct variant name.
   With this constructor invoking, all the mandatory configurations for the shield are done
   and hence it is important you pass the correct variant name.
*/
Profet24VBTTShieldIno HSS = Profet24VBTTShieldIno();

int channel = 2;

Error_t err = OK;
int incomingSerial = 0;

void setup()
{
    /** Serial initialization */
    Serial.begin(115200);
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

    /** Turn on the selected channel */
    Serial.println("\nTurning on selected switch...");
    HSS.switchHxOn(channel);
    delay(25);
    Serial.print("Switched Channel ");
    Serial.print(channel);
    Serial.println(" on");
}

void loop()
{
    /** Read current value continuously */
    readCurrent();

    /** Press 'enter' to switch off all channels */
    if(Serial.available() > 0)
    {
        incomingSerial = Serial.read();
        if(incomingSerial == 13)
        {
            Serial.println("\nTurning off the selected switch");
            HSS.switchHxOff(channel);
        }
        else 
            Serial.println("Invalid input");
    }
    else
        Serial.println(" To turn off the selected switch, press 'enter'. ");
}

/**
 * @brief       Read current flowing through the switch
 */
void readCurrent()
{
    float readAmps = 0.0;
    readAmps = HSS.readIsx(channel);
    Serial.print("Current flowing through the switch: ");
    Serial.print(readAmps);Serial.println(" A");
    return;
}