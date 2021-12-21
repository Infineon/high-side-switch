Porting Guide 
==============

Porting the library to a new software development framework and hardware
platform entails the implementation of the corresponding ADC, GPIO and Timer
PAL classes. In the following sections, some additional explanations and
hints are provided:

Framework PAL Implementation
----------------------------

Implement the abstract PAL interface for you framework. The **ADC
class**, **GPIO class** and **Timer class** are mandatory.

The Doxygen comments on the *“src/pal/hss-pal-adc.hpp”*, *“src/pal/hss-pal-gpio.hpp”*
and *“src/pal/hss-pal-timer.hpp”* describe the required behavior of each function
of the :ref:`PAL Interface <pal-intf>`.

Consider the existing framework implementations as reference examples
for you design: *“/src/framework/sample_fmwk/pal”*. Some of the
functions are optional depending on your framework and intended usage of
the library.

That is the case of *init()* and *deinit()*, which take care of the
hardware peripherals init/deinitialization. If this is done in your main
application (or somewhere else outside the library), there is no need of
delegating such initialization to the High-side Switch library. The definition
of these functions can just be a return with the success return code.

Framework API Wrapper
---------------------

The framework API wrapper implementation is optional, it is meant to
ease the usage. Mostly the main help is to avoid the creation of the
ADC, GPIO and Timer object instances for the developer.

To illustrate this approach, it is easier to evaluate a concrete
implementation of the Arduino wrapper. For example the constructor of
the *Hss* class, which can be found in the files
*“src/corelib/hss.cpp”*.

1. Adapt the constructor arguments to those used for the platform class
   creation (ADC, GPIO and Timer) in the new framework, using the native
   data types and structures. Hide what can be already defined for that
   platform and provide as much abstraction and simplicity as possible.

   For example, the core library of the base constructor is defined like
   this:

   .. code-block:: C
      
      Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant);

   is wrapped for Arduino like this:

   .. code-block:: C

      HssIno(uint8_t den, uint8_t in0, uint8_t in1, uint8_t dsel, uint8_t is, BtxVariants_t * btxVariant);

   While it does not seems to simplify much in number of arguments, an
   Arduino developer can simply pass the pin number as argument, and
   does not need to deal with the (probably unknown) GPIO classes,
   neither specify further GPIO configuration as the mode (input,
   output, pull-up..), positive/negative logic, etc.

   As for the constructor, the same philosophy can apply to other
   functions of the public API. In case of Arduino, as a hobbyist and
   makers environment, clarity and simplicity might prevail over
   configurability and functionality. Therefore, the :ref:`wrapper
   API <arduino-api>` further hides, group or eliminate certain
   functionalities.

   For each ecosystem and framework, any other criteria can be chosen,
   hopefully matching as well its code conventions, implementation
   principles and paradigms.

