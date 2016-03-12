void setupLcd() {
	lcd.begin(16, 2); //  <<----- My LCD was 16x2

	  // Switch on the backlight
	lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
	lcd.setBacklight(HIGH);
	lcd.home(); // go home
}

void  setTime() {
	switch (editMode) {
	case Hours:
		blinkHours();
		printMinutes();
		if (modeButtonPressed()) {
			editMode = Minutes;
		}
		break;
	case Minutes:
		printHours();
		blinkMinutes();
		if (modeButtonPressed()) {
			toggleMode();
			editMode = Hours;
		}
		break;
	}
}

void printHours() {
	lcd.setCursor(0, 0);
	lcd.print(getHours());
}

void blinkHours() {
	lcd.setCursor(0, 0);
	blinkText(0, 0, getHours(), "  ");
}

void printMinutes() {
	lcd.setCursor(3, 0);
	lcd.print(getMinutes());
}

void blinkMinutes() {
	lcd.setCursor(3, 0);
	blinkText(3, 0, getMinutes(), "  ");
}

String getHours() {
	return Format(hours);
}

String getMinutes() {
	return Format(minutes);
}

String Format(int number) {
	if (number < 10)
		return "0" + String(number);
	else {
		return String(number);
	}
}


short previousMinutes;
void  showTime() {

	Time time = rtc.getTime();

	if (time.min != previousMinutes) {
		previousMinutes = time.min;

		lcd.setCursor(0, 0);
		if (time.hour < 10)
			lcd.print("0" + String(time.hour));
		else
			lcd.print(time.hour);

		lcd.setCursor(3, 0);
		if (time.min < 10)
			lcd.print("0" + String(time.min));
		else
			lcd.print(time.min);
	}
	blinkText(2, 0, ":", " ");
}

unsigned long previousMillis;
unsigned long interval = 1000;

void blinkText(int column, int row, String text, char  alternateText[]) {
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval) {
		// save the last time you blinked the LED
		previousMillis = currentMillis;

		aantalSeconden++;
		lcd.setCursor(column, row);
		if (tonen) {
			lcd.write(text.c_str());
			tonen = false;
		}
		else {
			lcd.write(alternateText);
			tonen = true;
		}
	}
}

void blinkColon() {
	unsigned long currentMillis = millis();
	if (currentMillis - previousMillis >= interval) {
		// save the last time you blinked the LED
		aantalSeconden++;

		previousMillis = currentMillis;
		lcd.setCursor(2, 0);
		if (tonen) {
			lcd.write(":");
			tonen = false;
		}
		else {
			lcd.write(" ");
			tonen = true;
		}
	}
}








