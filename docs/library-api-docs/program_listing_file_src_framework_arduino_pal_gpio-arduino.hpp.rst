
.. _program_listing_file_src_framework_arduino_pal_gpio-arduino.hpp:

Program Listing for File gpio-arduino.hpp
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_gpio-arduino.hpp>` (``src\framework\arduino\pal\gpio-arduino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef GPIO_ARDUINO_H_
   #define GPIO_ARDUINO_H_
   
   #include "hss.hpp"
   
   class GPIOIno: virtual public GPIO
   {
   private:
       uint8_t     pin;
       uint8_t     mode;
       VLogic_t    logic;
   
   public:
   
       static constexpr uint8_t  unusedPin = 0xFFU;
   
                   GPIOIno();
                   GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic);
                   ~GPIOIno();
       Error_t     init();
       Error_t     deinit();
       VLevel_t    read();
       Error_t     write(VLevel_t level);
       Error_t     enable();
       Error_t     disable();
   };
   #endif 
