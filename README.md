# 🤖 ROBOTIC ARM: 6-DOF Arduino-Based Automation System

[![GitHub license](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/yourusername/your-repo-name/blob/main/LICENSE)
[![Project Status](https://img.shields.io/badge/Status-Completed-success)](https://github.com/yourusername/your-repo-name/issues)
[![Built with Arduino](https://img.shields.io/badge/Platform-Arduino-blue)](https://www.arduino.cc/)

## 🚀 Overview

This project is a **Six-Degree-of-Freedom (6-DOF) Robotic Arm** designed and built for automation and educational purposes. The arm achieves precise control across all six axes, making it a versatile platform suitable for a variety of pick-and-place, sorting, or complex manipulation tasks.

The entire system was developed using **3D-printed components** for rapid prototyping and customization, with an **Arduino-based controller** providing a flexible and easy-to-program embedded system.

## 🛠️ Key Features & Technical Specifications

* **Degrees of Freedom (DOF):** 6 DOF (Base, Shoulder, Elbow, Wrist Roll, Wrist Pitch, Gripper).
* **Fabrication Method:** Fully designed and fabricated using 3D printing.
* **Control System:** Arduino-based control for flexibility and ease of programming.
* **Core Components:**
    * Servo Motors: MG996R (for high torque joints).
    * Motor Driver: PCA9685 16-channel 12-bit PWM Servo Driver.
    * Actuator: NEMA-17 Stepper Motor (for the base or another key joint).
    * Controller: IR sensor and a random ir remote we found.
* **Applications:** Automation, pick-and-place, educational platform for robotics and embedded systems.

## 📖 Table of Contents

- [Overview](#-overview)
- [Key Features & Technical Specifications](#️-key-features--technical-specifications)
- [System Architecture](#-system-architecture)
- [Hardware & Materials](#-hardware--materials)
- [Software & Installation](#-software--installation)
- [Usage & Operation](#-usage--operation)
- [Future Enhancements](#-future-enhancements)
- [References & Acknowledgments](#-references--acknowledgments)

## 🏗️ System Architecture

The system is designed with a clear separation between the mechanical structure, the sensing input, and the control output. The Arduino microcontroller serves as the central brain, processing input from the control interface (e.g., MPU6050 for gestures or a joystick) and translating it into precise Pulse Width Modulation (PWM) signals for the servo motors via the PCA9685 driver.

## 📦 Hardware & Materials

To replicate this project, you will need the following key components:

| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| Arduino Microcontroller (e.g., Uno/Mega) | 1 | Main control unit |
| MG996R Servo Motor | 6 | Joint actuation |
| NEMA-17 Stepper Motor | 1 | High-precision joint (e.g., Base) |
| PCA9685 Servo Driver | 1 | PWM signal management |
| 3D Printed Parts | 1 set | Mechanical structure of the arm |
| IR Sensor & remote | 1 set | Controlling the arm |

## 💻 Software & Installation

### Prerequisites

* Arduino IDE (Latest version recommended)
* Required Libraries:
    * `Adafruit PCA9685 Library`
    * `MPU6050 Library` (e.g., Jeff Rowberg's library)
    * [**PLACEHOLDER: Other Libraries**]
