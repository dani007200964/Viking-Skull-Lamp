@mainpage Viking Skull Lamp

__Introduction__

I ​made this project for my brother. He loves Halloween and asked me to create a Viking-style lamp that has a glowing skull.
This is what comes out of this idea. I roughly had five months to test the device before publishing it. I can happily say
that in this period nothing went wrong with it. It just worked like a charm. Also, I have worked a lot on the documentation,
meanwhile. Here you can see what can this thing do. Also, there are some nice photos of the lighting in the @ref gallery "gallery".

\htmlonly


<p align="center"><iframe width="1024" height="786" src="https://www.youtube.com/embed/T2uH4yskYew" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></iframe></p>

\endhtmlonly

__Features:__
* 30 addressable LED to make it shine \emoji :rotating_light:
* Microphone for \emoji :studio_microphone:
  * Music reactive lighting \emoji :musical_note:
  * @ref clap_pattern "Clap switch" \emoji :clap:
* Foldable controls
* Interactive menu with a graphical display \emoji :joystick:
* Saving and loading the configuration parameters \emoji :floppy_disk:
* Light modes:
  * Rainbow \emoji :rainbow:
  * Candle \emoji :candle:
  * Pulse \emoji :loud_sound:
  * Komodo 3000 \emoji :sunny:
  * Color \emoji :art:
* Humidifier for spooky smoke effect \emoji :ghost:
* Magic runes on the front. They are glow-in-the-dark \emoji :star:

![](hardcore_logo.png)

I want to clarify at the beginning that this is not a beginner-level project. It's more like a hardcore one.
If you love to create stuff and you are brave enough to start this journey, this documentation will guide you
through the whole assembly procedure. Before you start buying the components, please check the
@ref required_tools "required tools" page. It contains everything you need to create this device. If you don't
have a tool, it will be clear at the beginning.

I tried to not make mistakes in the device or its documentation, but I'm just a regular person, sometimes
I make mistakes like everyone else do. If you find a problem or something does not understandable, please visit
the @ref issue_guide "issue guide" section. There is an example of how to submit an issue. If you report an issue
I will try my best to fix it.

This journey consists of five stages. You have to start from the first and progress upwards.

1. \ref components "Sourcing Components:" Firstly you have to source the required parts and materials.

2. \ref print_guide "3D Printing Parts:" Next, you have to print all the necessary parts. There are some tricky ones
so read the \ref print_guide "print guide" section carefully.

3. \ref pcb_assembly "PCB And Cable Assembly:" I have designed a custom PCB for this project. It expands the functionality of
the Arduino UNO platform. It controls all the peripherals in the system. The custom PCB was necessary to make the project
fit this size.

4. \ref software_guide "Software Guide:" Of course, this project has a custom firmware. It is written in C++ and I
have used PlatformIO as a development tool.

5. \ref assembly_instructions "Mechanical Assembly:" Finally it's time to assemble the whole thing.

__Donation__

If you like my work, and if it was useful for you, please consider buying me a coffee or tipping. \emoji :coffee: \emoji :coffee: \emoji :coffee:

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate?hosted_button_id=YFGZD78H6K2CS)

__Contributing__

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

__Used Resources:__

* [FastLED](https://github.com/FastLED/FastLED)
* [PlatformIO](https://platformio.org/)
* [Visual Studio Code](https://code.visualstudio.com/)
* [Atom](https://atom.io/)
* [Doxygen](https://doxygen.nl/manual/tables.html)
* [Doxygen Awesome Theme](https://github.com/jothepro/doxygen-awesome-css)
* [Graphviz](https://graphviz.org/)
* [FreeCAD](https://www.freecadweb.org/)
* [Blender](https://www.blender.org/)
* [Prusa Slicer](https://github.com/prusa3d/PrusaSlicer/releases)
* [Gimp](https://www.gimp.org/)
* [KiCad](https://www.kicad.org/)
* [Interactive HTML BOM](https://github.com/openscopeproject/InteractiveHtmlBom)
* [Inkscape](https://inkscape.org/)
* [OpenShot](https://www.openshot.org/)
* [<model-viewer>](https://modelviewer.dev/)

__License & Copyright__

© Daniel Hajnal

\emoji :email: hajnal.daniel96@gmail.com

Software is licensed under the __MIT__ License, and the hardware and the mechanical parts are licensed under the __Creative Commons__ [BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/) license.
