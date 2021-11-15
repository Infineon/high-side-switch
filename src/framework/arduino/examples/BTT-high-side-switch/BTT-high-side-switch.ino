/**
 * @file        BTS-high-side-switch.ino
 * @brief       High-Side-Switch Example for the Arduino form factored shields
 *
 * @details     This example shows the usage of the offered functionalities of the shield. It includes:
 *              - Switching the channels on/off one after the other
 *              - Switching multiple channels on/off at once
 *              - Read the current flowing through the channel
 *              - Perform diagnosis for individual channel
 *              
 *              Find below the Profet 24V shield part details and its offered channels: 
 *              ---------------------------------------------------------------------------------
 *                  Shield Name            Included parts          Supported number of channels
 *              ---------------------------------------------------------------------------------
 *               24V_SHIELD_BTT6030    Profet 0 (BTT6030-2ERA)                2         
 *                                     Profet 1 (BTT6030-2ERA)                2                                 
 *                                     Profet 2 (BTT6020-1ERA)                1                          
 *              ---------------------------------------------------------------------------------
 * 
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 *
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-profet24VShield-ino.hpp>

/* Create an object of the shield with High-side-switch by passing the correct variant name.
   With this constructor invoking, all the mandatory configurations for the shield are done
   and hence it is important you pass the correct variant name.
*/
Profet24VBTTShieldIno HSS = Profet24VBTTShieldIno();

Error_t err = OK;
static int counter = 0;

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
}

/**
* This section makes calls to core API's to perform aforementioned functionalities of the board.
* The user should press '+' symbol to execute different scenarios.
* Depending on the value of the counter the following functionalites will be executed :
*    - From 1 to 5:
*        Switch on all five channels, one after the other starting with channel 1
*        Also reads out the diagnosis of the corresponding channel
*    - From 6 to 10:
*        Switch off all five channels, one after the other starting with channel 1
*        Also reads out the diagnosis of the corresponding channel
*    - From 11 to 12:
*        First turns on all channels at once
*        Then turns off all channels at once
*    - After that the counter will be reset and you can use the program again
* 
* The status of the switch can be determined with the following table:
* || Diagnosis Status || Description                                                        ||
* --------------------------------------------------------------------------------------------
* ||          0       || NORMAL          = Everything is working correctly                  ||
* ||          1       || OVERLOAD        = Exceeded the board's current limit               ||
* ||          2       || SHORT_TO_GND    = Short the ground of the board                    ||
* ||          3       || OVERTEMPERATURE = Board got to hot                                 ||
* ||          4       || SHORT_TO_VSS    = Short to the Battery pad of the board            ||
* ||          5       || OPEN_LOAD       = No load is connected                             ||
* ||          6       || UNDER_LOAD      = Not enough voltage/current to turn on the switch ||
* ||          7       || INVERSE_CURRENT = Inverse current flows into the board             ||
* 
* Please note: If you use the diagnosis function when the switch is off and no load is connected
* the status will be SHORT_TO_GND, because this state is not clear because of the provided IS signal
* of the board. Read more about this in the respective data sheet.
*/

void loop()
{   
    static int oldCounter = 0;
    int switchStatus = 0;

    /** Checks if user has entered '+' symbol*/    
    if(true == readSerialInput())
    {
        if(counter > 0 && counter < 6 && oldCounter != counter)
        {
            switchOnSingleCh(counter);
            Serial.println("Reading the current and diagnosis status of this switch ...");
            readCurrent(counter);
            readDiagnosis(counter);
            oldCounter = counter;
        }

        else if(counter > 5 && counter < 11 && oldCounter != counter)
        {
            switchOffSingleCh(counter - 5);
            Serial.println("Reading the current of this switch ...");
            readCurrent(counter - 5);
            oldCounter = counter;
        }

        else if(counter > 10 && counter < 13 && oldCounter != counter)
        {
            if(counter == 11)
            {
                Serial.println("\nTurn on all switches at once!");
                HSS.switchesHxOn(1,1,1,1,1);
                oldCounter = counter;
            }
            else if(counter == 12)
            {
                Serial.println("\nTurn off all switches at once and reset counter!");
                HSS.switchesHxOff(1,1,1,1,1);
                oldCounter = counter;
                counter = 0;
            }
        }
    }
}

/**
 * @brief       Turns on the channel passed as parameter
 * @param   ch  Channel number 
 */
void switchOnSingleCh(int ch)
{
    HSS.switchHxOn(ch);
    Serial.print("Switched Channel ");
    Serial.print(ch);
    Serial.println(" on");
    return;
}

/**
 * @brief       Read current flowing through the switch
 * @param   ch  Channel number 
 */
void readCurrent(int ch)
{
    float readAmps = 0.0;
    readAmps = HSS.readIsx(ch);
    Serial.print("Current flowing through the switch: ");
    Serial.print(readAmps);Serial.println(" A");
    return;
}

/**
 * @brief       Read diagnosis status of the switch
 * @param   ch  Channel number 
 */
void readDiagnosis(int ch)
{
    int switchStatus = HSS.readDiagx(ch);
    Serial.print("Diagnosis status of the switch: ");
    Serial.println(switchStatus);
    return;
}

/**
 * @brief       Turns off the channel passed as parameter
 * @param   ch  Channel number 
 */
void switchOffSingleCh(int ch)
{
    HSS.switchHxOff(ch);
    Serial.print("Switched Channel ");
    Serial.print(ch);
    Serial.println(" off");
    return;
}

/**
 * @brief       Check the user input
 * @details     This function is checking for a user input. To use this press the "+" 
 *              symbol on your keyboard, this is equal to "43" in ASCII. If invalid key is pressed,
 *              it returns false.
 */
bool readSerialInput()
{   
    int incomingSerial = 0;

    if(Serial.available() > 0){
        incomingSerial = Serial.read();

        if(incomingSerial == 43){
            counter++;
            return true;
        }
    }
    return false;
}