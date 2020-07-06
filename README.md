# Smart High-Side Switch

[![Build Status](https://travis-ci.com/Infineon/high-side-switch.svg?branch=master)](https://travis-ci.com/github/Infineon/high-side-switch)

C++ library for Infineon's Arduino shield SHIELD_BTS700x-1EPP with the **Smart High-Side Power Switch BTS700x-1EPP**

## Supported Hardware

### SHIELD_BTS7002-1EPP
The library has been customized for the Arduino-Adapter-Shield ***SHIELD_BTS700x-1EPP*** and for the Arduino environment. It works with all available versions of the board (SHIELD_BTS7002-1EPP, SHIELD_BTS7004-1EPP, SHIELD_BTS7006-1EPP, SHIELD_BTS7008-1EPP).

<img src="docs/img/Profet+2.png" width="250px">

A detailed explanation of the board and its features can be found in the [user manual](https://www.infineon.com/dgdl/Infineon-PROFET+2_12V_Arduino_Shield-UserManual-v01_00-EN.pdf?fileId=5546d4626df6ee62016dfe3f1eff118b). The user manual also contains the pinout as well as the schematics of the board. The data sheet of the BTS7002-1EPP can be found [here](https://www.infineon.com/dgdl/Infineon-BTS7002-1EPP-DataSheet-v01_04-EN.pdf?fileId=5546d4626eab8fbf016ead699aef00b3).

### Verified Hardware
The shield is designed to be directly stacked on boards which have the Arduino UNO form factor.
Therefore, the library has been built and successfully deployed to the following platforms:

MCU Platforms |
---           |
[XMC1100 Boot Kit](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc11_boot_001/#ispnTab1) |
[Arduino Uno Rev3](https://store.arduino.cc/arduino-uno-rev3) |

### Additional hardware platforms
The library should be directly compatible with other platforms that support the Arduino API (Arduino reference language). The library is also written in a way that porting the library to another platform requires the developer only to provide a API for the specific platform, using the platform specific low level drivers. A porting guide is available in the [Wiki](https://github.com/Infineon/high-side-switch/wiki).

## Software documentation
A detailed explanation of the software structure as well as the API can be found [here](https://github.com/Infineon/high-side-switch/wiki/Library-Details). And there is also a ***Doxygen-File*** available, which can be found [here](https://infineon.github.io/high-side-switch/).

## More information
The complete documentation of the library as well as detailed information about the PROFET-shield, can be found in the [Wiki](https://github.com/Infineon/high-side-switch/wiki).

## License
This project is licensed under the MIT License - click [here](https://github.com/Infineon/high-side-switch/blob/master/LICENSE) for details.


