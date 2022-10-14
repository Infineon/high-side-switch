/**
 * @file        BTS500xx-hss-advanced.ino
 * @brief       High-Side-Switch Advanced Example for BTS500xx Arduino form factored shield
 * @details     This example shows the usage of all the offered functionalities of the shield.
 *              It does the following:
 *              - Demonstrates the diagnosis functionality of the channels
 *              - Demonstrates the different voltage measurement functionalities
 *              - Demonstrates the temperature measurement
 *
 *              It can be deployed to the Arduino Uno or the XMC's with corresponding form factor.
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 */

#include <hss-shield-bts500xx-ino.hpp>

using namespace hss;

/** Creation of the hss board object */
Bts500xxShieldIno HSS = Bts500xxShieldIno();

Error_t err = OK;
DiagStatus_t diagStatus = NORMAL;

float readCurrent = 0.0;
float batteryVoltage = 0.0;
float outputVoltage = 0.0;
float temperature = 0.0;

void setup()
{
    /** Serial initialization */
    Serial.begin(9600);
    Serial.println("Serial initialized");

    /** Initialization of the High-Side-Switch-Board */
    err = HSS.init();
    if(OK != err)
    {
        Serial.println("Initialization failed");
    }
    else
    {
        Serial.println("Initialization successful!");
    }
    delay(1000);
}

void loop()
{
    /** Diagnosis with switch 1 turned off */
    diagStatus = HSS.readDiagx(1);
    showDiagStatus(diagStatus);

    /** Turn on switch 1 */
    err = HSS.switchHxOn(1);
    if(OK != err)
    {
        showErrorStatus(err);
    }
    delay(2000);

    /** Read current through switch 1 */
    for(int i=0; i<10; i++)
    {
        readCurrent = HSS.readIsx(1);
    }
    Serial.print("Current flowing through switch 1: ");
    Serial.print(readCurrent);
    Serial.println(" A");
    delay(2000);

    /** Diagnosis with switch 1 turned on */
    diagStatus = HSS.readDiagx(1);
    showDiagStatus(diagStatus);
    delay(2000);

    /** Diagnosis with switch 2 turned off */
    diagStatus = HSS.readDiagx(2);
    showDiagStatus(diagStatus);
    delay(2000);

    /** Turn on switch 2 */
    err = HSS.switchHxOn(2);
    if(OK != err)
    {
        showErrorStatus(err);
    }
    delay(2000);

    /** Read current through switch 2 */
    for(int i=0; i<10; i++)
    {
        readCurrent = HSS.readIsx(2);
    }
    Serial.print("Current flowing through switch 2: ");
    Serial.print(readCurrent);
    Serial.println(" A");
    delay(2000);

    /** Diagnosis with switch 2 turned on */
    diagStatus = HSS.readDiagx(2);
    showDiagStatus(diagStatus);
    delay(2000);

    /** Measure the output voltage of switch 1 */
    outputVoltage = HSS.readVOut();
    Serial.print("The output voltage of switch 1 is ");
    Serial.print(outputVoltage);
    Serial.println(" V");
    delay(2000);

    /** Check the board temperature */
    temperature = HSS.readTemperature();
    Serial.print("The board temperature is ");
    Serial.print(temperature);
    Serial.println(" °C");
    delay(2000);

    /** Measure the battery voltage */
    batteryVoltage = HSS.readVs();
    Serial.print("The battery voltage is ");
    Serial.print(batteryVoltage);
    Serial.println(" V");
    delay(2000);

    /** Turn off both switches */
    err = HSS.switchesHxOff(true, true);
    if(OK != err)
    {
        showErrorStatus(err);
    }
    delay(5000);
}

/** Helper function to show the different diagnosis states */
void showDiagStatus(DiagStatus_t diagState)
{
    switch (diagState)
    {
    case SHORT_TO_VSS:
        Serial.println("You have a short to the supply voltage at this switch");
        break;

    case OPEN_LOAD:
        Serial.println("You have an open load at this switch. You should check your connection");
        break;

    case SHORT_TO_GND_OR_OT:
        Serial.println("You have a short to the ground or an over-temperature at this switch");
        break;

    case FAULT:
        Serial.println("You have a detected fault condition at this switch. Please check the data sheet for more information [page 19-20]");
        break;

    case DIAG_READ_ERROR:
        Serial.println("You have a diagnosis read error, which means you have chosen a channel that is invalid");
        Serial.println("Only channel 1 and 2 are valid channels!");
        break;

    default:
        Serial.println("Everything is working correctly");
        break;
    }
}

/** Helper function to show the different error codes */
void showErrorStatus(Error_t error)
{
    switch (error)
    {
    case INTF_ERROR:
        Serial.println("You have encountered an interface error");
        break;

    case CONF_ERROR:
        Serial.println("You have encountered a configuration error");
        break;

    case READ_ERROR:
        Serial.println("You have encountered a reading error");
        break;

    case WRITE_ERROR:
        Serial.println("You have encountered a writing error");
        break;

    case NULLPTR_ERROR:
        Serial.println("You have encountered a null pointer error");
        break;

    case INVALID_CH_ERROR:
        Serial.println("You have encountered an invalid channel error");
        break;

    case UNSUPPORTED_OP_ERROR:
        Serial.println("You have encountered an unsupported operation error");
        break;

    case INIT_ERROR:
        Serial.println("You have encountered an initialization error");
        break;

    default:
        /** Default state is OK, here we do not print anything */
        break;
    }
}