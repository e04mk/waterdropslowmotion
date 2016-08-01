const int pumpPin = 11;
const int strobPin = 10;
const int pot1Pin = A0;
const int pot2Pin = A1;
int pot1Value = 0;
int pot2Value = 0;

// Turn the strobe on or off when outside these limits
const int strobehighlimit = 110;
const int strobelowlimit = 2;

// Serial communication slows down loop, use when debugging
const bool serialmon = false;

// The setup routine runs once when you press reset
void setup() {                
  // Initialize the strobe pin as a digital output.
  pinMode(strobPin, OUTPUT);
  // Initialize serial communication
  if (serialmon == true)
    Serial.begin(9600);
}

// The loop routine runs over and over again forever
void loop() {
  pot1Value = analogRead(pot1Pin);
  pot1Value = map(pot1Value, 0, 1023, 255, 50); // Map into 8-bit region of analogWrite
  if(pot1Value < 80){ // Fully stop pump when close to stopped
    pot1Value = 0;
  }
  analogWrite(pumpPin, pot1Value);
  
  pot2Value = analogRead(pot2Pin);
  pot2Value = map(pot2Value, 0, 1023, 0, 127);
  if (pot2Value > strobelowlimit && pot2Value < strobehighlimit){
    // Strobe if the pot is not maxed out
    digitalWrite(strobPin, HIGH); // turn the Strobe on
    delayMicroseconds(700);      // 0.8ms LED on
    digitalWrite(strobPin, LOW); // turn the Strobe off
  }
  else if (pot2Value <= strobelowlimit) {
    digitalWrite(strobPin, HIGH);
  }
  else if (pot2Value >= strobehighlimit) {
    digitalWrite(strobPin, LOW);
  }
  delay(pot2Value);		// TODO: Scale this value to flash just between the point of the drops to look stationary and when it travels forward and backward.

  // Print the results to the serial monitor: 
  if (serialmon == true) {
    Serial.print("pot1 = " );
    Serial.print(pot1Value);
    Serial.print("\t pumpValue = ");
    Serial.println(pot1Value); 
    Serial.print("pot2 = " );
    Serial.print(pot2Value);
    Serial.print("\t delay = ");
    Serial.print(pot2Value);
    Serial.println("ms");
  }
}

