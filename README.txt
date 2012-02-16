This is a library for MAX3421E-based / Atmega328 Freeduino USB Host Board -> http://shop.moderndevice.com/products/freeduino-usb-host-board


To use these files, copy the folder FreeduinoLibraryFiles into the main arduino libraries folder.

Then open the arduino IDE and open the FreeduinoHostBoardDemo1 program.  To be sure that the library files are found, you can do

Sketch/Add library

and go get the FreeduinoLibraryFiles that you created in the main arduino libraries folder.  This will include files you do not need, so just look at the include files in the original sketch and erase any extra include files that came from adding the library.  In particular, you do not want ch9.h, as that has errors under Arduino 1.0

You can now modify the sketch and save under your own sketch name.

Note that the Freeduino board compiles as an Uno.


