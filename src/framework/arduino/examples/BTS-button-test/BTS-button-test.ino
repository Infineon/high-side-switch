/**
 * @file        button-test.ino
 * @brief       Button Test Example for Profet 12V BTS700x and BTS500xx Arduino form factored Shields
 *
 *              SHIELD_BTS700x-1EPP and SHIELD_BTS5001x-1TAD Shields have optional user button to 
 *              perform switching. This example demonstrates the use of optional user button.
 *              This functionallty is not included in the main example, because the
 *              button is not populated on the board by default.
 * 
 *                  Variant details for Profet 12 V shields:
 *              ------------------------------------------------
 *                  Shield Name            Available variants
 *              ------------------------------------------------
 *              SHIELD_BTS700x-1EPP             BTS7002
 *                                              BTS7004
 *                                              BTS7006
 *                                              BTS7008
 * 
 *              SHIELD_BTS5001x-1TAD            BTS50010
 *                                              BTS50015      
 *             -------------------------------------------------
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
 * @details     The BTS700x_1EPP shield supports both digital and analog read button functionality
 *              which is configurable through jumpers (Refer manual for details).
 * 
 *                  Jumper being used       Read Button Functions
 *                          J2             analogReadButton(Analog)
 *                          J3             digitalReadButton(Digital)
 *
 *              In this example we use the analogReadButton() functionality of the library
 *              to read out the VSS of the attached power supply. In case you wish to use digitalReadButton()
 *              functionality, replace analogReadButton by digitalReadButton. 
 * 
 * @note        Ensure always that you have right function being called in correspondance to the jumper configurations.
 * 
 *              BTS5001x_1TAD only supports analogReadButton() functionality and there are no hardware
 *              configurations required to be able to call this function.
 */
void loop()
{
    float voltage = 0.0;
    static bool button_pressed = false;                         // The flag is used to avoid printing constantly

    if(HSS.analogReadButton() && button_pressed == false){
        button_pressed = true;
        voltage = HSS.readVss();
        Serial.print("Supply voltage is: ");
        Serial.println(voltage);
    }

    if(!HSS.analogReadButton()){
        button_pressed = false;
    }
}