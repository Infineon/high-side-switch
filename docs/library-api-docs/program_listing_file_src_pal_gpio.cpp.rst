
.. _program_listing_file_src_pal_gpio.cpp:

Program Listing for File gpio.cpp
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_gpio.cpp>` (``src\pal\gpio.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "gpio.hpp"
   
   
   GPIO::Error_t GPIO::checkErrorStatus()
   {
       return errorStatus;
   }
