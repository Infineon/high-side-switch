
.. _program_listing_file_src_corelib_hss-types.hpp:

Program Listing for File hss-types.hpp
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-types.hpp>` (``src\corelib\hss-types.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_TYPES_HPP_
   #define HSS_TYPES_HPP_
   
   namespace hss
   {
   
       enum Error_t
       {
           OK                   =  0,   
           INTF_ERROR           = -1,   
           CONF_ERROR           = -2,   
           READ_ERROR           = -3,   
           WRITE_ERROR          = -4,   
           NULLPTR_ERROR        = -5,   
           INVALID_CH_ERROR     = -6,   
           UNSUPPORTED_OP_ERROR = -7,   
           INIT_ERROR           = -8    
       };
       enum Channel_t
       {
           CHANNEL0     = 0,           
           CHANNEL1     = 1,           
           ALL_CHANNELS = 2,           
           NO_CHANNEL   = 3            
       };
       enum Status_t{
           UNINITED    = 0,    
           INITED      = 1,    
           POWER_ON    = 2,    
           POWER_OFF   = 3,    
       };
       enum DiagEnable_t{
           DIAG_EN      = 0,    
           DIAG_DIS     = 1,    
       };
       enum DiagStatus_t{
           DIAG_READ_ERROR     = -1,   
           NOT_ENABLED         = -2,   
           NORMAL              = 0,    
           FAULT               = 1,    
           FAULT_OL_IC         = 2,    
           SHORT_TO_GND_OR_OT  = 3,    
           SHORT_TO_VSS        = 5,    
           OPEN_LOAD           = 6,    
       };
   }
   
   #define HSS_ASSERT_RET(x)       if( x != OK ) { return x; }
   #define HSS_ASSERT_NULLPTR(x)   if( x == nullptr ) { return NULLPTR_ERROR; }
   
   #endif 
