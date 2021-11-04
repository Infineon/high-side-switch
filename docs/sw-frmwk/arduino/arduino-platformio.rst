.. _arduino-platformio:

Arduino & PlatformIO
====================

Introduction
------------
If you are new to PlatformIO, download and install Visual Studio Code first and then the PlatformIO plugin. Please follow the instructions on the `official website`_. Then go through `this tutorial`_ to get started with PlatformIO in VSCode and create a new project.

.. _`official website`: https://docs.platformio.org/en/latest/integration/ide/pioide.html
.. _`this tutorial`: https://diyprojects.io/install-ide-platformio-extension-visual-studio-code-vscode-windows-32-bit-linux/#.XOVQP44zYnI

Library Installation
--------------------
With the project created, now the library and its dependencies can be configured in the Platform.ini Project File. This file, located in the project root folder, includes one(or several) building environments [env:__].

In the environment section, the platform, board, and framework are specified. PlatformIO will take care of downloading and installing the dependencies.

In the following example, we use ...

.. code-block::
    
    [evn:mkr1000USB]
    platform = atmelsam
    board = mkr1000USB
    framework = arduino

    lib_deps=
    # Using a library name
    radar-bgt60

    # Using the repository URL
    https://github.com/Infineon/radar-bgt60.git#master

You can also simply take the ``platform.ini`` file from the `arduino-radar-bgt60 repo`_. This file includes all settings for using this library with different platforms.

.. _`arduino-radar-bgt60 repo`: https://github.com/Infineon/arduino-radar-bgt60