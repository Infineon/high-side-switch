/**
 * @file        BTS-hss-single-ch.ino
 * @brief       High-Side-Switch Single Channel Operation Example for the Arduino form factored shields.
 * @details     This example demonstrates how to switch on/off single channel in a BTS shield. It also 
 *              calls API to read the current value.
 *    
 *              Find below the Profet 12V shields and its supported variant details that are valid choices
 *              to run this example: 
 *              _________________________________________________________________________________
 *                  Shield Name        Supported number of channels    Available variants      
 *              _________________________________________________________________________________
 *              SHIELD_BTS700x-1EPP                 4                        BTS7002
 *                                                                           BTS7004
 *                                                                           BTS7006
 *                                                                           BTS7008
 *                              
 *              SHIELD_BTS5001x-1TAD        1 (set as default)               BTS50010
 *                                                                           BTS50015      
 *              _________________________________________________________________________________
 * 
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * 
 * @note        This example can be used for both SHIELD_BTS700x-1EPP and SHIELD_BTS5001x-1TAD shields
 *              provided you select correct parameters.
 *              Please read the inline code comments for configuration.
 * 
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

/**
 *  Enable the example for the shield you have by defining 'SHIELD'
 */
#define BTS700x_1EPP    0
#define BTS5001x_1TAD   1
#define SHIELD          BTS700x_1EPP

/** Create an object of the shield with High-side-switch by passing the correct variant name.
   With this constructor invoking, all the mandatory configurations for the shield are done
   and hence it is important you pass the correct variant name.
*/
#if SHIELD == BTS700x_1EPP
    #include <hss-shield-bts700x-ino.hpp>
    Bts700xShieldIno HSS = Bts700xShieldIno(&BTS7002);

    /// Set channel to be used for single switch operation
    int channel = 2;
#else
    #include <hss-shield-bts500xx-ino.hpp>
    Bts500xxShieldIno HSS = Bts500xxShieldIno(&BTS50015);
    int channel = 1;
#endif

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