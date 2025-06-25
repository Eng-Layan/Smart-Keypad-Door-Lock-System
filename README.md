# Smart Keypad Door Lock System

This is my third embedded systems project using Arduino and real hardware components, as part of my personal learning and portfolio development.

## Project Overview

A smart door lock system that allows the user to input a 4-digit password via keypad.  
If correct: the servo unlocks the door and LCD shows a success message.  
If incorrect: after 3 failed attempts, a buzzer alarm is triggered and the system locks.  
A reset button restores the system to its initial state.

## Components Used

- Arduino Uno  
- 4x4 Keypad  
- LCD 1602 (non-I2C)  
- Servo Motor  
- Buzzer  
- Push Button (Reset)  
- Potentiometer (for LCD contrast)  
- Breadboard and Jumper Wires

## Skills Practiced

- Arduino Programming (C++)  
- Embedded Systems Design  
- LCD and Keypad Interfacing  
- Servo Motor Control  
- Basic Hardware Debugging  
- Security Logic Implementation  
- Breadboard Wiring and Testing

## Circuit Pin Mapping

| Component     | Arduino Pin |
|---------------|-------------|
| LCD RS        | 7           |
| LCD EN        | 6           |
| LCD D4-D7     | 5, 4, 3, 2  |
| Keypad Pins   | 8, 9, A0, A1, A2, A3, A4, A5 (example) |
| Servo Signal  | 10          |
| Buzzer        | 11          |
| Reset Button  | 12 (INPUT_PULLUP) |
| Potentiometer | V0 (LCD contrast) |

## Code
📂 [Full code here](Smart_Keypad_Door_Lock_System.ino)

## Project Images
![IMG_2874](https://github.com/user-attachments/assets/4ee22d94-734b-48f9-ba41-c6df57a787ff)
![IMG_2875](https://github.com/user-attachments/assets/cda2bee9-474c-4aaa-aeda-c34d600f5701)
![IMG_2876](https://github.com/user-attachments/assets/b6f069da-131b-40c4-ba51-714ec6643c74)


## Project Videos

Video 1: Correct Password Entry  
[Watch: Correct Password Demo](https://youtu.be/SjerBMjpxxc)  
The user enters the correct password and the servo unlocks the door.

Video 2: Incorrect Password Entry  
[Watch: Incorrect Password Demo](https://youtu.be/OfVIvtr_v-E)  
The user enters wrong passwords three times, triggering the buzzer and locking the system.

## Future Improvements

- Save password to EEPROM  
- Add fingerprint or RFID authentication  
- Include real-time clock module (RTC)  
- Send SMS alerts via GSM on failed login attempts

## Author

Eng. Layan  
Electrical and Electronics Engineering – 4th Year  
Project 3 of my embedded systems portfolio  
Built using my personal Arduino starter kit

