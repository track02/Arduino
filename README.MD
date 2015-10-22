Small Arduino Projects 


1) Basic Circuit 

	LED + Switch
	Series / Parallel
	No Code

2) Flashing LEDs when button is pressed

	Simple code to toggle HIGH / LOW outputs when button is detected


3) Temperature Sensor + LEDs

	LEDs light up as temperature increases above baseline
	Convert sensor value into a voltage and the voltage into a temperature
	Compare temperature reading to pre-set baseline and toggle LEDs accordingly


4) x3 Photoresistors + RGB LED

	Adjust RGB levels in LED based on photoresistor readings
	Have one photoresistor for each colour, filter light w/ plastic filter
	
	Use the map function to scale the analogue input (0-1023) to an output value 	     (0 - 255) 

	RGB LED uses PWM to rapidly switch RGB elements on and off
	Different timings create various colours and can be used to mix/fade
	E.g (0,0,255) RG would be off and B would be on 100% of the time	


5) Servo + Potentiometer

	Use a potentiometer to adjust voltage ratio  and rotate servo accordingly

	Analogue input must be converted from 0 - 1023 to 0-179 (rotation angles)


6)Photoresistor + Buzzer/Piezo

	Adjust buzzer output using voltage change caused by light levels detected by photoresistor.

	Use the tone function to allow varying frequencies

	Calibrate the system by determining min/max light levels
	move hand over photoresistor to create light-range

	Convert this analogue input to a frequency and pass to speaker
