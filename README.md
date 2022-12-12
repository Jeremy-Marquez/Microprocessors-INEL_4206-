# Microprocessors INEL 4206 - Temperature Sensor Project

Project Description: 
The goal for this project is demonstrating IoT knowledge by realising HTTP requests from a microprocesor (esp32) to an instance in which node-red is running. The flow of node-red would be primarily based on two HTTP requests. One for updating the measurements from the sensor (POST) and the other for obtaining the results in a way that a virtual assistant like Siri can translate the output from text to speech.

The dashboard of Node-Red is the following:
![image](https://user-images.githubusercontent.com/70215217/207150785-0f14ebe0-07dd-4364-903a-ec966d68b22c.png)

To build the project:
1. Clone the repository in your machine

2. Do the installations for PlatformIO extensions on VS code

3. Modify ssid and password values in the code you just cloned to the ones of your wifi network

4. Make sure the Vout of the LTM84 is connected to the pin 35 of the esp32

5. Upload the code to the esp32 and make sure it is connected in a proper way to an LTM84 temperature sensor. The datasheet is the following: https://www.ti.com/lit/ds/symlink/lmt84.pdf?ts=1670804378375&ref_url=https%253A%252F%252Fwww.google.com%252F

6. Finally: Access the following URL to see the results posted in Node-Red UI: http://34.198.194.143:1880/ui | Access the following URL through Siri to listen to the last read of the sensor (temperature): http://34.198.194.143:1880/GetTemperature


