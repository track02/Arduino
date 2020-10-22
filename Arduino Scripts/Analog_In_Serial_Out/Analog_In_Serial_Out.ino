/*
  Repeatedly listens for analog in values from designated pins
  Every X seconds, packages latest reading set and transmits over serial
*/

//Sensor Pins
int firstSensor = 0;    // first analog sensor
int secondSensor = 1;   // second analog sensor
int thirdSensor = 2;    // third analog sensor

//Sensor Readings
float firstReading = 0.0;
float secondReading = 0.0;
float thirdReading = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  firstReading = analogRead(firstSensor);
  secondReading = analogRead(secondSensor);
  thirdReading = analogRead(thirdSensor);
  
  Serial.print(firstReading);
  Serial.print(",");
  Serial.print(secondReading);
  Serial.print(",");
  Serial.println(thirdReading);
  delay(5000);
  

}
