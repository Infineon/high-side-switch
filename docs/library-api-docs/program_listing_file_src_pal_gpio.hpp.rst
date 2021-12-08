
.. _program_listing_file_src_pal_gpio.hpp:

Program Listing for File gpio.hpp
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_gpio.hpp>` (``src\pal\gpio.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <stdint.h>
   
   #ifndef GPIO_HPP_
   #define GPIO_HPP_
   
   class GPIO
   {
       public:
       
           enum Error_t
           {
               OK          = 0,     
               INTF_ERROR  = -1,    
               CONF_ERROR  = -2,    
               READ_ERROR  = -3,    
               WRITE_ERROR = -4,    
           };
   
           enum IntEvent_t
           {
               INT_FALLING_EDGE   = 0,     
               INT_RISING_EDGE    = 1,     
           };
           enum VLevel_t
           {
               GPIO_LOW   = 0,        
               GPIO_HIGH  = 1         
           };        
           enum VLogic_t
           {
               NEGATIVE = 1,       
               POSITIVE = 2,       
           };
           virtual Error_t        init        () = 0;
           
           virtual Error_t       deinit      () = 0;
   
           virtual VLevel_t       read        () = 0;
           
           virtual Error_t        write       (VLevel_t level) = 0;
   
           virtual Error_t        enable      () = 0;
   
           virtual Error_t        disable     () = 0;
   
           Error_t checkErrorStatus();
   
           private:
           Error_t errorStatus;
   
   };
   
   #endif 
