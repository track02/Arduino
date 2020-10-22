/*Use a potentiometer to adjust the rotation of a servo motor
 * Potentiometers divide voltage  - turning the potentiometer 
 * changes the ratio of the voltage between the middle pin and power
 * this can be read as analogue input
 */


//Pull in servo library
#include <Servo.h>

//Create servo object
Servo myServo; 

int const potPin = A0;
int potVal;
int angle;

void setup() {

  //Servo is attached to pin no. 9
  myServo.attach(9);

  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);


  Serial.print("potVal: ");
  Serial.print(potVal);

  //Map scales the input (0 - 1023) to the output (0 - 179)
  //Analogue in can read between 0 - 1023, a servo can only rotate 0-179 degrees
  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print(", angle: ");
  Serial.println(angle);

  //Write angle to servo for rotation
  myServo.write(angle);

  //Sleep
  delay(15);
}
