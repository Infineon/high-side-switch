/**
 * @file        BTS700x-hss-advanced.ino
 * @brief       High-Side-Switch Advanced Example for Profet 12V BTS700x Arduino form factored shields
 * @details     This example shows the usage of all the offered functionalities of the shield. 
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
 *             You can configure following variants for this shield:
 *              - BTS7002
 *              - BTS7004
 *              - BTS7006
 *              - BTS7008
 *  
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 *
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
    Serial.println("*** Part A: Single switch operation ***");

    /** Perform single switch operation for all switches one after the other */
    for (int switch_count = 1; switch_count <=4; switch_count++)
    {
        /** Turn on the selected channel */
        Serial.println("\n--> Turning on switch : ");
        Serial.println(switch_count);
        HSS.switchHxOn(switch_count);

        /** Get switch related params like current, diagnosis output while it is in 'ON' state */
        getSwitchParams(switch_count);

        /** Keep switch on for a second */
        delay(1000);

        /** Turn off the selected channel */
        Serial.print("--> Turning off switch : ");
        Serial.println(switch_count);
        HSS.switchHxOff(switch_count);

        /** Get switch related params like current, diagnosis output while it is in 'OFF' state */
        getSwitchParams(switch_count);
        
        /** Keep switch off for a second */
        delay(1000);
    }
    
    Serial.println("*** Part B: Multiple switch operation ***");
    
    /** Turn on all 4 switches parallelly */
    Serial.println("--> Turning on all switches at once!");
    HSS.switchesHxOn(1,1,1,1);

    /** Keep all switches on for a second */
    delay(1000);

    /** Turn off all 4 switches parallelly */
    Serial.println("--> Turning off all switches at once!");
    HSS.switchesHxOff(1,1,1,1);

    /** Keep all switches off for a second */
    delay(1000);
}

/**
 * @brief       Perform switch related functionalities
 * @details     This function is going to perform the following:
 *              - Read current through the selected switch
 *              - Perform diagnosis 
 *              - Read the battery voltage
 * @param[in]   switch_no   Switch No.
 */
void getSwitchParams(int switch_no)
{
    Serial.println("Reading the current, battery voltage and diagnosis status of switch ...");
    /** Read current value */
    readCurrent(switch_no);
    /** Get diagnosis result */
    readDiagnosis(switch_no);
    /** Read battery voltage */
    readBatteryVoltage();
}


/**
 * @brief       Read current flowing through the switch
 * @param   switch_no  Switch number 
 */
void readCurrent(int switch_no)
{
    float readAmps = 0.0;
    readAmps = HSS.readIsx(switch_no);
    Serial.print("Current flowing through the switch: ");
    Serial.print(readAmps);
    Serial.println(" A");
    return;
}

/**
 * @brief       Read diagnosis status of the switch
 * @param   switch_no  Switch number 
 */
void readDiagnosis(int switch_no)
{
    int switchStatus = HSS.readDiagx(switch_no);
    if(switchStatus & OPEN_LOAD)
    {
        Serial.println("Openload detected!");
    }
    if(switchStatus & OVERLOAD)
    {
        Serial.println("Overload detected!");
    }
    if(switchStatus & SHORT_TO_VSS)
    {
        Serial.println("Short circuit to Vss detected!");
    }
    if(switchStatus & SHORT_TO_GND)
    {
        Serial.println("Short circuit to ground detected!");
    }
    if(switchStatus & NORMAL)
    {
        Serial.println("Normal operation!");
    }
    return;
}

/**
 * @brief       Reads the current battery voltage
 */
void readBatteryVoltage()
{
    float batteryVoltage = 0.0;
    batteryVoltage = HSS.readVss();
    Serial.print("Current battery voltage : ");
    Serial.print(batteryVoltage);
    Serial.println(" V");
    return;
}