/* Freeduino Simple sketch
* Serial speed is 57500 because Arduino serial monitor locks at 115200
*/

#include <Max3421e.h>
#include <Usb.h>
#include <FHB.h>


AndroidAccessory acc("Google, Inc.",
		     "DemoKit",
		     "DemoKit Arduino Board",
		     "1.0",
		     "http://www.android.com",
		     "0000000012345678");

void setup()
{
	Serial.begin(57600);
        
        pinMode(3, OUTPUT);
	digitalWrite(3, 1);

	acc.powerOn();
}

void loop()
{
	byte msg[3];
	if (acc.isConnected()) {
	  int len = acc.read(msg, sizeof(msg), 1);
          if (len > 0) {
            Serial.println(msg[0]);
            Serial.println(msg[1]);
            Serial.println(msg[2]);
	    if (msg[0] == 0x2) {
        	if (msg[1] == 0x0) analogWrite(3, msg[2]);
                else analogWrite(3,20);
            }
          }
        }
	delay(10);
}

