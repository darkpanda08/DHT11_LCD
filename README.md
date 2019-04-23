# Display DHT11 sensor data on LCD
This Arduino code is to display the DHT11 or DHT22 data on LCD screen. It also shows alert in form of buzzer, LED and on Screen alert. This code consists of some custom characters for the LCD to look good.


## Requirements
The items required for this project are:
- Arduino Uno (You can use any other arduino board also but connection should be ade according to that board.) Here Arduino refers to Arduino Uno.
- 16x2 LCD display
- 10k Potentiometer
- DHT11 Sensor (or DHT22)
- LED
- Jumper Wires


## Connections
1. Identify the pins of your 16x2 LCD Display according to the datasheet.

2. Connect Pin1 of LCD to ground rail of breadboard.

3. Connect Pin2 of LCD to positive rail of breadboard.

4. Connect Pin3 of LCD to 10k Potentiometer middle pin. Connect other two pins of potentiometer to positive and ground rail. (For Contrast)

5. Connect Pin4 of LCD to Pin12 of Arduino.

6. Connect Pin5 of LCD to ground rail of breadboard.

7. Connect Pin6 of LCD to Pin11 of Arduino.

8. Connect Pin16 of LCD to ground rail of breadboard.

9. Connect Pin15 of LCD to 10k Potentiometer middle pin.  Connect other two pins of potentiometer to positive and ground rail. (For Backlight)

10. Connect Pin14 of LCD to Pin2 of Arduino.

11. Connect Pin13 of LCD to Pin3 of Arduino.

12. Connect Pin12 of LCD to Pin4 of Arduino.

13. Connect Pin11 of LCD to Pin5 of Arduino.

**Here the connections to Arduino is done with Digitals pins only. No Analog Pin is used.


## Installation
Make the connections as written above. Connection diagram is also available in repository.

Connect the Arduino to your PC via USB and upload the code provided in file named dht11_lcd.ino. You can make changes to the code like you can mention the location in the code.

Once the code is uploaded, vary both the potentiometer until the diplay is appropriate for you.
