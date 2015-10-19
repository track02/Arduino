const int sensorPin = A0;
const float baselineTemp = 22.0;



void setup() {
  Serial.begin(9600); //Open up serial connection
                      //9600 baud - 9600 bits per second

  //Loop pins and set outputs and turn off LEDs
  for(int i = 2; i < 5; i++){
    pinMode(i, OUTPUT); 
    digitalWrite(i, LOW);
    
  }
}

void loop() {

  int sensorVal = analogRead(sensorPin); //Pull from ANIN
  float voltage = (sensorVal/1024.0) * 5.0; //ANIN Reads 5v in range 0 - 1024 - Convert back
  float temperature = (voltage - 0.5) * 100; //Convert voltage to temperature

  //Print outs
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print("\n\n");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print("\n\n");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("\n\n");

  //Turn off all LEDs if below baseline
  if(temperature < baselineTemp)
    for(int i = 2; i < 5; i ++)
      digitalWrite(i, LOW);

  //Turn on all LEDs if baseline +3
  if(temperature >= baselineTemp + 3){
    for(int i = 2; i < 5; i++)
      digitalWrite(i, HIGH);
  }
  //Turn on 2 LEDs if baseline +2
  else if(temperature >= baselineTemp + 2){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
  }
  //Turn on 1 LED if baseline +1
  else if(temperature >= baselineTemp + 1){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
  }
  
  //Sleep to reduce polling on input  
  delay(500);

  

}
