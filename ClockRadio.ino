#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
/////einde klok




//// Generally, you should use "unsigned long" for variables that hold time
//// The value will quickly become too large for an int to store
//unsigned long previousMillis = 0;        // will store last time LED was updated
//
//// constants won't change :
//const long interval = 1000;           // interval at which to blink (milliseconds)

//knipperen
//////////////////////////////////////


/*
** Example Arduino sketch for SainSmart I2C LCD Screen 16x2
 ** based on https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino
 ** by
 ** Edward Comer
 ** LICENSE: GNU General Public License, version 3 (GPL-3.0)

 ** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
 ** https://bitbucket.org/fmalpartida/new-liquidcrystal

 ** Modified - Ian Brennan ianbren at hotmail.com 23-10-2012 to support Tutorial posted to Arduino.cc

 ** Written for and tested with Arduino 1.0
 **
 ** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL

 */
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

//--------------------------------------------
// Example for a rotary encoder
// Bart Venneker 2015
//--------------------------------------------
// This example uses a rotary encoder to set the 
// value of a variable (rotaryCount)
//
// See http://youtu.be/KzT3aUE1-0Q for more info (in DUTCH!!)

#define ROTARYPA 2
#define ROTARYPB 4

#define DISPLAYMODE 0
#define EDITMODE 1


//Knop
int BUTTON = 8;


long rotaryCount = 0;
long lastRotaryCount = 0;
long aantalSeconden = 0;
enum EditMode {
	Hours,
	Minutes
};
EditMode editMode;

void setup() {
	// Setup Serial connection
	Serial.begin(9600);

	// Initialize the rtc object
	rtc.begin();
	setupLcd();
	setupRotaryEncoder();
	// The following lines can be uncommented to set the date and time
	//rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
	//rtc.setTime(21, 32, 0);     // Set the time to 12:00:00 (24hr format)
	//rtc.setDate(25, 2, 2016);   // Set the date to January 1st, 2014
}

int mode = DISPLAYMODE;
boolean tonen;
int hours, minutes;

boolean pushButtonPreviousState = true;
void loop() {
	switch (mode) {
	case DISPLAYMODE:
		if (modeButtonPressed()                                                                                                                                                                                                                                                                                                                                                                                                                                               ) {
			toggleMode();
		}

		showTime();
		break;
	case EDITMODE:
		setTime();
		break;
	}
}


boolean modeButtonPressed() {
	boolean buttonState = digitalRead(BUTTON);
	if (buttonState == LOW) {
		if (pushButtonPreviousState == false) {
			pushButtonPreviousState = true;
			return true;
		}
	}
	else {
		//resetten
		pushButtonPreviousState = false;
	}

	return false;
}

void toggleMode() {
	if (mode == DISPLAYMODE) {
		Serial.println("Switching to editmode");
		Serial.println("Editing hours");
		mode = EDITMODE;
		Time time = rtc.getTime();
		hours = time.hour;
		minutes = time.min;
	}
	else {
		Serial.println("Switching to display mode");
		mode = DISPLAYMODE;
	}
}













