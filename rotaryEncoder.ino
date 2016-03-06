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
	//  if(mode==EDITMODE){
	if (digitalRead(ROTARYPB)) {
		if (rotaryCount > 0) {
			rotaryCount--;   // Turn it Down!       
		}
	}
	else {
		rotaryCount++;   // Turn it Up!      
	}
	//  } 
}




