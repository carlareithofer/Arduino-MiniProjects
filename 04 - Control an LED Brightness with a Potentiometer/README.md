# 04 - Control an LED Brightness with a Potentiometer

In this project, I used a potentiometer to control the brightness of an LED. By turning the potentiometer, the LED brightness can be adjusted from minimum to maximum.

This project introduces analog input and PWM (Pulse Width Modulation) to control the LED's brightness.

The potentiometer value is read with `analogRead()`, which returns a number between 0 and 1023. Since `analogWrite()` only accepts values between 0 and 255, the reading is divided by 4 before being used to set the LED brightness.

**Requirements:**

<img width="490" height="210" alt="image" src="https://github.com/user-attachments/assets/a005e329-da5e-4331-8d59-c2ca967b381f" />
<br>
<img width="465" height="320" alt="436FEC2B-01C2-444D-A6B8-D6644F89B3A6" src="https://github.com/user-attachments/assets/a593371b-5f43-4e55-9f94-f92a1a9c2a03" />

**Simulated circuit in Tinkercad:**

<img width="511" height="321" alt="image" src="https://github.com/user-attachments/assets/e711b2b2-854c-49ea-b020-d2cb553ad256" />

**Assembled circuit:**

<img width="330" alt="image" src="https://github.com/user-attachments/assets/f9de6dbe-2a14-4e4b-b7dd-0c818273248f" />
<img width="330" alt="image" src="https://github.com/user-attachments/assets/fa0f9fe2-e4c7-415f-90ce-9633310a95e5" />
<img width="330" alt="image" src="https://github.com/user-attachments/assets/8edae096-bbf3-4204-bb54-342dea869ddb" />

That’s it! I hope you found this project interesting, and thank you for following along! :)
