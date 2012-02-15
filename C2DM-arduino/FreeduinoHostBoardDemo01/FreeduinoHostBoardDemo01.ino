/* FreeduinoHostBoardDemoV01.pde
* demo sketch for the Modern Device Freeduino USB Host Board  moderndevice.com

*  This sketch works with Google's Android ADK app
*  with code from Google & www.circuitsathome.com
*  This code is in the public domain
*
* The Freeduino Host Board should be used with the Arduino Uno board setting
* The board also requires FTDI drivers from FTDIchip.com
* You want the Virtual Com Port (VCP) drivers
* 
* This sketch currently has the current functionality with the Google ADK
* The PWM value of pins 3, 5, 6 are controlled by the color channels of LED1
* The Google buttons 1,2,3 are controlled by grounding AO, A1, A2 to activate
* LED icons in the Google Android Sketch
* Notes:
* Serial speed changed to 57500 because Arduino serial monitor locks at 115200

* Please forward improved hacks of this sketch to support@moderndevice.com
*/


#include <Wire.h> 
#include <Servo.h>

#include <Max3421e.h>
#include <Usb.h>
#include <FHB.h>

#if 0
#include   <CapSense.h>
#endif

#if 0
#define  LED3_RED       2
#define  LED3_GREEN     4
#define  LED3_BLUE      3
#endif

#define  LED2_RED       8

#if 0

#define  LED2_GREEN     7
#define  LED2_BLUE      6

#define  LED1_RED       8
#define  LED1_GREEN     10
#define  LED1_BLUE      9

#define  SERVO1         11
#define  SERVO2         12
#define  SERVO3         13

#define  TOUCH_RECV     14
#define  TOUCH_SEND     15

#define  RELAY1         A0
#define  RELAY2         A1

#define  LIGHT_SENSOR   A2
#define  TEMP_SENSOR    A3

//#define  BUTTON1        A6
//#define  BUTTON2        A7
//#define  BUTTON3        A8

#define  JOY_SWITCH     A9      // pulls line down when pressed
#define  JOY_nINT       A10     // active low interrupt input
#define  JOY_nRESET     A11     // active low reset output

#else
// Modern Device setup

#define  BUTTON1        A0
#define  BUTTON2        A1
#define  BUTTON3        A2

#define  LED1_RED       3
#define  LED1_GREEN     5
#define  LED1_BLUE      6

#endif

AndroidAccessory acc("Google, Inc.",
		     "DemoKit",
		     "DemoKit Arduino Board",
		     "1.0",
		     "http://www.android.com",
		     "0000000012345678");
Servo servos[3];

#if 0
// 10M ohm resistor on demo shield
CapSense   touch_robot = CapSense(TOUCH_SEND, TOUCH_RECV);
#endif

void setup();
void loop();

void init_buttons()
{
	pinMode(BUTTON1, INPUT);
	pinMode(BUTTON2, INPUT);
	pinMode(BUTTON3, INPUT);
	// enable the internal pullups
	digitalWrite(BUTTON1, HIGH);
	digitalWrite(BUTTON2, HIGH);
	digitalWrite(BUTTON3, HIGH);
}


void init_relays()
{
#if 0
  	pinMode(RELAY1, OUTPUT);
	pinMode(RELAY2, OUTPUT);
#endif
}


void init_leds()
{
#if 0  
	digitalWrite(LED1_RED, 1);
	digitalWrite(LED1_GREEN, 1);
	digitalWrite(LED1_BLUE, 1);

	pinMode(LED1_RED, OUTPUT);
	pinMode(LED1_GREEN, OUTPUT);
	pinMode(LED1_BLUE, OUTPUT);
#endif

#if 0
	digitalWrite(LED2_RED, 1);

	digitalWrite(LED2_GREEN, 1);
	digitalWrite(LED2_BLUE, 1);
#endif
	pinMode(LED2_RED, OUTPUT);
#if 0
	pinMode(LED2_GREEN, OUTPUT);
	pinMode(LED2_BLUE, OUTPUT);

	digitalWrite(LED3_RED, 1);
	digitalWrite(LED3_GREEN, 1);
	digitalWrite(LED3_BLUE, 1);

	pinMode(LED3_RED, OUTPUT);
	pinMode(LED3_GREEN, OUTPUT);
	pinMode(LED3_BLUE, OUTPUT);
#endif
}

void init_joystick(int threshold);

byte b1, b2, b3, b4, c;
void setup()
{
	Serial.begin(57600);
	Serial.print("\r\nStart");


	init_leds();
#if 0
	init_relays();
#endif
	init_buttons();
#if 0
	init_joystick( 5 );
#endif

#if 0
	// autocalibrate OFF
	touch_robot.set_CS_AutocaL_Millis(0xFFFFFFFF);
#endif

#if 0
	servos[0].attach(SERVO1);
	servos[0].write(90);
	servos[1].attach(SERVO2);
	servos[1].write(90);
	servos[2].attach(SERVO3);
	servos[2].write(90);
#endif

	b1 = digitalRead(BUTTON1);
	b2 = digitalRead(BUTTON2);
	b3 = digitalRead(BUTTON3);
#if 0
	b4 = digitalRead(JOY_SWITCH);
#endif
	c = 0;


Serial.println("pre-power");

	acc.powerOn();

Serial.println("post-power");

}

void loop()
{
	byte err;
	byte idle;
	static byte count = 0;
	byte msg[3];
	long touchcount;


	if (acc.isConnected()) {
//Serial.print("-");
		int len = acc.read(msg, sizeof(msg), 1);
		int i;
		byte b;
		uint16_t val;
		int x, y;
		char c0;
#if 0
 Serial.print(len, HEX);
 Serial.print(">");
 Serial.println(msg[0], HEX);
#endif
		if (len > 0) {
			// assumes only one command per packet
#if 1
if (msg[0] != 0xc1) {
 Serial.print(msg[0], HEX);
 Serial.print(",");
 Serial.print(msg[1], HEX);
 Serial.print(",");
 Serial.println(msg[2], HEX); 
}
#endif 
 
			if (msg[0] == 0x2) {
 Serial.print(msg[0], HEX);
 Serial.print(",");
 Serial.println(msg[1], HEX);
                                  //digitalWrite(LED2_RED, !digitalRead(LED2_RED));
#if 1
				if (msg[1] == 0x0)
					analogWrite(LED1_RED, msg[2]);
				else if (msg[1] == 0x1)
					analogWrite(LED1_GREEN, msg[2]);
				else if (msg[1] == 0x2)
					analogWrite(LED1_BLUE, msg[2]);
				else 
#endif

#if 1
#if 1
if (msg[1] == 0x3)
					analogWrite(LED2_RED, 255 - msg[2]);
#else
if (msg[1] == 0x3) {
					analogWrite(LED2_RED, 0);
}
#endif
#endif
#if 0
				else if (msg[1] == 0x4)
					analogWrite(LED2_GREEN, 255 - msg[2]);
				else if (msg[1] == 0x5)
					analogWrite(LED2_BLUE, 255 - msg[2]);
				else if (msg[1] == 0x6)
					analogWrite(LED3_RED, 255 - msg[2]);
				else if (msg[1] == 0x7)
					analogWrite(LED3_GREEN, 255 - msg[2]);
				else if (msg[1] == 0x8)
					analogWrite(LED3_BLUE, 255 - msg[2]);
				else if (msg[1] == 0x10)
					servos[0].write(map(msg[2], 0, 255, 0, 180));
				else if (msg[1] == 0x11)
					servos[1].write(map(msg[2], 0, 255, 0, 180));
				else if (msg[1] == 0x12)
					servos[2].write(map(msg[2], 0, 255, 0, 180));
#endif
			} else if (msg[0] == 0x3) {
#if 0
				if (msg[1] == 0x0)
					digitalWrite(RELAY1, msg[2] ? HIGH : LOW);
				else if (msg[1] == 0x1)
					digitalWrite(RELAY2, msg[2] ? HIGH : LOW);
#endif
			}
		}

		msg[0] = 0x1;

		b = digitalRead(BUTTON1);
		if (b != b1) {
			msg[1] = 0;
			msg[2] = b ? 0 : 1;
			acc.write(msg, 3);
			b1 = b;
		}

		b = digitalRead(BUTTON2);
		if (b != b2) {
			msg[1] = 1;
			msg[2] = b ? 0 : 1;
			acc.write(msg, 3);
			b2 = b;
		}

		b = digitalRead(BUTTON3);
		if (b != b3) {
			msg[1] = 2;
			msg[2] = b ? 0 : 1;
			acc.write(msg, 3);
			b3 = b;
		}

#if 0
		b = digitalRead(JOY_SWITCH);
		if (b != b4) {
			msg[1] = 4;
			msg[2] = b ? 0 : 1;
			acc.write(msg, 3);
			b4 = b;
		}
#endif
#if 0
		switch (count++ % 0x10) {
		case 0:
			val = analogRead(TEMP_SENSOR);
			msg[0] = 0x4;
			msg[1] = val >> 8;
			msg[2] = val & 0xff;
			acc.write(msg, 3);
			break;

		case 0x4:
			val = analogRead(LIGHT_SENSOR);
			msg[0] = 0x5;
			msg[1] = val >> 8;
			msg[2] = val & 0xff;
			acc.write(msg, 3);
			break;

		case 0x8:
			read_joystick(&x, &y);
			msg[0] = 0x6;
			msg[1] = constrain(x, -128, 127);
			msg[2] = constrain(y, -128, 127);
			acc.write(msg, 3);
			break;
		case 0xc:
			touchcount = touch_robot.capSense(5);

			c0 = touchcount > 750;

			if (c0 != c) {
				msg[0] = 0x1;
				msg[1] = 3;
				msg[2] = c0;
				acc.write(msg, 3);
				c = c0;
			}

			break;
		}
#endif
	} else {
//Serial.print(".");
  		// reset outputs to default values on disconnect
#if 0  
		analogWrite(LED1_RED, 255);
		analogWrite(LED1_GREEN, 255);
		analogWrite(LED1_BLUE, 255);
#endif
		analogWrite(LED2_RED, 255);
#if 0
		analogWrite(LED2_GREEN, 255);
		analogWrite(LED2_BLUE, 255);
		analogWrite(LED3_RED, 255);
		analogWrite(LED3_GREEN, 255);
		analogWrite(LED3_BLUE, 255);
		servos[0].write(90);
		servos[0].write(90);
		servos[0].write(90);
		digitalWrite(RELAY1, LOW);
		digitalWrite(RELAY2, LOW);
#endif
	}

	delay(10);
}

