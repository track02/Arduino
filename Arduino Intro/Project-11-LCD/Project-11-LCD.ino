#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Set LCD pins


const int switchPin = 6; //Tilt sensor pin
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup(){
  
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the"); //Print line
  lcd.setCursor(0,1); //Move cursor to first column (0) on second line (1)
  lcd.print("Crystal Ball!"); //Print line
    
}

void loop(){

  
  switchState = digitalRead(switchPin);

  //Check tilt sensor state 
  if(switchState != prevSwitchState){
      
    if(switchState == LOW){

      //Generate random int 0-8
      reply = random(8);

      //Clear down LCD and print inital line
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);

      //Print reply using random number
      switch(reply){
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("No");
          break;
        case 2:
          lcd.print("Maybe");
          break;
        case 3:
          lcd.print("I don't know");
          break;
        case 4:
          lcd.print("Doubtful");
          break;
        case 5:
          lcd.print("Outlook Good");
          break;
        case 6:
          lcd.print("Doubtful");
          break;
        case 7:
          lcd.print("Unsure");
          break;
      }
    }
  }
    
  //Update prev state
  prevSwitchState = switchState;
    
}
  




