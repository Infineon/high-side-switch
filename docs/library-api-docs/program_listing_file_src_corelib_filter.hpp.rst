
.. _program_listing_file_src_corelib_filter.hpp:

Program Listing for File filter.hpp
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_filter.hpp>` (``src\corelib\filter.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef FILTER_HPP_
   #define FILTER_HPP_
   
   #include <stdint.h>
   
   class ExponentialFilter
   {
       public:
   
           ExponentialFilter();
           ExponentialFilter(float y);
           ExponentialFilter(float y, uint16_t t);
   
           void setFilter(float y, uint16_t t);
           void setTau(uint16_t t);
           void setToNewValue(float y);
           float input(float x);
           float output();
           uint16_t pow2(uint16_t p);
   
           private:
           uint16_t tau;
   
           float y;
           float y_last;
           float x;
   };
   #endif 
