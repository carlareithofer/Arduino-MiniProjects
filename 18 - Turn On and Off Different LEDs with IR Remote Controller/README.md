# 18 - Turn ON and OFF Different LEDs with IR Remote Controller

An Arduino LED control system that uses an infrared receiver and a remote control to switch three LEDs on and off independently. Each LED is assigned two remote control buttons: one to turn it on and another to turn it off.

**Required library:** IRremote (version 3.0 or newer), installed from the Arduino IDE Library Manager.

**How to use it:**
- Point the remote at the IR receiver and press the buttons from the table above.
- The command codes depend on the remote control. If your remote doesn't work, open the Serial Monitor at **115200** baud, press each button, and replace the codes in the `#define` lines with the ones displayed.
  
**Requirements:**

<img width="465" alt="image" src="https://github.com/user-attachments/assets/993feea5-500c-4a50-9742-f58a1d17d7f6" />
<br>
<img width="465" height="320" alt="image" src="https://github.com/user-attachments/assets/0657aacb-f797-4963-ad3a-0f3c80b95b88" />

**Simulated circuit in Tinkercad:**

<img width="465" height="321" alt="image" src="https://github.com/user-attachments/assets/439d1866-7f30-4653-928f-8b7f99032d30" />

**Assembled circuit:**

<img width="370" alt="image" src="https://github.com/user-attachments/assets/155eee31-38f3-418c-85bd-2825247b0b46" />

That’s it! I hope you found this project interesting, and thank you for following along! :)
