
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

//Calibration
void setup() {


  //Start - Display LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //Set max and min range using current light levels
  while (millis() < 5000) {
    sensorValue = analogRead(A0);

    if(sensorValue > sensorHigh)
      sensorHigh = sensorValue;

    if(sensorValue < sensorLow)
      sensorLow = sensorValue;
          
  }

  digitalWrite(ledPin, LOW);
 

}

void loop() {

  sensorValue = analogRead(A0);

   //Scale current sensor reading using
   //min/max possible input values and min/max output values
   /*
    * Scale N which is between X/Y to A between B and C
    */
  int pitch = 
      map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  tone(8, pitch, 20);

  delay(10);

  

}
