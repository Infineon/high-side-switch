
.. _program_listing_file_src_framework_arduino_examples_button-test_button-test.ino:

Program Listing for File button-test.ino
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_examples_button-test_button-test.ino>` (``src\framework\arduino\examples\button-test\button-test.ino``)

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
       float voltage = 0.0;
       static bool button_pressed = false;                         // The flag is used to avoid printing constantly
   
       if(HSS.digitalReadButton() && button_pressed == false){
           button_pressed = true;
           voltage = HSS.readVss();
           Serial.print("Supply voltage is: ");
           Serial.println(voltage);
       }
   
       if(!HSS.digitalReadButton()){
           button_pressed = false;
       }
   }
