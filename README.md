#  Smart Parking System — IoT Based

A smart parking automation system with **two different approaches** to monitor and display available parking slots using **ESP32 + LCD**.

This project provides **real-time parking visibility**, reduces human effort, and works for both gated and open parking layouts.

---

## Features
- Real-time display of available parking slots
- Two different parking detection methods
- Works with ESP32 DevKit V1 & ESP32-S2 (simulation support)
- I2C LCD interface for user display
- Simple logic & scalable up to many slots
- Ideal for college/mini-projects and real deployment

---

##  System Architecture

### Method 1 — Entry/Exit Gate Detection
Uses **2 IR sensors** at the gate:
- Detects whether a car is entering or leaving
- Updates available slots count

Pros: No need for sensors at each slot  
Cons: May detect humans or bicycles → false count

📂 Code:  
`Method1_EntryExit/EntryExit.ino`

📂 Simulation Screenshots:  
`Method1_EntryExit/simulation/`

---

### Method 2 — Per-Slot Occupancy Detection
Each slot has **one IR sensor**:
- Directly detects whether the car is present in the slot

 Pros: Most accurate, no false human detection  
 Cons: More hardware required

📂 Code:  
`Method2_PerSlot/PerSlot.ino`

---

## Hardware Requirements

| Component | Qty |
|----------|:---:|
| ESP32 DevKit V1 / ESP32-S2 | 1 |
| IR Sensors | 2 (Method 1) / 10 (Method 2) |
| 20x4 I2C LCD | 1 |
| Jumper wires & Breadboard | — |

---

##  Pin Configuration

### ESP32 DevKit V1 (Physical Hardware)
| Function | Pin |
|--------|----|
| SDA (LCD) | GPIO 21 |
| SCL (LCD) | GPIO 22 |
| IR Entry | GPIO 25 |
| IR Exit | GPIO 26 |
| Slot Sensors | GPIO 3,4,5,12,13,14,15,16,17,18 |

### Simulation (online)

[View simulation on Wokwi](https://wokwi.com/projects/449577927265103873)

### ESP32-S2 (Simulation)
| Function | Pin |
|--------|----|
| SDA (LCD) | GPIO 33 |
| SCL (LCD) | GPIO 35 |

Modify this line based on your board:
```cpp
// DevKit V1
Wire.begin(21,22);

// ESP32-S2 (Simulation)
Wire.begin(33,35);
