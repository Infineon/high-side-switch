
.. _program_listing_file_src_pal_adc.cpp:

Program Listing for File adc.cpp
================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_adc.cpp>` (``src\pal\adc.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "adc.hpp"
   
   AnalogDigitalConverter::Error_t AnalogDigitalConverter::checkErrorStatus()
   {
       return errorStatus;
   }
