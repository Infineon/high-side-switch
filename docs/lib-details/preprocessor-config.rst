Preprocessor Configuration
========================== 
The *src/config* sources provides the C-macro level library configuration.

Through defines configuration the different modules of the library are conditionally compiled. Thus, only the code needed is added to the binary. The main selectable parameters are:

* **Logger**. The entire logger and the individual software modules and/or debugging level traces can be enabled or disable via these macro group.

Config Files
""""""""""""

The configuration folder includes 3 files:

* *bgt60-conf.hpp*: This is the actual configuration file.
* *bgt60-conf-opts.hpp*: All the library configuration macro define options.
* *bgt60-conf-dfl.hpp*: This is the default configuration. This file is included (```#include```) in the *bgt60-conf.hpp*. If any optional parameter is not defined, then the default value will be set in this file. If any user selectable mandatory configuration is not set, an error will be thrown during compilation, requesting the definition of such parameter.