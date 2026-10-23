# 17 - Distance to the Obstacle on LCD Screen

An Arduino-based distance measurement system that uses an ultrasonic sensor to measure the distance to nearby objects and display it on a 16×2 LCD. The screen also shows the sensor's trigger interval, while the code retains the last valid distance reading when a measurement exceeds the sensor's 400 cm range.

The sensor is triggered every 60 ms, which is the minimum interval recommended for the HC-SR04, so that the echo of one measurement does not interfere with the next one.

**How to use it:**
- Place an object in front of the sensor. The distance in centimeters is shown on the second row of the LCD.
  
**Requirements:**

<img width="465" alt="image" src="https://github.com/user-attachments/assets/452725a5-0621-4711-bf71-8b2dcdbfbbf2" />
<br>
<img width="465" alt="image" src="https://github.com/user-attachments/assets/12eed25d-1782-4e8e-9fc4-9986006770ae" />


**Simulated circuit in Tinkercad:**

<img width="511" height="321" alt="image" src="https://github.com/user-attachments/assets/2ceee282-bce6-4d53-a906-f1808fb23386" />

That’s it! I hope you found this project interesting, and thank you for following along! :)
