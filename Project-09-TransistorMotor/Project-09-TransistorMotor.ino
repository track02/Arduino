//Set pins
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop(){

  //Read switch state and toggle motor
  switchState = digitalRead(switchPin);

  if(switchState == HIGH)
    digitalWrite(motorPin, HIGH);
  else
    digitalWrite(motorPin, LOW);
}

