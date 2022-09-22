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

Cut an M3 thread to the hole on the side.

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
* __M3 Locknut__ - 2pcs

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

@subsection step_26_insert_plastic_washer_pcb Step 26 - Insert Plastic Washer

![Insert Plastic Washer](asm_stp026_insert_plastic_washer_pcb.JPG)

@pre Required parts:
* __M3 x 0.5mm Plastic Washer__ - 1pcs

Insert the plastic washer to the screw.

@subsection step_27_lock_pcb Step 27 - Lock The PCB

![Lock The PCB](asm_stp027_lock_pcb.JPG)

@pre Required parts:
* __M3 Locknut__ - 1pcs

Lock the screw with a nut.

@subsection step_28_insert_other_pcb_washers Step 28 - Insert Plastic Washer

![Insert Plastic Washer](asm_stp028_insert_other_pcb_washers.JPG)

@pre Required parts:
* __M3 x 0.5mm Plastic Washer__ - 3pcs

Insert the remaining plastic PCB washers.

@subsection step_29_lock_pcb_screws Step 29 - Lock PCB Screws

![Lock PCB Screws](asm_stp029_lock_pcb_screws.JPG)

@pre Required parts:
* __M3 x 5mm Regular Screw__ - 3pcs

Lock the PCB with the screws.

@subsection step_30_glue_display_holder Step 30 - Glue Display Holder

![Lock PCB Screws](asm_stp030_glue_display_holder.JPG)

@pre Required parts:
* __display_holder_base_with_art_1pcs.stl__ - 1pcs
* __display_holder_front_with_art_1pcs.stl__ - 1pcs
* __Super Glue__

Glue the front to the base part of the display holder.

@note Check the orientation before gluing!

@subsection step_31_glue_magnet_holder Step 31 - Glue Magnet Holder

![Glue Magnet Holder](asm_stp031_glue_magnet_holder.JPG)

@pre Required parts:
* __front_panel_magnet_holder_1pcs.stl__ - 1pcs
* __10mm x 3mm__ [Neodymium Magnet](https://www.tme.com/us/en-us/details/gn55.2-nd-10-3/magnets/elesa-ganter/gn-55-2-nd-10-3/) - 1pcs
* __Super Glue__

Glue the magnet into the magnet holder.

@subsection step_32_insert_front_nuts Step 32 - Insert Front Nuts

![Lock PCB Screws](asm_stp032_insert_front_nuts.JPG)

@pre Required parts:
* __box_front_with_art_1pcs.stl__ - 1pcs
* __M3 Locknut__ - 2pcs

Insert the nuts, to the slots on the front panel.

@subsection step_33_display_holder_thread Step 33 - Display Holder Thread Cut

![Display Holder Thread Cut](asm_stp033_display_holder_thread.JPG)

@pre Required parts:
* @ref step_30_glue_display_holder "Display Holder Assembly" - 1pcs
* __M3 Thread Cutter__

Cut an M3 thread both sides of the display holder.

@note Be gentle when cutting the thread. If you cut too fast, the plastic can melt or the cutter can break.

@subsection step_34_insert_display_holder_screws Step 34 - Insert Display Holder Screws

![Insert Display Holder Screws](asm_stp034_insert_display_holder_screws.JPG)

@pre Required parts:
* __M3 x 8mm Imbus Head Screw__  - 1pcs
* __M3 x 16mm Imbus Head Screw__ - 1pcs
* @ref step_33_display_holder_thread "Display Holder Assembly" - 1pcs
* @ref step_32_insert_front_nuts "Front Assembly" - 1pcs

__1.__ Insert the display holder to the front panel.

__2.__ Insert the screws from inside of the display holder.

\emoji :orange_circle: M3 x 16mm screw

\emoji :purple_circle: M3 x 8mm screw

@note Check the orientation of the slot on the front panel and the slot on the display.

@subsection step_35_insert_display_holder_nuts Step 35 - Insert Display Holder Nuts

![Insert Display Holder Nuts](asm_stp035_insert_display_holder_nuts.JPG)

@pre Required parts:
* __M3 Locknut__ - 2pcs

Tighten the screws with an __Allen Key__ from the inside.

@note They have to be tight but __not overtight__! The display holder has to
rotate freely.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp035_demonstration.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

@subsection step_36_insert_display_holder_magnet Step 36 - Insert Display Holder Magnet

![Insert Display Holder Magnet](asm_stp036_insert_display_holder_magnet.JPG)

@pre Required parts:
* __10mm x 3mm__ [Neodymium Magnet](https://www.tme.com/us/en-us/details/gn55.2-nd-10-3/magnets/elesa-ganter/gn-55-2-nd-10-3/) - 1pcs

Insert the magnet in the slot on the display holder.

@note __Do NOT glue the magnet!__ It will be glued in the next steps.

@subsection step_37_insert_display_holder_knobs Step 37 - Insert Display Holder Knobs

![Insert Display Holder Knobs](asm_stp037_insert_display_holder_knobs.JPG)

@pre Required parts:
* __short_screw_spacer_1pcs.stl__ - 1pcs
* __long_screw_spacer_1pcs.stl__  - 1pcs
* __M3 x 8mm Imbus Head Screw__   - 2pcs

Fix the knobs to the display holder.

\emoji :orange_circle: Short spacer

\emoji :purple_circle: Long spacer

@subsection step_38_test_magnets Step 38 - Test Magnets

![Test Magnets](asm_stp038_test_magnets.JPG)

@pre Required parts:
* __Super Glue__

Insert the magnet holder to the slot on the front panel.

@note If the polarity of the magnets are correct, you should see that, the display holder closes itself.
The magnet on the front panel, should __push up__ the magnet inside the display holder.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp038_demonstration.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

If the magnet polarity wrong, just flip the magnet inside the display holder and try it again.

After you have tested the display holder and it's working fine, you can glue the magnet holder
into the front panel, and the magnet inside the display holder.

@subsection step_39_peel_off_display_cover Step 39 - Peel Off Display Cover

![Peel Off Display Cover](asm_stp039_peel_off_display_cover.JPG)

Peel off the protecting foil from the oled display.

@subsection step_40_insert_display Step 40 - Insert Display

![Insert Display](asm_stp040_insert_display.JPG)

Insert the oled display into the display holder.

@note Check the orientation of the display cable.

@subsection step_41_insert_display_clamps Step 41 - Insert Display Clamps

![Insert Display Clamps](asm_stp041_insert_display_clamps.JPG)

@pre Required parts:
* __display_clamp_2pcs.stl__ - 2pcs

Insert the clamps into the display holder.

@subsection step_42_rotate_shaft_back Step 42 - Rotate Shaft Back

![Rotate Shaft Back](asm_stp042_rotate_shaft_back.JPG)

Slowly rotate the eccentric shaft to the back position.

@subsection step_43_insert_front Step 43 - Insert Front

![Insert Front](asm_stp043_insert_front.JPG)

Gently slide the front to the base.

@note The tolerances are tight, but it should slide in with a bit force. If it
doesn't, clean up the parts with an exacto knife.

![Result](asm_stp043_result.JPG)

It should look like this.

@subsection step_44_lock_front Step 44 - Lock Front

![Lock Front](asm_stp044_lock_front.JPG)

@pre Required parts:
* __M3 x 12mm Flat Head Screw__ - 2pcs

Tighten the screws on the bottom to lock the front panel.

@subsection step_45_rotate_shaft_front Step 45 - Rotate Shaft Front

![Rotate Shaft Front](asm_stp045_rotate_shaft_front.JPG)

Slowly rotate the eccentric shaft to the front position.

@subsection step_46_push_motor_mount_front Step 46 - Push Motor Mount Front

![Push Motor Mount Front](asm_stp046_push_motor_mount_front.JPG)

Gently push the motor mount to the front. We have to find absolute front position.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp046_demonstration.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

@subsection step_47_lock_motor_mount Step 47 - Lock Motor Mount

![Lock Motor Mount](asm_stp047_lock_motor_mount.JPG)

Tighten the screws from the motor mount __while the motor mount is pushed to the front position__

If you power the motor with a bench supply( no more than __5V__, and __300mA__ ),
and crank up the voltage slowly, you should see that the mechanism opens and closes.

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp047_test.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

@note Sorry for the color mismatch, the video captured from an early prototype.
The expected behaviour is the same.

* If the mechanism stuck at opening, that means the motor mount is set the wrong
position, it has to be adjusted. You have to push it a bit to the back.
* If the mechanism opens and closes, but the display doesn't open fully, that
means the motor mount is set the wrong position, it has to be adjusted. You have
to push it a bit to the front.

@subsection step_48_adjust_back_estop_knob Step 48 - Adjust Back Endstop Knob

![Adjust Back Endstop Knob](asm_stp048_adjust_back_estop_knob.JPG)

1. Slowly rotate the eccentric shaft to the back position.
2. Adjust the back endstop knob position. It has to just click when the mechanism
arrives to the back position.
3. Tighten the screw to fix the knob.

@subsection step_49_adjust_font_estop_knob Step 49 - Adjust Front Endstop Knob

![Adjust Front Endstop Knob](asm_stp049_adjust_front_estop_knob.JPG)

1. Slowly rotate the eccentric shaft to the front position.
2. Adjust the front endstop knob position. It has to just click when the mechanism
arrives to the front position.
3. Tighten the screw to fix the knob.

@subsection step_50_connect_wires Step 50 - Connect Wires

![Connect Wires](asm_stp050_connect_wires.JPG)

![Pinout](asm_stp050_pinout.png)

\emoji :orange_circle: Back endstop

\emoji :purple_circle: Front endstop

\emoji :large_blue_circle: Encoder

\emoji :green_circle: Motor

\emoji :yellow_circle: Input power \emoji :warning: __Check the polarity!__

\emoji :red_circle: Oled display.

@note If the oled display cable won't fit easily, it is recommended to unscrew the
Techno Viking PCB to access the oled display cable connector. After the display
cable connected the PCB put back to it's place.

@subsection step_51_oled_cable_tie Step 51 - Oled Cable Tie

![Oled Cable Tie](asm_stp051_oled_cable_tie.JPG)

Secure the display cable with a cable tie.

@note Make shore that the cable have enough room to move back and forward after
it has been tied.

![Base Cables](asm_stp051_result.JPG)

The wiring should look like this.

@subsection step_52_encoder_knob Step 52 - Encoder Knob

![Encoder Knob](asm_stp052_encoder_knob.JPG)

@pre Required parts:
* __encoder_knob_with_art_1pcs.stl__ - 2pcs

Insert the encoder knob to the encoder shaft.

@note The encoder knob model is designed to fit multiple length encoder shafts.
Maybe it can be pushed further than it should. In this case, insert some cotton
swabs into the hole in the knob until it's internal length is perfect.

@subsection step_53_upload_software Step 53 - Upload Software

Now it's time to upload the software to the board. After it finished you can check the
functionality of the mechanism by double pressing the encoder button. Also the display
should work. Maybe some adjustment on the endstop knobs are required.
__Do not continue until the mechanism and the display does not work correctly!__

@subsection step_54_led_holder_nuts Step 54 - Insert LED Holder Nuts

![Insert LED Holder Nuts](asm_stp054_led_holder_nuts.JPG)

@pre Required parts:
* __led_holder_1pcs.stl__ - 1pcs
* __M3 Locknut__          - 5pcs
* __M3  Regular Nut__     - 4pcs

Insert the nuts into their slots.

\emoji :orange_circle: Regular nut

\emoji :purple_circle: Locknut

@note On the photo I have used locknuts everywhere. It was a mistake.

@subsection step_55_insert_led_ring_mount Step 55 - Insert LED Ring Mount

![Insert LED Ring Mount](asm_stp055_insert_led_ring_mount.JPG)

@pre Required parts:
* __led_ring_mount_1pcs.stl__ - 1pcs

Insert the LED ring mount to the LED holder.

@subsection step_56_insert_cotton_swab Step 56 - Insert Cotton Swab

![Cotton Swab From Ear Stick](asm_stp056_cotton_swab_ear_stick.JPG)

![3mm Long Cotton Swab Rod](asm_stp056_cotton_swab_rod.JPG)

@pre Required parts:
* __azomizer_socket_1pcs_PETG.stl__ - 1pcs
* __Cotton Swab__                   - 1pcs

@note Some humidifier modules come with a cotton swab rod, some don't.
If your does not contain it, you can use an ear cleaning stick, and use
the cotton swab from it. If your module come with a cotton swab rod,
you have to cut exactly __3mm__ long peace of it with an exacto knife.

Insert the cotton swab to the center slot on the atomizer socket.

@subsection step_57_insert_atomizer Step 57 - Insert Atomizer

![Insert Atomizer](asm_stp057_insert_atomizer.JPG)

@pre Required parts:
* __20mm Ceramic Humidifier Transducer With Silicone Housing__ - 1pcs

Insert the atomizer to the socket on the atomizer socket.

@note Check the wire orientation. It has to slide into the slot on the atomizer socket.

@warning Do __NOT__ use any glue or sealant. It could clog the return path and the humidifier
wont work. Trust me I have tried it...

@subsection step_58_fix_atomizer_socket Step 58 - Fix Atomizer Socket

![Fix Atomizer Socket](asm_stp058_fix_atomizer_socket.JPG)

@pre Required parts:
* __M3 x 20mm Flat Head Screw__ - 5pcs
* __M3 Locknut__                - 4pcs

\emoji :purple_circle: Tighten the screws using a __star pattern__. If it's too loose, it will leak.

\emoji :orange_circle: Insert the nuts to the slots.

@note Check the wire during the process. It can stuck between the two surfaces.

@subsection step_59_humidifier_pcb_holes Step 59 - Humidifier PCB Holes

@pre Required parts:
* __3.2mm Drill Bit__

I have bought a few humidifier module and the hole positions were different for each.
If your modules hole positions are different, lock the board to one hole and drill
another one. To fix the humidifier PCB, at least two screws are required.

@subsection step_60_humidifier_pcb_screws Step 60 - Insert Humidifier PCB Screws

![Insert Humidifier PCB Screws](asm_stp060_humidifier_pcb_screws.JPG)

@pre Required parts:
* __M3 x 8mm Imbus Head Screw__ - 2pcs
* __M3 x 0.5mm Plastic Spacer__ - 8pcs

1. Insert the two screws from the top.
2. Insert 4 - 4 plastic spacer to the screw from the bottom.

@subsection step_61_fix_humidifier_pcb Step 61 - Fix Humidifier PCB

![Fix Humidifier PCB](asm_stp061_fix_humidifier_pcb.JPG)

@pre Required parts:
* __M3 Regular Nut__ - 2pcs

\emoji :orange_circle: Tighten the screws.

\emoji :purple_circle: Connect the humidifier disc cable to the PCB.

@subsection step_62_humidifier_test Step 62 - Humidifier Test

1. You have to make shore that the humidifier does not leak.

![Fill The Tank](asm_stp062_humidifier_test.JPG)

Fill the tank ( marked purple ) with a bit of water. Do not overfill it! It usually
takes a few minutes to soak the cotton swab, please wait at least 5 minutes. If the
cotton swab soaks all the water pleas add a bit again.

If you connect the USB port of the humidifier PCB to a phone charger you should see
some fog \emoji :ghost:

\htmlonly

<iframe
    width="640"
    height="480"
    src="asm_stp062_humidifier_test_video.mp4"
    frameborder="0"
    allow="autoplay; encrypted-media"
    allowfullscreen
>
</iframe>

\endhtmlonly

2. Leave some water in the tank and put some dry paper towels between the tank and the table.
Let it on the table for a day at least. If it does not leak after a day it probably good.

@subsection step_63_insert_led_strip Step 63 - Insert LED Strip

![Insert LED Strip](asm_stp063_insert_led_strip.JPG)

@pre Required parts:
* __LED Strip__ @ref led_strip_cable "Cable Assembly" - 1pcs

1. Insert the LED strip into the slots on the LED holder. It does not require any glue!
2. Feed through the cable on the hole at the corner.

@subsection step_64_skull_inserts Step 64 - Skull Inserts

![Skull Inserts](asm_stp064_skull_inserts.JPG)

@pre Required parts:
* __skull_1pcs.stl__ - 1pcs
* __M3 inserts__ - 2pcs

Press the two inserts to the plastic with a soldering iron. I used  the with 200°C
and it worked perfectly.

@note Let it cool for 2-3 minutes.

@subsection step_65_fix_skull Step 65 - Fix Skull

![Fix Skull](asm_stp065_fix_skull.JPG)

@pre Required parts:
* __M3 x 10mm D-Head Screw__ - 2pcs

Tighten the two screws to fix the skull to the top.

![Top Part Finished](asm_stp065_result.JPG)

It should look like this.

@subsection step_66_insert_the_led_ring Step 66 - Insert LED Disc

![Insert LED Disc](asm_stp066_insert_the_led_ring.JPG)

@pre Required parts:
* __LED Disc__ @ref led_disc_cable "Cable Assembly" - 1pcs

Insert the LED disc to the slot.

@subsection step_67_connect_top_cables Step 67 - Connect Top Cables

![Connect Top Cables](asm_stp067_connect_top_cables.JPG)

Connect the top section's cables to the Techno Viking PCB.

\emoji :orange_circle: LED disc

\emoji :purple_circle: Humidifier

\emoji :large_blue_circle: LED strip

@subsection step_68_insert_led_holder Step 68 - Insert LED Holder

![Insert LED Holder](asm_stp068_insert_led_holder.JPG)

Insert the LED holder to the base.

@note Check the orientation.

@subsection step_69_insert_top Step 69 - Insert Top

![Insert Top](asm_stp069_insert_top.JPG)

@pre Required parts:
* __M3 x 20mm Flat Head Screw__ - 4pcs

1. Insert the top part.
2. Tighten the 4 screws on the sides( 2 on the back 1 - 1 on the front sides ).

@subsection step_70_fix_top Step 70 - Fix Top

![Fix Top](asm_stp070_lock_top.JPG)

@pre Required parts:
* __M3 x 20mm Flat Head Screw__ - 4pcs

![](finish_logo.png)
