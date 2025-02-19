# ACE_RobotArm

# 🦿 Two-Leg Robot | Bipedal Robot

This repository contains the source code and documentation for the development of an **autonomous bipedal robot**, designed to move stably and avoid obstacles using a **Finite State Machine (FSM)**. The robot is based on the **Raspberry Pi Pico W**, controlling **SG90 servomotors** via **PCA9685**, and using an **HC-SR04P ultrasonic sensor** for obstacle detection.

---

## 📌 Features

✅ **Basic locomotion** – Walk forward and perform rotations  
✅ **Obstacle detection** – Uses the HC-SR04P ultrasonic sensor  
✅ **Obstacle avoidance** – FSM-based decision-making  
✅ **Efficient servo control** – PCA9685 module for motor management  
✅ **Modular code** – Implemented in C++ for easy maintenance and expansion  

---

## 🛠️ Components Used

| Component                | Function |
|---------------------------|-----------------------------|
| **Raspberry Pi Pico W**   | Main microcontroller |
| **PCA9685**               | PWM controller for servos |
| **SG90 Servomotors**      | Actuators for locomotion |
| **HC-SR04P Sensor**       | Obstacle detection |
| **9V Battery**            | System power supply |

---

## 🏗️ Code Structure

📂 Two-Leg-Robot/ │── 📂 src/ # Main source code │ ├── main.cpp # FSM implementation and robot control │ ├── feet.cpp/.h # Servo motor control module │ ├── sensors.cpp/.h # Ultrasonic sensor reading module │── 📂 docs/ # Documentation and reports │── 📂 images/ # Schematics, diagrams, and robot pictures │── README.md # This document


---

## 🔧 Installation and Setup

1️⃣ **Clone the repository:**

git clone https://github.com/guiosorio15/Two-Leg-Robot.git

2️⃣ Open the project in the PlatformIO IDE (VSCode recommended)
3️⃣ Ensure you have the necessary libraries:

Wire.h (I2C for PCA9685)
Adafruit_PWMServoDriver.h (Servo motor control)
4️⃣ Upload the code to the Raspberry Pi Pico W

-

      FORWARD
          │
    DIST < 15cm
          ▼
     [TURN RIGHT] ----> [TURN LEFT]
          │
    (If obstacle still present)
          ▼
   [STOP OR TRY OTHER SIDE]

--- 
## Future Improvements

🔹 Implementing the GY-521 sensor to improve balance
🔹 Dynamic rotation adjustments to avoid obstacles more precisely
🔹 Possible Wi-Fi communication using Raspberry Pi Pico W
🔹 Integrating learning algorithms to improve locomotion



---

### 📌 Why This Structure?
✔ **Clear introduction** explaining the project’s purpose  
✔ **Component table** for quick reference  
✔ **Code structure** to help organize the repository  
✔ **Well-explained FSM** with diagrams  
✔ **Installation and setup steps**  
✔ **Future improvements** for project expansion  

Let me know if you need any modifications! 🚀
