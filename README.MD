Small Arduino Projects 


1) Basic Circuit 

	LED + Switch
	Series / Parallel
	No Code

2) Flashing LEDs when button is pressed

	Simple code to toggle HIGH / LOW outputs when button is detected


3) Temperature Sensor & LEDs

	LEDs light up as temperature increases above baseline
	Convert sensor value into a voltage and the voltage into a temperature
	Compare temperature reading to pre-set baseline and toggle LEDs accordingly


4) x3 Photoresistors & RGB LED

	Adjust RGB levels in LED based on photoresistor readings
	Have one photoresistor for each colour, filter light w/ plastic filter
	
	Use the map function to scale the analogue input (0-1023) to an output value 	     (0 - 255) 

	RGB LED uses PWM to rapidly switch RGB elements on and off
	Different timings create various colours and can be used to mix/fade
	E.g (0,0,255) RG would be off and B would be on 100% of the time	


5) Servo & Potentiometer

	Use a potentiometer to adjust voltage ratio  and rotate servo accordingly

	Analogue input must be converted from 0 - 1023 to 0-179 (rotation angles)


6) Photoresistor & Buzzer/Piezo

	Adjust buzzer output using voltage change caused by light levels detected by photoresistor.

	Use the tone function to allow varying frequencies

	Calibrate the system by determining min/max light levels
	move hand over photoresistor to create light-range

	Convert this analogue input to a frequency and pass to speaker

7) Resistor Ladder & Buzzer/Piezo

	Created a resistor ladder which results in differing voltages
	returned when a switch is pressed and the circuit completes

	Look for different voltages returned analogue in
	Play a different tone for each voltage

8) LED's & Tilt Switch

	Created a Digital Hour glass
	Using a set interval / timer toggle on LED's as time passes
	Once all LED's are lit flash odd/even 
	If tilt switch output differs from previous reset LED's + timer

9) Transistor & Motor

	A motor requires more current than can be provided by digital out pins.
	Back-voltage generated from a motor can also be harmful to circuit.
	Use a 9V battery for powering the motor, a transistor is used
	to interface the motor to the microcontroller.
	A diode is also used to prevent damage being caused by back-voltage.

	A switch is used to toggle the transistor gate and connect the motor.

10) H-Bridge & Motor

	Use a H-Bridge to reverse the polarity of the motor
	Allows motor to change direction
	
	By swapping voltages on H-Bridge control pins the polarity of
	the connected circuit can be reversed, adjusting motor direction

	Motor state is controlled using an On/Off button and a Left/Right button	

11) LCD & Tilt Switch

	Wired up an LCD to display different messages
	Each time a change is detected from the tilt switch a new message is displayed
