# Arduino Keypad Door Lock System (Password + Alarm)

This project is an Arduino-based keypad door lock system that allows the user to set a 4-digit password and unlock a door using a 4x4 keypad.

The system allows only **3 wrong attempts**. After three incorrect password entries, an alarm buzzer is activated. A solenoid lock is used to lock/unlock the door.

---

## 🔧 Hardware Used

- Arduino UNO / Nano
- 4x4 Matrix Keypad
- Solenoid Door Lock (via driver/transistor/relay)
- Buzzer
- Indicator LED (optional)
- Jumper Wires
- External Supply for Solenoid (recommended)

---

## 📦 Required Library

Install from Arduino Library Manager:

- **Keypad by Mark Stanley & Alexander Brevig**

---

## 🔌 Pin Connections (As per Code)

### ⌨️ Keypad (4x4)

| Keypad Pin | Arduino Pin |
|-------------|-------------|
| Row1 | D10 |
| Row2 | D9 |
| Row3 | D8 |
| Row4 | D7 |
| Col1 | D6 |
| Col2 | D5 |
| Col3 | D4 |
| Col4 | D3 |

---

### 🔔 Buzzer

| Buzzer | Arduino |
|---------|----------|
| + | D13 |
| – | GND |

---

### 🔒 Solenoid Lock (via Driver)

| Control | Arduino |
|----------|----------|
| Driver IN / Relay IN | D11 |

> ⚠️ Do NOT connect solenoid lock directly to Arduino pin.  
> Use transistor or relay driver + flyback diode.

---

## ⚙️ Working Logic

- On power up → user sets a **4-digit password**
- Each key press gives buzzer feedback
- User must enter correct password to unlock
- If password is correct:
  - Lock output pin goes HIGH for 5 seconds
- If password is wrong:
  - Error beep
  - Retry allowed
- After **3 wrong attempts**:
  - Alarm buzzer sounds for 10 seconds

---

## ▶️ How to Run

1. Install Keypad library
2. Connect keypad, buzzer, and lock driver
3. Upload code to Arduino
4. Open Serial Monitor (9600 baud)
5. Set your 4-digit password
6. Enter password to unlock

---

## 🔐 Security Features

- User-defined password at startup
- 3-attempt limit
- Audible alarm on lockout
- Audible keypress feedback

---

## 📷 Circuit Diagram

Circuit diagram image will be added soon. Wiring table is provided above.

---

## 🎥 Working Video

https://www.youtube.com/shorts/o6KKp9bXInk

---

## ⚠️ Safety Notes

- Use transistor + diode for solenoid lock
- Use external supply for lock coil
- Common GND between Arduino and driver
- Add base resistor for transistor
- Never power solenoid directly from Arduino pin

---

## 👨‍💻 Author

Gautam — Robotics & Embedded Projects
