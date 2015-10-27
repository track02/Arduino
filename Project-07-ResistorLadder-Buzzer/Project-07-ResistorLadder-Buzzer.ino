int notes[] = {262,294,330,349}; //Create an array and populate w/ values



void setup() {
  Serial.begin(9600);

}

void loop() {
  
  //Read in returned voltage from switch press  
  int keyVal = analogRead(A0);
  
  //Output over serial
  Serial.println(keyVal);

  //Depending on voltage - play a different tone - will need to configure condition values due to resistor error %
  if(keyVal == 1023){
    tone(8, notes[0]);
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
  else{
    noTone(8);
  }



}
