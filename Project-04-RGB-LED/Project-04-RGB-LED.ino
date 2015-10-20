
//Const I/O Pins
const int greenLed = 9;
const int blueLed = 10;
const int redLed = 11;

const int redSensor = A0;
const int greenSensor = A1;
const int blueSensor = A2;

//Vars for RGB outputs / inputs
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup(){

  //Open serial port - 9600 baud
  Serial.begin(9600);

  //Setup outputs
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);

}


void loop(){

  //Read in sensor values
  redSensorValue = analogRead(redSensor);
  greenSensorValue = analogRead(greenSensor);
  blueSensorValue = analogRead(blueSensor);

  //Print readings
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("Raw Sensor Values \t Blue: ");
  Serial.print(blueSensorValue);  
  Serial.print("Raw Sensor Values \t Green: ");
  Serial.print(greenSensorValue);

  //Set RGB output values
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;


  //Print outputs
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);

  /*Set brightness using PWM  
   * Pulse Width Modulation
   * Rapidly swap between HIGH / LOW output
   * % of time in HIGH -> Duty Cycle
   * 
   * Sensor reads between 0-1023, OUTPUT takes value of 0-255
   * Convert by dividing by 4
   * 
   * Set output using analogWrite()
   * 
   * E.g. Value of 127 -> 50% Duty Cycle (On 50% of the time)
   */

  analogWrite(redLed, redValue);
  analogWrite(greenLed, greenValue);
  analogWrite(blueLed, blueValue);

  delay(250);

  
}

