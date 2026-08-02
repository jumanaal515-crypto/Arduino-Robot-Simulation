#  Arduino Smart Robot Controller (Combined Simulation Task)

##  Project Overview
This project is an advanced Arduino-based simulation developed using **Tinkercad**. 

Although the assignment offered two individual options, this implementation **successfully combines both tasks into a single intelligent system**, providing complete motor motion control along with autonomous obstacle detection and avoidance.

---

##  Task Breakdown & Features

###  Task 1 Features: Timed Motion Logic
* **Forward Movement:** Drives all 4 DC Motors forward for **30 seconds**.
* **Backward Movement:** Reverses all 4 DC Motors for **1 minute (60 seconds)**.
* **Alternating Turns:** Alternates turning Right and Left sequentially for **1 minute (60 seconds)**.

###  Task 2 Features: Autonomous Obstacle Avoidance
* **Distance Sensing:** Uses an **Ultrasonic Distance Sensor** to continuously monitor the path ahead.
* **Safety Threshold:** If an obstacle is detected within **$\le 10\text{ cm}$**, the system immediately overrides the sequence and stops all motors.
* **Environment Scanning:** A **Servo Motor** rotates to scan the surroundings for safe clearance.
* **Path Rerouting:** Automatically reverses and turns to avoid collision before resuming normal operation.

---

##  Hardware Components

| Component | Quantity | Description |
| :--- | :---: | :--- |
| **Arduino Uno R3** | 1 | Main Microcontroller |
| **L293D Motor Driver IC** | 1 | Controls the 4 DC Motors (H-Bridge) |
| **DC Motors** | 4 | Robot Wheels Drive System |
| **Micro Servo Motor** | 1 | Rotates for Scanning (Connected to Pin 11) |
| **Ultrasonic Distance Sensor** | 1 | 3-pin Sensor for Obstacle Detection (Connected to Pin 7) |
| **9V Battery** | 1 | External Power Supply for Motors |

---

##  Circuit Pinout Connections

* **L293D Inputs (Motors Control):**
  * `IN1` $\rightarrow$ Arduino **Pin 2**
  * `IN2` $\rightarrow$ Arduino **Pin 3**
  * `IN3` $\rightarrow$ Arduino **Pin 4**
  * `IN4` $\rightarrow$ Arduino **Pin 5**
* **Ultrasonic Sensor (3-pin):**
  * `VCC` $\rightarrow 5\text{V}$ | `GND` $\rightarrow \text{GND}$ | `SIG` $\rightarrow$ Arduino **Pin 7**
* **Servo Motor:**
  * `VCC` $\rightarrow 5\text{V}$ | `GND` $\rightarrow \text{GND}$ | `Signal` $\rightarrow$ Arduino **Pin 11**

---

##  Source Code
The complete code (`main.ino`) is included in this repository. It utilizes the `<Servo.h>` library and custom pulse logic to read distance from the 3-pin ultrasonic sensor.

---

##  Simulation
* Developed & Tested on **Tinkercad Circuits**.
