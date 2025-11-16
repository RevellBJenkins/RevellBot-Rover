# Milestone Roadmap

This document outlines the full development plan for the RevellBot Rover.  
Each milestone builds the engineering foundation required for a fully autonomous differential drive robot.

---

## ✔ Milestone 1 — Motor Subsystem (Current)
- Understand motor driver interface (L298N → Cytron MDD10A later)
- Map control pins (PWM + DIR)
- Build wiring plan and power setup
- Create movement functions (forward, reverse, turn)
- Verify smooth PWM control

---

## Milestone 2 — Wheel Encoders
- Select encoder type
- Read encoder ticks using interrupts
- Calculate wheel RPM and distance
- Begin understanding closed loop control

---

## Milestone 3 — Dead Reckoning
- Use encoder data to track x, y, and heading
- Implement basic differential drive kinematics
- Understand drift and accumulated error

---

## Milestone 4 — Obstacle Sensing
- Integrate ultrasonic or ToF sensors
- Smooth distance data (noise reduction)
- Implement threshold-based detection

---

## Milestone 5 — Reactive Avoidance Logic
- Build a simple behavior system
- Prioritize safety behaviors (avoid → turn → resume)
- Handle conflicting sensor inputs

---

## Milestone 6 — Finite State Machine
- Define system states (IDLE, FORWARD, AVOID, TURN, STOP)
- Build clean transition logic
- Replace if/else chains with structured architecture

---

## Milestone 7 — ESP32 Port (PlatformIO)
- Move codebase to ESP32
- Implement non-blocking timing (millis-based or timers)
- Organize firmware into modules
- Support dual-core processing if useful

---

## Milestone 8 — Advanced Sensors
- Integrate IMU (MPU6050 or BNO055)
- Fuse heading + acceleration with wheel encoders
- Improve accuracy of robot’s position estimate

---

## Milestone 9 — Navigation Behaviors
- Drive specific distances
- Turn to specific headings
- Implement simple waypoint logic
- Add early PID control where needed

---

## Milestone 10 — ROS2 Integration (Long Term)
- Create publishers/subscribers for motor commands and sensor data
- Use TF for robot coordinate frames
- Build a basic ROS2 node for high-level control

---

This roadmap guides the entire project from beginner-level motor control to professional robotics development.

