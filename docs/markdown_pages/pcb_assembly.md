@page pcb_assembly PCB Assembly

@section how_to_get_the_pcb How To Get The PCB

This is a tricky question. If you never made a PCB and you doesn't want to try it, maybe I can help, but it's not shore.
I can make a few in a month but it's depending on my free time, and suppliers( shortage... ). If you are in trouble
with the PCB you can contact me and I will try to help.

The other option is to create the PCB for yourself. It is not that hard actually, you need a good soldering iron and a
tweezer. There are a ton of videos about soldering online, but here is my preferred one:

\htmlonly

<iframe width="1024" height="786" src="https://www.youtube.com/embed/VxMV6wGS3NY" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

\endhtmlonly

You also need some naked PCB panels, I highly recommend [JLCPCB](https://jlcpcb.com/). It is cheap and fast.
The quality for this price is very good, and the interface is simple. Just upload the <a href="gerber.zip" target="_blank"><b>gerber file</b></a>
and fill the settings as shown below:

![JLCPCB Settings](jlc_settings.png)

@note Please check the settings twice. A wrong setting can be a huge difference in price!

@section how_to_get_the_right_components How To Get PCB Components

The whole PCB is designed with [KiCad](https://www.kicad.org/) and it has a very useful plugin
called [Interactive HTML BOM](https://github.com/openscopeproject/InteractiveHtmlBom).
This plugin generates a browser based interactive tool, where you can find all the components
needed for the board. Also it shows where those components shall be placed on the PCB.

\htmlonly

<iframe src="ibom.html" style="height:800px;width:100%;" title="description"></iframe>

\endhtmlonly

@note On smaller monitors you may open this document <a href="ibom.html" target="_blank"><b>separately</b></a>.

Of course if you doesn't like the browser version of the BOM, you can open the whole project with
KiCad.

@section schematic Schematics

This section explains the different modules ant their job on the panel. You can skip this part if you
are not interested in circuit design.

\htmlonly

  <embed src="Schematics.pdf#toolbar=0" width="100%" height="800px">

\endhtmlonly

@note On smaller monitors you may open this document <a href="Schematics.pdf" target="_blank"><b>separately</b></a>.

@subsection analog_stage Analog Stage

__This part consists of seven amplifier stages:__

1. __Microphone Preamplifier:__ The condenser microphone generates a very low signal. This stage amplifies this signal
to make it useable for the other stages. Also this amplified signal is connected to the A3 ADC channel by default.
2. __Half-Wave Rectifier:__ This stage consumes two amplifiers. In this configuration it is a peak detector. The software
is using this signal to detect the noise floor of the environment. It is connected to A2 ADC channel.
3. __Low-Pass Filter:__ This stage attenuates frequency components above 500Hz. It could be used for something, but
this signal is not used by default. If you want, you can switch the state of JP1 and JP2 jumpers to use this channel.
In this way it will be connected to A3 ADC channel instead of the preamplifier output.
4. __High-Pass Filter:__ This stage attenuates frequency components below 2000Hz. It is connected to A1 ADC channel.
5. __Band-Pass Filter:__ The last stage consumes two amplifiers. It has a pass band between 500Hz and 2000Hz. That
means it passes all frequency components in this range, but outside this band it attenuates.

@subsection half_supply_generator Half-Supply Generator

This part generates exactly half of the supply voltage. The filters need a reference voltage between the power rails
to swing the output voltage up and down. This is why we need a half-supply generator. Also this means that the filters
output voltage is shifted to half supply onstead of 0V.

@subsection power_input Power Input

This section is responsible to supply the circuits safely. It has a thermal fuse, a TVS diode and a polarity protection.
I tried to make this as safe as possible.

@subsection endstops Endstops

The endstops are jus simple switches, they have to be debounced. This simple part does this job.

@subsection buzzer_driver Buzzer Driver

The panel has a small buzzer. It is useful to create some interaction when you navigate in the menu. This section consists
a transistor, that drives the buzzer, and some power filtering. The driver-stage have a protection diode, so both
electromechanical and piezoelectric buzzers can be used.

@subsection display_interface Display Interface

This is just a connector for the display cable with two pull-up resistors for the I2C signals. It also has some power filtering.

@subsection dc_motor_driver DC-Motor Driver

The circuit is exactly the same as the buzzer driver. It's job is to drive the motor.

@subsection humidifier_switch Humidifier Switch

The circuit is exactly the same as the buzzer driver. It's job is to turn on or off the humidifier module.

@subsection led_interface LED Interface

This contains two connectors for the two LED strips and some power filtering. It also has some series resistance, that required
to use WS2812 and WS2813 chips properly.

@subsection encoder_interface Encoder Interface

The encoder is basically three switch, they has to be debounced. This section does this.

@section pcb_test PCB Test

1. After you have assembled the PCB it is necessary to test it, before connecting it to the Arduino.
This is the smoke test. The best method is to have a bench power supply, and power the board up with
5V at 100mA current limit. The power LED should turn on, and the current consumption should be less
than 50mA( for just the bare PCB ).
2. If the smoke test succeeds it's time to connect the PCB to the Arduino UNO and upload the firmware
to it. If you can program the Arduino without a problem that is a good sign.
3. Lastly you have to connect all the peripherals to the board and try them before the final assembly.
For this step you need all the @ref cable_preparation "peripherals and cables to be prepared". Every
connector is labeled on the PCB, so you can find the right one for each peripheral easily.
4. If everything works, you can jump to the @ref assembly_instructions "final assembly".

@note If the smoke test fails, and the current consumption is high, you probably assembled one or more components wrong.
To identify the problem, there are some practices. For example if something blows up, it has to be replaced without
a question. Also if a component gets hot for a touch it is probably dead, I recommend replacement. Also check the
IC-s and silicon based components orientation. If they are soldered in a wrong orientation they usually die at power up.

@section cable_preparation Cable Preparation

@subsection power_connector_cable Power Connector Cable

![Power Connector Cable](power_conn_cable.JPG)

Cable length from the connector to the end sleeves is approximately __110mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the ends have cable end sleeves.
The connector, that I used can be found [here](https://www.hestore.hu/prod_10038660.html?lang=en).

@warning Always check the polarity with a multimeter, before connecting to the PCB!
Best practice is to mark the cable with a label printer or some kind of sticker.

@subsection humidifier_cable Humidifier Cable

![Humidifier Cable](humidifier_cable.JPG)

Cable length from the humidifier to the end connector is approximately __140mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-2 JST connector.
The connector, that I used can be found [here](https://www.tme.com/us/en-us/details/phr-2/raster-signal-connectors-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

![Humidifier Back](humidifier_back.JPG)

The polarity is marked at the back side of the humidifier board. Also a little solder bridge
has to be made to turn on the humidifier without button press.
Humidifier module, that I used can be found
[here](https://www.hestore.hu/prod_10041539.html?lang=en).

@warning Always check the polarity with a multimeter, before connecting to the PCB!
Best practice is to mark the cable with a label printer or some kind of sticker.

@subsection led_disc_cable LED Disc Cable

![LED Disc Cable](led_disc_cable.JPG)

![LED Disc Connector](led_disc_connector.JPG)

Cable length from the LED disc to the end connector is approximately __160mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-3 JST connector.
The connector, that I used can be found [here](https://www.tme.eu/hu/details/phr-3/jelcsatlakozok-raszter-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

@note The cable has to be soldered to the bottom of the LED disc. The bottom side has SMD solder terminals
where the cable has to be soldered. They are labeled, so it's easy to identify the wires. There is an input
and an output connector, the input one has to be used.

LED disc, that I used can be found
[here](https://www.hestore.hu/prod_10037905.html?lang=en).

@subsection led_strip_cable LED Strip Cable

![LED Strip Cable](led_strip_cable.JPG)

![LED Strip Connector](led_strip_connector.JPG)

Cable length from the LED strip to the end connector is approximately __130mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-3 JST connector.
The connector, that I used can be found [here](https://www.tme.eu/hu/details/phr-3/jelcsatlakozok-raszter-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

@note The LED strip has to be cut to length with 27 LEDs. The wires has to be soldered.
If the strip made with WS2813 LEDs, the BI ( Backup Input ) pin has to soldered to ground.
Also a __470uF 10V capacitor__ has to soldered to the input across __VCC__ and __GND__
on the strip to stabilize the power rail. The width of the capacitor has to be equal or
less than the LED strip( whisch is 10mm ).

@warning The polarity of the capacitor has to be correct, otherwise it will blow up.

LED strip, that I used can be found
[here](https://www.tme.com/us/en-us/details/hcbaa60wg/light-sources-led-ribbon/worldsemi/hc-f5v-60l-60led-w-ws2813-ip65/).

@subsection oled_display_cable Oled Display Cable

![Oled Display Cable](oled_cable.JPG)

![Oled Display Connector](oled_connector.JPG)

Cable length from the Oled display to the end connector is approximately __210mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-4 JST connector.
The connector, that I used can be found [here](https://www.tme.eu/hu/details/phr-4/jelcsatlakozok-raszter-2-00mm/jst/).
The display side of the cable also has a connector, it can be found
[here](https://www.tme.com/us/en-us/details/nsr-04/pin-headers/ninigi/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

Oled display module, that I used can be found
[here](https://www.hestore.hu/prod_10040388.html?lang=en).

@subsection encoder_cable Encoder Cable

![Encoder Cable](encoder_cable.JPG)

![Encoder Connector](encoder_connector.JPG)

Cable length from the encoder to the end connector is approximately __200mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-5 JST connector.
The connector, that I used can be found [here](https://www.tme.eu/hu/details/phr-5/jelcsatlakozok-raszter-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

Encoder module, that I used can be found
[here](https://www.hestore.hu/prod_10043306.html).

@note On the encoder side, the wires has to be soldered to the pins on the encoder module.
Use heat-shrink tubes to isolate the wires from each other.

@subsection front_endstop_cable Front Endstop Cable

![Front Endstop Cable](front_endstop.JPG)

Cable length from the front endstop to the end connector is approximately __155mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-2 JST connector.
The connector, that I used can be found [here](https://www.tme.com/us/en-us/details/phr-2/raster-signal-connectors-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

@note Because it is a mechanical switch, the polarity on the connector doesn't matter.

Endstop switch, that I used can be found
[here](https://www.tme.eu/hu/details/ss-5gl2t/mikrokapcsolok-snap-action/omron-ocb/).

@subsection back_endstop_cable Back Endstop Cable

![Back Endstop Cable](back_endstop.JPG)

Cable length from the back endstop to the end connector is approximately __155mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-2 JST connector.
The connector, that I used can be found [here](https://www.tme.com/us/en-us/details/phr-2/raster-signal-connectors-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

@note Because it is a mechanical switch, the polarity on the connector doesn't matter.

Endstop switch, that I used can be found
[here](https://www.tme.eu/hu/details/ss-5gl2t/mikrokapcsolok-snap-action/omron-ocb/).

@subsection motor_cable Back Motor Cable

![Motor Cable](motor_cable.JPG)

Cable length from the motor to the end connector is approximately __105mm__,
the cable is __0.22mm2 ( 24 AWG )__, and the end have a PHR-2 JST connector.
The connector, that I used can be found [here](https://www.tme.com/us/en-us/details/phr-2/raster-signal-connectors-2-00mm/jst/).
Crimping tool for the connector, that I used can be found
[here](https://www.tme.com/us/en-us/details/fut.pa-09/crimping-tools-for-terminals/engineer/pa-09/).

@note Because the mechanical construction of the open mechanism, the polarity on the connector doesn't matter.

DC motor, that I used can be found
[here](https://www.hestore.hu/prod_10042774.html?lang=en).
