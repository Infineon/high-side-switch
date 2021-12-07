.. _pal-interface:

PAL Interface
=============

The interaction with the hardware and platform resources is abstracted from the core library 
by the definition of a platform abstraction interface.
For this shield, the platform resources that need to be provided are the following:


.. list-table::
    :header-rows: 1

    * - PAL resource
      - Functionality
    * - :ref:`exhale_class_classhss_1_1_g_p_i_o_p_a_l`
      - Digital input and output ports
    * - :ref:`exhale_class_classhss_1_1_a_d_c_p_a_l`
      - Calculates current/voltage values
    * - :ref:`exhale_class_classhss_1_1_timer_p_a_l`
      - Introduces time related functionality
    
These interfaces are implemented as C++ pure virtual classes.
