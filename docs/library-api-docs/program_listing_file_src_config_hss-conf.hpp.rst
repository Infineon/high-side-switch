
.. _program_listing_file_src_config_hss-conf.hpp:

Program Listing for File hss-conf.hpp
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_config_hss-conf.hpp>` (``src\config\hss-conf.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_CONF_HPP_
   #define HSS_CONF_HPP_
   
   #include "hss-conf-opts.hpp"
   
   #ifndef HSS_LOGGER_ENABLED
   #define HSS_LOGGER_ENABLED    0   
   #endif
   
   #if (HSS_LOGGER_ENABLED == 1)
   #endif
   
   #include "hss-conf-dfl.hpp"
   
   #endif 
