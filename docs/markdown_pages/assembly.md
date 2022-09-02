@page assembly_instructions Assembly Instructions

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

@section mechanical_assembly Mechanical Assembly

@subsection step_1_rubber_feet Step 1 - Rubber Feet

![Rubber Feet](asm_stp001_rubber_feet.JPG)

@pre Required parts:
* __box_bottom_1pcs.stl__ - 1pcs
* __Rubber Feet__         - 4pcs

The four rubber feet has to glued to the bottom of the box.
Rubber feet, that I used can be found
[here](https://www.hestore.hu/prod_10030980.html?lang=en).

@subsection step_2_endstop_mount_prepare Step 2 - Endstop Mount Prepare

![Endstop Mount Prepare](asm_stp002_endstop_mount_prepare.JPG)

@pre Required parts:
* __right_endstop_mount_1pcs.stl__ - 1pcs
* __left_endstop_mount_1pcs.stl__  - 1pcs
* __M3 locknut__                   - 4pcs

Four M3 locknuts has to be pressed to the endstop mounts.

@subsection step_3_endstop_mount_screws Step 3 - Endstop Mount Screws

![Endstop Mount Screws](asm_stp003_endstop_mount_screws.JPG)

@pre Required parts:
* __M3 x 18mm Flat Head Screw__ - 4pcs

Four M3 x 18mm Flat Head Screw has to be inserted to the endstop mount holes.

@subsection step_4_insert_bearings Step 4 - Insert Bearings

![Insert Bearings](asm_stp004_insert_bearings.JPG)

@pre Required parts:
* __26 x 17 x 5mm Bearings__ - 4pcs

Insert four 26 x 17 x 5mm Bearings.

@subsection step_5_locking_endstop_mounts Step 5 - Locking Endstop Mounts

![Locking Endstop Mount](asm_stp005_locking_endstop_mount.JPG)

\emoji :orange_circle: Make shore, that the holes for the endstop switches are
looking __inwards__.

\emoji :purple_circle: Tighten the four screws, but __not so hard__, the bearings has
to move a bit sideways.

@subsection step_6_moving_platform_knobs Step 6 - Moving Platform Knobs

![Moving Platform Knobs](asm_stp005_moving_platform_knob.JPG)

@pre Required parts:
* __endstop_knob_2pcs.stl__ - 2pcs
* __moving_platform_1pcs.stl__ - 1pcs

Insert the two knobs to the rails on the moving platform.

@subsection step_6_moving_platform_knobs Step 6 - Moving Platform Knobs

![Moving Platform Knobs](asm_stp006_moving_platform_knob_screws.JPG)

@pre Required parts:
* __M3 x 16mm Regular Screw__ - 2pcs
* __M3 Nut ( Regular )__ - 2pcs

\emoji :orange_circle: Insert the two M3 nut to the back side of the moving platform.

\emoji :purple_circle: Tighten the two screws, but __not so hard__, the knobs has
to slide freely.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp006_demonstration.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

@note It has to slide freely like in the video above.

@subsection step_7_insert_encoder Step 7 - Insert Encoder

![Insert Encoder](asm_stp007_insert_encoder.JPG)

@pre Required parts:
* __Encoder with__ @ref encoder_cable "cable assembly" - 1pcs

Insert the encoder into the moving platform.

@subsection step_8_lock_encoder Step 8 - Lock Encoder

![Lock Encoder](asm_stp008_lock_encoder.JPG)

@pre Required parts:
* __M7 x 0.75mm__ [nut](https://www.hestore.hu/prod_10043306.html?lang=en) - 1pcs

Lock the encoder shaft with a nut. It has to be tighten.
