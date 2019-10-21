int switchstate = 0;

void setup() {

  //Specify inputs/outputs on each pin
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {

  //Read input from pin 2
  switchstate = digitalRead(2);

  //Digitalwrite sends a voltage over specified pin
  //LOW = 0v
  //HIGH = 5v

  if(switchstate == LOW){

    //Turn on LED at pin 3 
    digitalWrite(3, HIGH);

    //Turn off LEDs at pins 4/5
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
  }
  else{

    //Turn off LEDs 3/4
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

    //Turn on LED 5
    digitalWrite(5, HIGH);

    //Sleep 1/4s
    delay(250);

    //Turn on LED 4 / Turn off LED 5 [Flashing]
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    //Sleep 1/4s
    delay(250);
  }
 }
