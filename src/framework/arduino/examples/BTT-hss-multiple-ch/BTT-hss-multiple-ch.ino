/**
 * @file        BTT-hss-multiple-ch.ino
 * @brief       High-Side-Switch Multiple Channel Operation Example for the Arduino form factored shields
 * @details     This example demonstrates how to switch on/off multiple channels at once.
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

/** Select channels to be used parallelly (index 0 being channel 1) */
bool ch[5] = {true,true,true,true, true};

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

    /** Turn on the selected channels */
    Serial.println("\nTurning on all switches at once!");
    HSS.switchesHxOn(ch[0], ch[1], ch[2], ch[3], ch[4]);
}

void loop()
{
    /** Press 'enter' to switch off all channels */
    if(Serial.available() > 0)
    {
        incomingSerial = Serial.read();
        if(incomingSerial == 13)
        {
            Serial.println("\nTurning off all switches at once!");
            HSS.switchesHxOff(ch[0],ch[1],ch[2],ch[3], ch[4]);
        }
        else 
            Serial.println("Invalid input");
    }
    else
        Serial.println(" Selected switches are on! To turn them off, press 'enter'. ");
}