@mainpage Viking Skull Lamp

__Introduction__

I have made this project for my brother. He asked me to create a Viking style lamp, that have a glowing skull. This is what come out from this idea.
The result came out pretty good I think, so I decided to share this project with the world. The device was finished in June of 2022 and I decided to
announce the design for the 2022 Halloween Contest on Printables.com. So I roughly had five month to test the device before publishing it. I can
happily say that in this period nothing went wrong with it, it just worked like a charm. Also I have worked a lot on the documentation in this time.
Here you can see what can this ting actually do:

\htmlonly

<p align="center"><iframe width="1024" height="786" src="https://www.youtube.com/embed/yvYET1PqnmI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></p>

\endhtmlonly

\htmlonly

<script type="module" src="https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js"></script>

<model-viewer src="assembly.glb" ar ar-modes="webxr scene-viewer quick-look" camera-controls poster="poster_assembly.png" shadow-intensity="1" environment-image="spruit_sunrise_1k_HDR.hdr" min-camera-orbit="auto 20deg auto" max-camera-orbit="auto 90deg auto">
    <div class="progress-bar hide" slot="progress-bar">
        <div class="update-bar"></div>
    </div>
    <button slot="ar-button" id="ar-button">
        View in your space
    </button>
    <div id="ar-prompt">
        <img src="https://modelviewer.dev/shared-assets/icons/hand.png">
    </div>
</model-viewer>


\endhtmlonly

Also there are some nice photos about the lighting in the @ref gallery "gallery".

I want to clarify at the beginning that this is not a beginner level project. It's more like a hardcore one.
If you love to create stuff and you are brave enough to start this journey, this documentation will guide you
through the whole assembly procedure. Before you start buying the components, please check the
@ref required_tools "required tools" page. It contains everything you need to create this device. If you doesn't
have a tool it will be clear at the beginning.

At the beginning I would say that I'm a human and I have made this whole thing on my own. I tried to not make mistakes in the
device or it's documentation, but mistakes happen. If you find a problem, our something does not understandable, please visit
the @ref issue_guide "issue guide" section. There is an example how to submit an issue, and I will try my best to fix them.

This journey consists of four stages. You have to start from the first and progress upwards.

1. \ref print_guide "3D Printing Parts:" Firstly, you have to print all the necessary parts. There are some tricky ones
so read the __print guide__ section carefully.

2. __PCB Assembly__

3. __Software Build / Upload__

4. __Mechanical Assembly__

<a href="Schematics.pdf" target="_blank"><b>Schematics</b></a>

<a href="gerber.zip" target="_blank"><b>Gerber files</b></a>

<a href="ibom.html" target="_blank"><b>Interactive BOM</b></a>

__Donation__

If this project help you reduce time to develop, you can give me a cup of coffee \emoji :coffee: \emoji :coffee: \emoji :coffee:

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate?hosted_button_id=YFGZD78H6K2CS)

__Contributing__

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

__license License & copyright__

© Daniel Hajnal

\emoji :email: hajnal.daniel96@gmail.com

Software is licensed under the __MIT__ License, the hardware and the mechanical parts are licensed under the __Creative Commons__ [BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/) license.
