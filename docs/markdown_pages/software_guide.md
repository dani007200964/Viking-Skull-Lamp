@page software_guide Software Guide

![Build Status](https://github.com/dani007200964/Viking-Skull-Lamp/actions/workflows/compile_test.yml/badge.svg?branch=main)

@section environment Environment

In this project, I used [Visual Studio Code](https://code.visualstudio.com/). It is an
open-source, multi-platform text editor, which has a lot of useful plugins. One of
those plugins is [PlatformIO](https://platformio.org/), which is a complete build system
for embedded devices. It is very easy to use and works very well.

__To make it work:__

__1.__ Download and install \emoji :package: [Visual Studio Code](https://code.visualstudio.com/)

![](platformio_install.png)

__2.__ Open VS Code and install the PlatformIO extension.

__3.__ Download the latest [release](https://github.com/dani007200964/Viking-Skull-Lamp/releases)
from the Viking Skull Lamp repository and unpack it somewhere on your machine.

__4.__ Open VS Code and follow the steps below.

![](vscode_open_pt1.png)

__5.__ Locate and open the __Software__ folder in the downloaded project folder.

![](vscode_open_pt2.png)

If everything went well, that's all, you can build and upload the firmware.

@section build_the_firmware Build The Firmware

![](vscode_build.png)

After the build finishes you should see a big green __[SUCCESS]__ on the console.

@section upload_the_firmware Upload The Firmware

@warning Do __NOT__ power the board from the USB and the power chord at the same
time! It can damage your board or your computer. If you upload the firmware use
the USB port only. If you use the device as intended of course you can use the
power chord.

![](vscode_upload.png)

@section modify_the_firmware Modify The Firmware

![Classes And Files](classes_files_section.png)

This is an open-source project, you can modify it as you like. The software
is no exception. I tried to comment it as much as possible to make it Doxygen compatible.
To understand the structure and the logic behind the source code, please check out
the __Classes__ and __Files__ section at the bottom left.
