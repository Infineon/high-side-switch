
.. _program_listing_file_src_corelib_filter.cpp:

Program Listing for File filter.cpp
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_filter.cpp>` (``src\corelib\filter.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "filter.hpp"
   
   ExponentialFilter::ExponentialFilter()
   {
       this->y = 0.0;
       this->y_last = 0.0;
       this->x = 0.0;
       this->tau = 1;
   }
   
   ExponentialFilter::ExponentialFilter(float y)
   {
       this->y = y;
       this->y_last = y;
       this->x = y;
   }
   
   ExponentialFilter::ExponentialFilter(float y, uint16_t t)
   {
       this->y = y;
       this->y_last = y;
       this->x = y;
       this->tau = pow2(t);  
   }
   
   void ExponentialFilter::setFilter(float y, uint16_t t)
   {
       this->y = y;
       this->y_last = y;
       this->x = y;
       this->tau = pow2(t);
   }
   
   void ExponentialFilter::setTau(uint16_t t)
   {
       this->tau = pow2(t);
   }
   
   void ExponentialFilter::setToNewValue(float y)
   {
       this->y = y_last = x = y;
   }
   
   float ExponentialFilter::input(float x)
   {
       y_last = y;
       this->x = x;
   
       y = y_last + ((x - y_last)/(float)tau);
   }
   
   float ExponentialFilter::output()
   {
       return y;
   }
   
   uint16_t ExponentialFilter::pow2(uint16_t p)
   {
       return 1<< p;
   }
   
