# Capstone Project - Smart Desk Station

For my final project, I used all the components and I combined the concepts from the 20 mini-projects into a single multi-mode system. The Smart Desk Station has three operating modes, selected with an IR remote control, and a 16×2 LCD that shows the current mode and live sensor data.

## Modes

| Remote button | Mode | What it does |
|---|---|---|
| 1 | **Parking sensor** | Measures the distance with the ultrasonic sensor. Red LED: under 30 cm, yellow LED: 30–150 cm, green LED: 150–400 cm. The distance in cm is shown on the LCD. |
| 2 | **Night light** | The yellow LED turns on when the photoresistor detects that it's dark. The light level is shown on the LCD. |
| 3 | **LED dimmer** | Each button press selects the next LED (red → yellow → green → red...). The potentiometer adjusts the brightness of the selected LED only. Each LED keeps its brightness when another LED is selected. |

When the mode changes, all LEDs are turned off, so each mode starts from a clean state.

## Concepts used

| Concept | Learned in |
|---|---|
| Digital outputs and LED sequences | Projects 01, 05 |
| PWM and brightness control | Projects 02, 04 |
| Push button with pull-down resistor | Project 03 |
| Functions and arrays | Project 07 |
| Non-blocking timing with *millis()* | Projects 09, 10, 11 |
| Software debounce | Project 11 |
| Hardware interrupts | Projects 12, 15 |
| Ultrasonic distance measurement | Projects 14, 15 |
| 16×2 LCD | Projects 16, 17 |
| IR remote control | Project 18 |
| Photoresistor and light threshold | Project 19 |

New in this project: a **state machine**. A single variable stores the current mode and decides which part of the code runs.

**Required libraries:** LiquidCrystal and IRremote (version 3.0 or newer), installed from the Arduino IDE Library Manager.

That's it! Thank you for following along with all my projects! :)

<img width="5045" height="2838" alt="tempImageVpAUKD" src="https://github.com/user-attachments/assets/1a692782-3554-4e58-a169-f44d6be5d9b9" />

