
.. _program_listing_file_src_framework_arduino_examples_high-side-switch_high-side-switch.ino:

Program Listing for File high-side-switch.ino
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_examples_high-side-switch_high-side-switch.ino>` (``src\framework\arduino\examples\high-side-switch\high-side-switch.ino``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include <hss-board-arduino.hpp>
   
   HssBoardIno HSS = HssBoardIno(&BTS7002);
   
   void setup()
   {
       Serial.begin(115200);
       delay(2000);
       Serial.println("Serial initialized");
   
       HSS.init();
       delay(1000);
       Serial.println("High-Side-Switch is initialized");
   }
   
   void loop()
   {   
       int incomingSerial = 0;
       static int counter = 0;
       static int oldCounter = 0;
   
       float readAmps = 0.0;
       float batteryVoltage = 0.0;
   
       int switchStatus = 0;
   
       if(Serial.available() > 0){
           incomingSerial = Serial.read();
   
           if(incomingSerial == 43){
               counter++;
           }
       }
   
       if(counter > 0 && counter < 5 && oldCounter != counter){
           HSS.switchHxOn(counter);
           Serial.print("Switched half bridge ");
           Serial.print(counter);
           Serial.println(" on");
   
           Serial.println("Reading the current and diagnosis status of this switch ...");
           readAmps = HSS.readIsx(counter);
           Serial.print("Current flowing through the switch: ");
           Serial.print(readAmps);Serial.println(" A");
   
           switchStatus = HSS.readDiagx(counter);
           Serial.print("Diagnosis status of the switch: ");
           Serial.println(switchStatus);
   
           batteryVoltage = HSS.readVss();
           Serial.print("Current battery voltage : ");
           Serial.print(batteryVoltage);Serial.println(" V\n");
   
           oldCounter = counter;
       }
       else if(counter > 4 && counter < 9 && oldCounter != counter){
           HSS.switchHxOff(counter - 4);
           Serial.print("Switched half bridge ");
           Serial.print(counter - 4);
           Serial.println(" off");
   
           Serial.println("Reading the current and diagnosis status of this switch ...");
           readAmps = HSS.readIsx(counter - 4);
           Serial.print("Current flowing through the switch: ");
           Serial.print(readAmps);Serial.println(" A");
   
           switchStatus = HSS.readDiagx(counter - 4);
           Serial.print("Diagnosis status of the switch: ");
           Serial.println(switchStatus);
   
           batteryVoltage = HSS.readVss();
           Serial.print("Current battery voltage : ");
           Serial.print(batteryVoltage);Serial.println(" V\n");
   
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
   }
