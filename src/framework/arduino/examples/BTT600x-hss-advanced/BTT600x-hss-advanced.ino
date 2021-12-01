/**
 * @file        BTT600x-hss-advanced.ino
 * @brief       High-Side-Switch Advanced Example for the Profet24V BTT600x Arduino form factored shield
 * @details     This example shows the usage of the offered functionalities of the shield.
 *              It has 2 parts:
 * 
 *              1. PART A
 *              - Switches a channel ON
 *              - Reads current through the switch, battery voltage and performs diagnosis in 'ON' state
 *              - Switches the channel OFF
 *              - Reads current through the switch, battery voltage and performs diagnosis in 'OFF' state
 *              
 *              2. PART B
 *              - Switch multiple channels 'ON' at once
 *              - Switch multiple channels 'OFF' at once
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
 *
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-profet24v-ino.hpp>

Profet24VBTTShieldIno HSS = Profet24VBTTShieldIno();

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
    Serial.println("*** Part A: Single switch operation ***");

    /** Turn on Profet 0 - channel 0, get current value and perform diagnosis and then turn it off */
    Serial.println("\n--> Turning on Profet 0 - channel 0 (OUT0.0)");
    singleSwOperation(0);
    Serial.println("Turning off Profet 0 - channel 0 (OUT0.0) ");

    /** Turn on Profet 0 - channel 1, get current value and perform diagnosis and then turn it off */
    Serial.println("--> Turning on Profet 0 - channel 1 (OUT0.1)");
    singleSwOperation(1);
    Serial.println("Turning off Profet 0 - channel 1 (OUT0.1) ");

    /** Turn on Profet 1 - channel 0, get current value and perform diagnosis and then turn it off */
    Serial.println("--> Turning on Profet 1 - channel 0 (OUT1.0)");
    singleSwOperation(2);
    Serial.println("Turning off Profet 1 - channel 0 (OUT1.0) ");

    /** Turn on Profet 1 - channel 1, get current value and perform diagnosis and then turn it off */
    Serial.println("--> Turning on Profet 1 - channel 1 (OUT1.1)");
    singleSwOperation(3);
    Serial.println("Turning off Profet 1 - channel 1 (OUT1.1) ");

    /** Turn on Profet 2, get current value and perform diagnosis and then turn it off */
    Serial.println("--> Turning on Profet 2 (OUT2)");
    singleSwOperation(4);
    Serial.println("Turning off Profet 2 (OUT2) ");

    Serial.println("*** Part B: Multiple switch operation ***");
    
    /** Turn on all 5 switches parallelly */
    Serial.println("\n--> Turning on all switches at once!");
    HSS.switchesHxOn(1,1,1,1,1);

    /** Keep all switches on for a second */
    delay(1000);

    /** Turn off all 5 switches parallelly */
    Serial.println("--> Turning off all switches at once!");
    HSS.switchesHxOff(1,1,1,1,1);

    /** Keep all switches off for a second */
    delay(1000);
}

/**
 * @brief       Perform switching related operations on single channel
 * @details     This function is going to perform the following:
 *              - Switch on the selected channel
 *              - Read current through the selected switch
 *              - Perform diagnosis 
 *              - Switch off the selected channel
 * @param[in]   switch_no   Switch No.
 */
void singleSwOperation(int switch_no)
{
    float readAmps = 0.0;

    /** Turn on the selected channel */
    HSS.switchHxOn(switch_no);

    /** Read current value */
    readAmps = HSS.readIsx(switch_no);
    Serial.print("Current flowing through the switch: ");
    Serial.print(readAmps);
    Serial.println(" A");

    /** Get diagnosis result */
    int switchStatus = HSS.readDiagx(switch_no);
    if(switchStatus & OPEN_LOAD)
    {
        Serial.println("Openload detected!");
    }
    if(switchStatus & OVERLOAD)
    {
        Serial.println("Overload detected!");
    }
    if(switchStatus & NORMAL)
    {
        Serial.println("Normal operation!");
    }

    /** Keep switch on for a second */
    delay(1000);

    /** Turn off the selected channel */
    HSS.switchHxOff(switch_no);
}