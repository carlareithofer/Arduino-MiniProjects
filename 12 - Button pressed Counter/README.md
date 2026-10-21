# 12 - Button pressed Counter

An Arduino button counter that uses a hardware interrupt to detect button presses. Each detected press increments a counter, with the current count displayed in the Serial Monitor.

The button is connected to pin 2 because on the Arduino Uno only pins 2 and 3 can be used for external interrupts. The interrupt is triggered on the RISING edge, which is the moment the button is pressed. A 50 ms software debounce prevents a single press from being counted multiple times.

**How to use it:**
- Open the Serial Monitor and set the baud rate to **115200**.
- Press the button. The current count is displayed after each press.

**Requirements:**

<img width="465" height="200" alt="image" src="https://github.com/user-attachments/assets/a36edf4d-4a87-4b63-8dca-bc097cccd72e" />

**Simulated circuit in Tinkercad:**

<img width="465" height="320" alt="image" src="https://github.com/user-attachments/assets/fa13e79a-30fe-4a47-938b-5e47bb2f6b29" />

That’s it! I hope you found this project interesting, and thank you for following along! :)
