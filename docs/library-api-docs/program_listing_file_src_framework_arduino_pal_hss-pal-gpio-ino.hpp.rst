
.. _program_listing_file_src_framework_arduino_pal_hss-pal-gpio-ino.hpp:

Program Listing for File hss-pal-gpio-ino.hpp
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_hss-pal-gpio-ino.hpp>` (``src\framework\arduino\pal\hss-pal-gpio-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_PAL_GPIO_INO_HPP_
   #define HSS_PAL_GPIO_INO_HPP_
   
   #include "hss-pal-gpio.hpp"
   
   using namespace hss;
   
   class GPIOIno: virtual public GPIOPAL
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
