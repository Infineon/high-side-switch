/**
 * @file        BTS-high-side-switch.ino
 * @brief       High-Side-Switch Example for the Arduino form factored shields
 *
 * @details     This example shows the usage of the offered functionalities of the shield. It includes:
 *              - Switching the channels on/off one after the other(in case if multiple channels supported)
 *              - Switching multiple channels on/off at once (supported only in SHIELD_BTS700x-1EPP)
 *              - Read the current flowing through the channel
 *              - Perform diagnosis for individual channel
 *              - Read battery voltage at any instant of time.
 *              
 *              Find below the Profet 12V shields and its supported variant details that are valid choices
 *              to run this example: 
 *              ---------------------------------------------------------------------------------
 *                  Shield Name        Supported number of channels    Available variants      
 *              ---------------------------------------------------------------------------------
 *              SHIELD_BTS700x-1EPP                 4                        BTS7002
 *                                                                           BTS7004
 *                                                                           BTS7006
 *                                                                           BTS7008
 *                              
 *              SHIELD_BTS5001x-1TAD        1 (set as default)               BTS50010
 *                                                                           BTS50015      
 *              ---------------------------------------------------------------------------------
 * 
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * 
 * @note        This example can be used for both SHIELD_BTS700x-1EPP and SHIELD_BTS5001x-1TAD shields
 *              provided you select correct parameters. Some functions like turning on/off multiple switches at
 *              once is not supported in SHIELD_BTS5001x-1TAD and hence would not serve as a valid function call.
 *              Please read the inline code comments for better understanding.
 * 
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

/**
 *  Enable the example for the shield you have by defining 'SHIELD'
 */
#define BTS700x_1EPP    0
#define BTS5001x_1TAD   1
#define SHIELD          BTS700x_1EPP

/* Create an object of the shield with High-side-switch by passing the correct variant name.
   With this constructor invoking, all the mandatory configurations for the shield are done
   and hence it is important you pass the correct variant name.
*/
#if SHIELD == BTS700x_1EPP
    #include <hss-bts700xShield-ino.hpp>
    Bts700xShieldIno HSS = Bts700xShieldIno(&BTS7002);
#else
    #include <hss-bts500xxShield-ino.hpp>
    Bts500xxShieldIno HSS = Bts500xxShieldIno(&BTS50015);
#endif

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

* A) For SHIELD_BTS700x-1EPP:
*    - From 1 to 4:
*        Switch on all four channels, one after the other starting with channel 1
*        Also reads out the diagnosis of the corresponding channel
*    - From 5 to 8:
*        Switch off all four channels, one after the other starting with channel 1
*        Also reads out the diagnosis of the corresponding channel
*    - From 9 to 10:
*        First turns on all channels at once
*        Then turns off all channels at once
*    - After that the counter will be reset and you can use the program again
* 
* B) For SHIELD_BTS5001x-1TAD:
*   - For counter = 1:
*       Switch on the channel and reads out the diagnosis of the corresponding channel
*   - For counter = 2:
*       Switch off the channel and reads out the diagnosis of the corresponding channel
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

    /** Checks if user has entered'+' symbol*/    
    if(true == readSerialInput())
    {
        switch (SHIELD)
        {
            case BTS5001x_1TAD:
                if(counter == 1)
                {
                    switchOnSingleCh(counter);
                    Serial.println("Reading the current and diagnosis status of this switch ...");
                    readCurrent(counter);
                    readDiagnosis(counter);
                    readBatteryVoltage();
                    oldCounter = counter;
                }

                if(counter == 2)
                {
                    switchOffSingleCh(counter - 1);
                    Serial.println("Reading the current and diagnosis status of this switch ...");
                    readCurrent(counter - 1);
                    readDiagnosis(counter - 1);
                    readBatteryVoltage();
                    oldCounter = counter;
                    counter = 0;
                }
                break;

            case BTS700x_1EPP:
                if(counter > 0 && counter < 5 && oldCounter != counter){
                    switchOnSingleCh(counter);
                    Serial.println("Reading the current and diagnosis status of this switch ...");
                    readCurrent(counter);
                    readDiagnosis(counter);
                    readBatteryVoltage();
                    oldCounter = counter;
                }

                else if(counter > 4 && counter < 9 && oldCounter != counter){
                    switchOffSingleCh(counter - 4);
                    Serial.println("Reading the current and diagnosis status of this switch ...");
                    readCurrent(counter - 4);
                    readDiagnosis(counter - 4);
                    readBatteryVoltage();
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
                break;
        }
    }
    else
        Serial.println("Waiting for user input...");
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
 * @brief       Reads the current battery voltage
 */
void readBatteryVoltage()
{
    float batteryVoltage = 0.0;
    batteryVoltage = HSS.readVss();
    Serial.print("Current battery voltage : ");
    Serial.print(batteryVoltage);Serial.println(" V\n");
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