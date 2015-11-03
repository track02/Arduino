//Tilt switch input
const int switchpin = 8;

//Time since last LED change
unsigned long previousTime = 0;

//Tilt switch states
int switchState = 0;
int prevSwitchState = 0;

//Which LED to turn on - starting at pin 2
int led = 2;

//Interval between LED turn on - 1 min
long interval = 600;

//Flag for toggling odd/even LEDs
bool toggle = true;


void setup(){

  //Set LED output pins - 2 to 8
  for(int x = 2; x<8; x++)
    pinMode(x, OUTPUT);

  //Set input pin for tilt switch
  pinMode(switchpin, INPUT);
  
  
}


void loop(){
  
  //Read current time
  unsigned long currentTime = millis();


  //Calc time diff
  if(currentTime - previousTime > interval){
    previousTime = currentTime;

    if(led <= 7)
      digitalWrite(led++, HIGH); //Turn LED on and increment
    else{

      for(int x = 2; x < 8; x++){

        //If it's an even LED - turn off
        if(x%2 == 0 && toggle)
          digitalWrite(x, LOW);
        else if(x%2 == 0 && !toggle)
          digitalWrite(x, HIGH);

        //If it's an odd LED - turn on
        if(x%2 != 0 && toggle)
          digitalWrite(x, HIGH);
        else if(x%2 != 0 && !toggle)
          digitalWrite(x, LOW);

                       
      } 

      toggle = !toggle;
    }

    


  }
  

  //Get tilt switch state
  switchState = digitalRead(switchpin);

  //Change in direction - reset
  if(switchState != prevSwitchState){
    
    for(int x = 2; x < 8; x++)
      digitalWrite(x,LOW);

    led = 2;
    previousTime = currentTime;
  
  }

    prevSwitchState = switchState;
    
} 

