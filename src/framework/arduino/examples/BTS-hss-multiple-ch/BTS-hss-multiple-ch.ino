/**
 * @file        BTS-hss-multiple-ch.ino
 * @brief       High-Side-Switch Multiple Channel Operation Example for the Arduino form factored shields
 * @details     This example demonstrates how to switch on/off multiple channels at once.
 *              Below are the valid chip variants for SHIELD_BTS700x-1EPP having 4 channels:
 *                  - BTS7002
 *                  - BTS7004
 *                  - BTS7006
 *                  - BTS7008 
 * 
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * 
 * @note        This example is valid only for SHIELD_BTS700x-1EPP.
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-bts700x-ino.hpp>

/** Create an object of the shield with High-side-switch by passing the correct variant name.
   With this constructor invoking, all the mandatory configurations for the shield are done
   and hence it is important you pass the correct variant name.
*/
Bts700xShieldIno HSS = Bts700xShieldIno(&BTS7002);

/** Select channels to be used parallelly (index 0 being channel 1) */
bool ch[4] = {true,true,true,true};

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
    HSS.switchesHxOn(ch[0],ch[1],ch[2],ch[3]);
    
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
            HSS.switchesHxOff(ch[0],ch[1],ch[2],ch[3]);
        }
        else 
            Serial.println("Invalid input");
    }
    else
        Serial.println(" Selected switches are on! To turn them off, press 'enter'. ");
}