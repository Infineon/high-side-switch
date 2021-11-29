.. _arduino-examples:

Arduino Examples
================
To run these examples use either the Arduino IDE or something similar like the PlatformIO extension for Visual Code or Atom.

.. list-table::
    :header-rows: 1

    * - Example 
      - Summary 
    * - :code:`examples/BTT-hss-advanced`   
      - * Default high-side-switch advanced test. 
        * Compatible with BTT60xx variants.
    * - :code:`examples/BTT-hss-multiple-ch`
      - * High-side-switch example to operate multiple channels. 
        * Compatible with BTT60xx variants.
    * - :code:`examples/BTT-hss-single-ch`  
      - * Basic High-side-switch example to operate single channel. 
        * Compatible with BTT60xx variants.
    * - :code:`examples/BTS-hss-advanced`   
      - * Default high-side-switch advanced test. 
        * Compatible with BTS5001x and BTS700x variants.
    * - :code:`examples/BTS-hss-multiple-ch`
      - * High-side-switch example to operate multiple channels. 
        * Compatible with BTS700x variants.
    * - :code:`examples/BTS-hss-single-ch`  
      - * Basic High-side-switch example to operate single channel. 
        * Compatible with BTS5001x and BTS700x variants.
    * - :code:`examples/BTS-button-test`    
      - * Switch dependent on optional user button. 
        * Compatible with BTS5001x and BTS700x variants.

All Arduino sketches are also available for the other included platforms. See below :code:`src/framework/PLATFORM` directory.

BTT-hss-advanced
""""""""""""""""
Summary
^^^^^^^
Default high-side-switch advanced test. Compatible with BTT60xx variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/btt6x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Shield
      - Included Variants
      - Supported Channels
    * - 24V_SHIELD_BTT6030
      - Profet 0 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 1 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 2 (BTT6020-1ERA)
      - 1

Description
^^^^^^^^^^^
This example shows the usage of the offered functionalities of the shield. It includes:
 * Switching the channels on/off one after the other
 * Switching multiple channels on/off at once
 * Read the current flowing through the channel
 * Perform diagnosis for individual channel while switch is ON

* Set the channel value for single channel operation in :code:`channel` variable. See below the mapping :

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`channel = 0`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`channel = 1`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`channel = 2`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`channel = 3`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`channel = 4`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

* In order to configure multiple channels, you can set the desired channels to true in the :code:`ch[5]` array. See below the mapping :

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`ch[0]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`ch[1]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`ch[2]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`ch[3]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`ch[4]`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

BTT-hss-multiple-ch
""""""""""""""""""""
Summary 
^^^^^^^
High-side-switch example to operate multiple channels. Compatible with BTT60xx variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/btt6x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Shield
      - Included Variants
      - Supported Channels
    * - 24V_SHIELD_BTT6030
      - Profet 0 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 1 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 2 (BTT6020-1ERA)
      - 1

Description
^^^^^^^^^^^
This example demonstrates how to switch on/off multiple channels at once.
In total, there are 5 channels provided in this board. Through this example,
you can control these 5 channels at the same time by setting the required channels 
to true in the :code:`ch[5]` where index-0 maps to channel 0. See below channel to port mapping:

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`ch[0]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`ch[1]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`ch[2]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`ch[3]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`ch[4]`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

BTT-hss-single-ch
""""""""""""""""""
Summary 
^^^^^^^
Basic High-side-switch example to operate single channel. Compatible with BTT60xx variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/btt6x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Shield
      - Included Variants
      - Supported Channels
    * - 24V_SHIELD_BTT6030
      - Profet 0 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 1 (BTT6030-2ERA)
      - 2
    * - 
      - Profet 2 (BTT6020-1ERA)
      - 1

Description
^^^^^^^^^^^
This is a basic high-side-switch example that demonstrates how to switch on/off a specific channel.
Along with channel operation, you could also determine the sensed current of the channel.
In total, there are 5 channels provided in this board and you can select which channel to function by setting 
correct number in :code:`channel`. See below channel to port mapping:

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`channel = 0`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`channel = 1`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`channel = 2`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`channel = 3`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`channel = 4`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

BTS-hss-advanced
""""""""""""""""""""
Summary
^^^^^^^
Default high-side-switch advanced test. Compatible with BTS5001x and BTS700x variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/bts5001x_shield.png
    :width: 150

.. image:: ../../img/bts700x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Type
      - Variant
      - Covered by
    * - Shield
      - BTS7002
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7004
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7006
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7008
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS50010
      - :code:`hss-bts500xxShield-ino.hpp`
    * - Shield
      - BTS50015
      - :code:`hss-bts500xxShield-ino.hpp`

Description
^^^^^^^^^^^
This example shows the usage of the offered functionalities of the shield. It includes:
 * Switching the channels on/off one after the other (in case if multiple channels supported)
 * Switching multiple channels on/off at once (supported only in BTS700x variants)
 * Read the current flowing through the channel
 * Perform diagnosis for individual channel
 * Read battery voltage at any instant of time

This example can be used for both, BTS700x and BTS5001x shields.

.. warning::
    Some functions like turning on/off multiple switches at once is not supported for the BTS5001x-1TAD shields and hence would not serve as a valid function call. Please read the inline code comments for better understanding.

* Set the channel value for single channel operation in :code:`channel` variable (only if selected shield is BTS700x). See below the mapping :

.. list-table::
    :header-rows: 1
    
    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`channel = 1`
      - BTS700x U1
      - OUT1
    * - :code:`channel = 2`
      - BTS700x U2
      - OUT2
    * - :code:`channel = 3`
      - BTS700x U3
      - OUT3
    * - :code:`channel = 4`
      - BTS700x U4
      - OUT4

.. note::
    In case of BTS5001x-1TAD shields, :code:`channel` would always remain `1` since this shield variant supports single channel.
    
* In order to configure multiple channels (valid only for BTS700x shield), you can set the desired channels to true in the `ch[4]` array. See below the mapping :
    
.. list-table::
  :header-rows: 1
    
  * - Channel (in example code)
    - Controls
    - Mapped output port
  * - `ch[0]`
    - BTS700x U1
    - OUT1
  * - `ch[1]`
    - BTS700x U2
    - OUT2
  * - `ch[2]`
    - BTS700x U3
    - OUT3
  * - `ch[3]`
    - BTS700x U4
    - OUT4

BTT-hss-multiple-ch
""""""""""""""""""""
Summary 
^^^^^^^
High-side-switch example to operate multiple channels. Compatible with BTT60xx variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/bts700x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Type
      - Variant
      - Covered by
    * - Shield
      - BTS7002
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7004
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7006
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7008
      - :code:`hss-bts700xShield-ino.hpp`
  
Description
^^^^^^^^^^^
This example demonstrates how to switch on/off multiple channels at once.
In total, there are 4 channels provided in this board. Through this example,
you can control these 4 channels at the same time by setting the required channels 
to true in the :code:`ch[4]` where index-0 maps to channel 1. See below channel to port mapping:

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`ch[0]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`ch[1]`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`ch[2]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`ch[3]`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`ch[4]`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

BTT-hss-single-ch
""""""""""""""""""
Summary 
^^^^^^^
Basic High-side-switch example to operate single channel. Compatible with BTT60xx variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/bts5001x_shield.png
    :width: 150

.. image:: ../../img/bts700x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Type
      - Variant
      - Covered by
    * - Shield
      - BTS7002
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7004
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7006
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7008
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS50010
      - :code:`hss-bts500xxShield-ino.hpp`
    * - Shield
      - BTS50015
      - :code:`hss-bts500xxShield-ino.hpp`

Description
^^^^^^^^^^^
This is a basic high-side-switch example that demonstrates how to switch on/off a specific channel.
Along with channel operation, you could also determine the sensed current of the channel.
In total, there are 4 channels and 1 channel provided in the BTS700x and BTS5001x board respectively and 
you can select which channel to operate by setting correct number in :code:`channel`. See below channel to port mapping:

.. list-table::
    :header-rows: 1

    * - Channel (in example code)
      - Controls
      - Mapped output port
    * - :code:`channel = 0`
      - Profet 0 (BTT6030-2ERA part 0 : channel 0)
      - OUT 0.0
    * - :code:`channel = 1`
      - Profet 0 (BTT6030-2ERA part 0 : channel 1)
      - OUT 0.1
    * - :code:`channel = 2`
      - Profet 1 (BTT6030-2ERA part 1 : channel 0)
      - OUT 1.0
    * - :code:`channel = 3`
      - Profet 1 (BTT6030-2ERA part 1 : channel 1)
      - OUT 1.1
    * - :code:`channel = 4`
      - Profet 0 (BTT6020-1ERA : channel 0)
      - OUT 2

.. note::
    In case of BTS5001x-1TAD shields, :code:`channel` would always remain :code:`1` since this shield variant supports single channel.
      
BTS-button-test
""""""""""""""""
Summary
^^^^^^^
Switch dependent on optional user button. Compatible with BTS5001x and BTS700x variants.

Compatibility
^^^^^^^^^^^^^
.. image:: ../../img/bts5001x_shield.png
    :width: 150

.. image:: ../../img/bts700x_shield.jpg
    :width: 150

.. list-table::
    :header-rows: 1

    * - Type
      - Variant
      - Covered by
    * - Shield
      - BTS7002
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7004
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7006
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS7008
      - :code:`hss-bts700xShield-ino.hpp`
    * - Shield
      - BTS50010
      - :code:`hss-bts500xxShield-ino.hpp`
    * - Shield
      - BTS50015
      - :code:`hss-bts500xxShield-ino.hpp`

Description
^^^^^^^^^^^
BTS700x-1EPP and BTS5001x-1TAD Shields have optional user button to perform switching.
This example demonstrates the use of optional user button. This functionality is not included in the main example, because the button is not populated on the board by default.