This is a library for MAX3421E-based / Atmega328 Freeduino USB Host Board -> http://shop.moderndevice.com/products/freeduino-usb-host-board


To use these files, copy the folder FreeduinoLibraryFiles into the main arduino libraries folder.

Then open the arduino IDE and open the FreeduinoHostBoardDemo1 program.  To be sure that the library files are found, you can do

Sketch/Add library

and go get the FreeduinoLibraryFiles that you created in the main arduino libraries folder.  This will include files you do not need, so just look at the include files in the original sketch and erase any extra include files that came from adding the library.  In particular, you do not want ch9.h, as that has errors under Arduino 1.0

You can now modify the sketch and save under your own sketch name.

Note that the Freeduino board compiles as an Uno.

There are some simplifed examples that you can use to build more complex code, specifically, FreeduinoSimple.

Note, that if you use the serial monitor to watch messages, it has to be opened before you plug in the tablet.  When you open the serial monitor it resets the arduino and, if the tablet is already attached to the arduino, it gets confused by the reset.


