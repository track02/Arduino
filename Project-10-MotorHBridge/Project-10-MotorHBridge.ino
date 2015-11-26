//Control pins for H-bridge to reverse motor polarity (reverse spin)
const int controlPin1 = 2;
const int controlPin2 = 3;

//Motor enabled - output to H-bridge
const int enablePin = 9;

//Pin for direction swap
const int directionSwitchPin = 4;

//Pin for motor on/off
const int onOffSwitchStatePin = 5;

//Potentiometer pin for motor speed
const int potPin = A0; 

//States
int onOffSwitchState = 0;
int previousOnOffState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

//Flags
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {

  //Setup input/output pins
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStatePin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {

  //Read input from on/off button
  onOffSwitchState =
         digitalRead(onOffSwitchStatePin);


  delay(1);

  //Read direction from left/right button
  directionSwitchState = digitalRead(directionSwitchPin);

  //Read in voltage difference from potentiometer and set as speed
  motorSpeed = analogRead(potPin)/4;

  //If difference between On/Off and input is read
  if(onOffSwitchState != previousOnOffState)
    if(onOffSwitchState == HIGH)
      motorEnabled = !motorEnabled; //Toggle motorEnable

  //If difference between left/right states and input is read
  if(directionSwitchState != previousDirectionSwitchState)
    if(directionSwitchState == HIGH)
      motorDirection = !motorDirection; //Toggle motorDirection

  //If Left - set control pins H/L
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  //Otherwise Right - inverse control pins L/H
  else{
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }


  //If the motor is enabled then pass motor speed
  if(motorEnabled == 1)
    analogWrite(enablePin, motorSpeed);
  //Otherwise disable the motor
  else
    analogWrite(enablePin, 0);


  previousDirectionSwitchState = directionSwitchState;
  previousOnOffState = onOffSwitchState;
           
}
