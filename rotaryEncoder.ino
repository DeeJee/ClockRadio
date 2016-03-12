void setupRotaryEncoder() {
	pinMode(ROTARYPA, INPUT);
	pinMode(ROTARYPB, INPUT);

	digitalWrite(ROTARYPA, HIGH);   // enable pull-up
	digitalWrite(ROTARYPB, HIGH);   // enable pull-up

	attachInterrupt(0, rotaryTurn, RISING);    // interrupt 0 is pin 2, For rotary encoder

	pinMode(BUTTON, INPUT);
	digitalWrite(BUTTON, HIGH); // connect internal pull-up
}

void rotaryTurn()
{
	// Interrupt Service Routine for a change to Rotary Encoder pin A
	if (editMode == Hours) {
		if (digitalRead(ROTARYPB)) {
			if (hours > 0) {
				hours--;   // Turn it Down!       
			}
			else {
				hours = 23;
			}
		}
		else {
			if (hours < 23) {
				hours++;   // Turn it Up!      
			}
			else {
				hours = 0;
			}
		}
	}
	if (editMode == Minutes) {
		if (digitalRead(ROTARYPB)) {
			if (minutes > 0) {
				minutes--;   // Turn it Down!       
			}
			else {
				minutes = 59;
			}
		}
		else {
			if (minutes < 59) {
				minutes++;   // Turn it Up!      
			}
			else {
				minutes = 0;
			}
		}
	}
}




