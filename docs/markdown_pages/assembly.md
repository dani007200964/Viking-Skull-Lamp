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
* __Encoder With__ @ref encoder_cable "Cable Assembly" - 1pcs

Insert the encoder into the moving platform.

@subsection step_8_lock_encoder Step 8 - Lock Encoder

![Lock Encoder](asm_stp008_lock_encoder.JPG)

@pre Required parts:
* __M7 x 0.75mm__ [nut](https://www.hestore.hu/prod_10043306.html?lang=en) - 1pcs

Lock the encoder shaft with a nut. It has to be tighten.

@subsection step_9_slide_in_moving_platform Step 9 - Slide In The Moving Platform

![Slide In The Moving Platform](asm_stp009_slide_in_moving_platform.JPG)

Slide in the moving platform to the base. The four bearings has to slide in to the
sockets on the moving platform.

@subsection step_10_lock_endstop_mount_screws Step 10 - Lock Endstop Mount Screws

![Lock Encoder](asm_stp010_lock_endstop_mount_screws.JPG)

Lock the four endstop mount screws.

@note The moving platform has to move freely forward and backward, without any side wobble.

@subsection step_11_motor_shaft_thread_cutting Step 11 - Motor Shaft M3 Thread Cutting

![Motor Shaft M3 Thread Cutting](asm_stp011_motor_shaft_thread_cutting.JPG)

@pre Required parts:
* __eccetric_shaft_1pcs.stl__ - 1pcs

Insert the encoder into the moving platform.

@subsection step_12_eccentric_shaft_assembly Step 12 - Eccentric Shaft Assembly

![Eccentric Shaft Assembly](asm_stp012_eccentric_shaft_assembly.JPG)

@pre Required parts:
* __eccetric_shaft_1pcs.stl__ - 1pcs
* __M3 x 12mm Flat Head__ - 1pcs
* __7mm OD, 3.6mm ID 8mm Height__ [Spacer](https://www.hestore.hu/prod_10024539.html) - 1pcs

Assemble the eccentric shaft as seen on the picture above.

@subsection step_13_insert_motor_screws Step 13 - Insert Motor Screws

![Insert Motor Screws](asm_stp013_insert_motor_screws.JPG)

@pre Required parts:
* __motor_mount_1pcs.stl__ - 1pcs
* __M1.6 x 5mm Flat Head__ [Screw](https://www.tme.com/us/en-us/details/b1.6x5_bn661/bolts/bossard/5512816/) - 2pcs

Insert the two screws into the motor mount.

@subsection step_14_lock_motor_screws Step 14 - Lock The Motor Screws

![Tighten Motor Screws](asm_stp014_lock_motor_screws.JPG)

@pre Required parts:
* __Motor With__ @ref motor_cable "Cable Assembly" - 1pcs

Tighten the two screws of the motor.

@subsection step_15_insert_motor_mount_nuts Step 15 - Insert Motor Mount Nuts

![Insert Motor Mount Nuts](asm_stp015_insert_motor_mount_nuts.JPG)

@pre Required parts:
* __M3 locknut__ - 2pcs

Insert the nuts to the slots on the motor mount.

@subsection step_16_press_the_eccentric_shaft Step 16 - Press The Eccentric Shaft To The Motor

![Press The Eccentric Shaft](asm_stp016_press_the_eccentric_shaft.JPG)

@pre Required parts:
* @ref step_12_eccentric_shaft_assembly "Eccentric Shaft Assembly" - 1pcs

Press the eccentric shaft to the motor shaft.

@subsection step_17_insert_the_motor_mount Step 17 - Insert The Motor Mount

![Insert The Motor Mount](asm_stp017_insert_the_motor_mount.JPG)

@pre Required parts:
* __M3 x 10mm Flat Head__ - 2pcs

Insert the motor mount to the base. From the bottom insert two M3 x 10mm flat head crews.
Tighten the two screws, but __not so hard__, the motor mount has to slide back and forward freely.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp017_demonstration.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

@subsection step_18_insert_power_jack Step 18 - Insert Power Jack

![Insert Power Jack](asm_stp018_insert_power_jack.JPG)

@pre Required parts:
* @ref power_connector_cable "Power Cable Assembly" - 1pcs

Insert the power jack to the slot on the back side.

@subsection step_19_lock_power_jack Step 19 - Lock Power Jack

![Lock Power Jack](asm_stp019_lock_power_jack.JPG)

Lock the power jack with it's nut. A tweezer can be helpful for this operation.

@subsection step_20_insert_endstops Step 20 - Insert Endstops

![Insert Endstops](asm_stp020_insert_endstops.JPG)

@pre Required parts:
* __M2.3 x 10mm Regular__ [Screws](https://www.tme.com/us/en-us/details/b2.3x10_bn330/bolts/bossard/1123106/) - 4pcs
* __Front Endstop__ @ref front_endstop_cable "Cable Assembly" - 1pcs
* __Back Endstop__ @ref back_endstop_cable "Cable Assembly" - 1pcs

Fix the endstops with the screws. The screw has to cut thread to the plastic,
it require some force.

@note Check the orientation of the endstops!

@subsection step_21_insert_pcb_screws Step 21 - Insert PCB Screws

![Insert Endstops](asm_stp021_insert_pcb_screws.JPG)

@pre Required parts:
* __M3 x 30mm Flat Head Screw__ - 1pcs
* __M3 x 16mm Flat Head Screw__ - 3pcs

\emoji :orange_circle: M3 X 16mm screws.

\emoji :purple_circle: M3 X 30mm screw.

@subsection step_22_insert_arduino Step 22 - Insert Arduino

![Insert Arduino](asm_stp022_insert_arduino.JPG)

@pre Required parts:
* __Arduino Uno__ [R3](https://store.arduino.cc/products/arduino-uno-rev3) - 1pcs

Insert an Arduino UNO __R3__ to the base.

@subsection step_23_insert_pcb_spacers Step 23 - Insert Threaded PCB Spacers

![Insert Threaded PCB Spacers](asm_stp023_insert_pcb_spacers.JPG)

@pre Required parts:
* __M3 x 12mm__ [Spacer](https://www.tme.com/us/en-us/details/dr185rdm3x12/plastic-standoffs/dremec/185rdx12/) __With 6mm OD__ - 3pcs

Insert the spacers and tighten them.

@subsection step_24_insert_printed_pcb_spacer Step 24 - Insert Printed PCB Spacer

![Insert Printed PCB Spacer](asm_stp024_insert_printed_pcb_spacer.JPG)

@pre Required parts:
* __pcb_spacer_corner_1pcs.stl__ - 1pcs

Insert the spacer.

@note Check the orientation!

@subsection step_25_insert_viking_pcb Step 25 - Insert Techno Viking PCB

![Insert Techno Viking PCB](asm_stp025_insert_viking_pcb.JPG)

@pre Required parts:
* __Techno Viking PCB__ - 1pcs

Insert the PCB to the Arduino UNO.

@note Gently push the Techno Viking Board to the Arduino UNO.
