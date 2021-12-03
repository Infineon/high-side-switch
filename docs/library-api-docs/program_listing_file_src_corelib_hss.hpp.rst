
.. _program_listing_file_src_corelib_hss.hpp:

Program Listing for File hss.hpp
================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss.hpp>` (``src\corelib\hss.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_H_
   #define HSS_H_
   
   #include <stdlib.h>
   #include <stdint.h>
   #include <unistd.h>
   #include "hss-types.hpp"
   #include "hss-pal-timer.hpp"
   #include "hss-pal-gpio.hpp"
   #include "hss-pal-adc.hpp"
   #include "hss-variants.hpp"
   #include "hss-filter.hpp"
   
   using namespace hss;
   
   class Hss
   {
       public:
   
                               Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant);
                               Hss(GPIOPAL *den, GPIOPAL *in0, GPIOPAL *in1, GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant);
                               ~Hss();
           Error_t             init();
           Error_t             deinit();
           Error_t             enable(Channel_t ch=CHANNEL0);
           Error_t             disable(Channel_t ch=CHANNEL0);
           Error_t             enableDiag();
           Error_t             disableDiag();
   
           Status_t            getSwitchStatus();
           DiagStatus_t        diagRead(float senseCurrent, Channel_t ch=CHANNEL0);
           float               readIs(uint16_t rSense, Channel_t ch=CHANNEL0);
   
           void                setCurrentOffset(float offset);
   
       protected:
   
           GPIOPAL             *den;
           GPIOPAL             *in0;
           GPIOPAL             *in1;
           GPIOPAL             *dsel;
           ADCPAL              *is;
   
           TimerPAL            *timer;
   
           ExponentialFilter   *currentFilter;
   
           BtxVariants_t       *btxVariant;
           Status_t            status;
           Status_t            statusCh0;
           Status_t            statusCh1;
   
           DiagEnable_t        diagEnb;
           DiagStatus_t        diagStatus;
   
           Error_t             selDiagCh(Channel_t ch);
   
       private:
   
           float               currentOffset = 0.0;
   
   };
   
   #endif 
