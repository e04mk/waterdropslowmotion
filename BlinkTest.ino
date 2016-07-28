/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int led = 13;
const int pumpPin = 11;
const int strobPin = 10;
const int pot1Pin = A0;
const int pot2Pin = A1;
int pot1Value = 0;
int pot2Value = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(strobPin, OUTPUT);
  // initialize serial port
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
  pot1Value = analogRead(pot1Pin);
  pot2Value = analogRead(pot2Pin);
  digitalWrite(led, HIGH);   	// turn the LED on
  digitalWrite(strobPin, HIGH);
  delay(1);			// 1ms LED on
  digitalWrite(led, LOW);    	// turn the LED off
  digitalWrite(strobPin, LOW);
  pot2Value = map(pot2Value, 0, 1023, 0, 255);
  delay(pot2Value);		// TODO: Scale this value to flash just between the point of the drops to look stationary and when it travels forward and backward.
  
  // print the results to the serial monitor:
  Serial.print("pot1 = " );
  Serial.print(pot1Value);
  
  pot1Value = map(pot1Value, 0, 1023, 0, 255);
  if(pot1Value < 30){
    pot1Value = 0;
  }
  Serial.print("\t pumpValue = ");
  Serial.println(pot1Value); 
  Serial.print("pot2 = " );
  Serial.print(pot2Value);
  Serial.print("\t delay = ");
  Serial.print(pot2Value);
  Serial.println("ms");
  analogWrite(pumpPin, pot1Value);
}
