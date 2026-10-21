# 14 - Ultrasonic Distance Sensor

An Arduino ultrasonic distance measurement project using an ultrasonic sensor to measure the distance to nearby objects. The sensor periodically sends a pulse, measures the returning echo, and calculates the distance based on the measured time.

The distance is calculated from the time it takes the ultrasonic pulse to travel to the object and back. Sound travels at about 343 m/s, or 0.0343 cm/µs. Since the pulse travels the distance twice, distance = duration × 0.0343 / 2, which is approximately duration / 58.

**How to use it:**
- Open the Serial Monitor and set the baud rate to **115200**.
- Place an object in front of the sensor. The distance in centimeters is displayed every 100 ms.
  
**Requirements:**


<img width="465" alt="image" src="https://github.com/user-attachments/assets/3f8d8cb5-1805-4bbf-93eb-6eae8269ff0c" />

**Simulated circuit in Tinkercad:**

<img width="465" height="350" alt="image" src="https://github.com/user-attachments/assets/ac2daf89-772d-48bb-8775-1385157ae928" />

**Assembled circuit:**

<img width="370" alt="image" src="https://github.com/user-attachments/assets/155eee31-38f3-418c-85bd-2825247b0b46" />

That’s it! I hope you found this project interesting, and thank you for following along! :)
