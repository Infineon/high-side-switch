High-Side-Switch Implementation Guide  
------------------------------------------
This section covers the API implementation for High Side Switches used in the Profet family of shields.
This library is currently usable with:

* Profet 12V Shield with BTS7002, BTS7004, BTS7006 or BTS7008 variant
* Profet 12V Shield with BTS50010 or BTS50015 variant 
* Profet 24V Shield with BTT6030 and BTT6020 variant

The implemented APIs, turn the loads ON and OFF by switching the positive (high-) side of the load supply.
Additionaly, it covers sense and diagnostic functionalities to flag any unintended system behavior.

Table of Contents 
++++++++++++++++++

:ref:`exhale_class_class_hss`

Class Details
^^^^^^^^^^^^^^

.. list-table::
    :header-rows: 1

    * - Included in module 
      - Class Name
      - Summary
    * - :code:`corelib`
      - :ref:`exhale_class_class_hss`
      - High-Side-Switch main class with core functionalities
    * - 
      - :ref:`exhale_class_class_hss_board`
      - Base class for PROFET-Shield with all it's functions
    * - 
      - :ref:`exhale_class_class_bts500xx_shield`
      - Shield class implementation for Profet 12V - BTS5001x variant
    * - 
      - :ref:`exhale_class_class_bts700x_shield`
      - Shield class implementation for Profet 12V - BTS700x variant
    * - 
      - :ref:`exhale_class_class_profet24_v_b_t_t_shield`
      - Shield class implementation for Profet 24V - BTT60xx variant
    * - 
      - :ref:`exhale_class_class_exponential_filter`
      - Filter class for output optimization
    * - :code:`pal`
      - :ref:`exhale_class_classhss_1_1_g_p_i_o_p_a_l`
      - GPIO Platform Abstraction Layer
    * - 
      - :ref:`exhale_class_classhss_1_1_a_d_c_p_a_l`
      - ADC Platform Abstraction Layer
    * - 
      - :ref:`exhale_class_classhss_1_1_timer_p_a_l`
      - Timer Platform Abstraction Layer
    * - :code:`framework/arduino/pal`
      - :ref:`exhale_class_class_g_p_i_o_ino`
      - Arduino GPIO Implementation
    * - 
      - :ref:`exhale_class_class_a_d_c_ino`
      - Arduino ADC Implementation
    * - 
      - :ref:`exhale_class_class_timer_ino`
      - Arduino Timer Implementation

    * - :code:`framework/arduino/wrapper`
      - :ref:`exhale_class_class_hss_ino`
      - Arduino class of the High-Side-Swich
    * - 
      - :ref:`exhale_class_class_bts500xx_shield_ino`
      - Profet 12V - BTS5001x shield wrapper implementation
    * - 
      - :ref:`exhale_class_class_bts700x_shield_ino`
      - Profet 12V - BTS700x shield wrapper implementation
    * - 
      - :ref:`exhale_class_class_profet24_v_b_t_t_shield_ino`
      - Profet 24V - BTT60xx shield wrapper implementation

Configuration Struct Details
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. list-table::
    :header-rows: 1

    * - Included in module 
      - Struct Name
      - Summary
    * - :code:`corelib`
      - :ref:`exhale_struct_struct_btx_variants__t`
      - HSS type specific parameters for diagnosis
    * - :code:`framework/arduino/wrapper`
      - :ref:`exhale_struct_struct_b_t_s500xx_hw_config__t`
      - Platform configuration for BTS5001x Shield
    * - :code:`framework/arduino/wrapper`
      - :ref:`exhale_struct_struct_bts700x_hw_config__t`
      - Platform configuration for BTS700x Shield
    * - :code:`framework/arduino/wrapper`
      - :ref:`exhale_struct_struct_profet24_v_b_t_t_hw_config__t`
      - Platform configuration for BTS700x Shield