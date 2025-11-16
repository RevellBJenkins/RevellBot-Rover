# Milestone 1 — Motor Subsystem

This milestone establishes the foundation of the rover by creating a reliable, well-documented motor control system.  
All higher-level behaviors (encoders, navigation, state machine, avoidance) depend on stable and predictable motor outputs.

---

## 🎯 Goals
- Understand the L298N motor driver interface  
- Map direction and PWM pins  
- Build a safe and stable wiring plan  
- Test raw motor behavior  
- Create movement functions (forward, reverse, turn, stop)  
- Prepare for eventual migration to Cytron MDD10A

---

## 🧩 Motor Driver: L298N (Current Hardware)
The L298N will be used for TinkerCad simulation and early development because it is easily accessible and already available.

### Motor Channels
- **Left Motor:** OUT1, OUT2  
- **Right Motor:** OUT3, OUT4  

### Control Pins
Each motor uses:
- 2 direction pins (IN1/IN2 or IN3/IN4)
- 1 PWM pin (ENA or ENB)

---

## 🛠 Pin Mapping (Arduino Uno)

### Left Motor
| L298N Pin | Arduino Pin | Purpose        |
|----------|-------------|----------------|
| ENA      | D5 (PWM)    | Speed Control  |
| IN1      | D7          | Direction A    |
| IN2      | D8          | Direction B    |

### Right Motor
| L298N Pin | Arduino Pin | Purpose        |
|----------|-------------|----------------|
| ENB      | D6 (PWM)    | Speed Control  |
| IN3      | D9          | Direction A    |
| IN4      | D10         | Direction B    |

---

## 🔌 Wiring & Power Plan

### Motor Power
- External motor power (battery pack or DC supply) → L298N **+12V**
- L298N ground connected to motor battery ground

### Arduino Power
- Arduino powered through USB  
- Avoid powering Arduino from L298N 5V regulator for now

### Ground Strategy
All grounds must be connected:
- Arduino GND  
- L298N GND  
- Motor battery GND  

This establishes a shared reference for PWM and direction signals.

---

## 📐 Wiring Diagram
Place wiring images or TinkerCad screenshots here once completed.

(Example file path: `hardware/wiring-diagrams/l298n-setup.jpg`)

---

## 🧪 Planned Motor Tests

### 1. Direction Verification
- Left motor forward
- Left motor reverse  
- Right motor forward  
- Right motor reverse  
- Correct wiring if directions are inverted

### 2. PWM Behavior
- Test 0%, 50%, 75%, 100% duty cycles  
- Identify minimum PWM threshold where each motor starts moving  
- Note any jitter or noise

### 3. Combined Motion Tests
- Forward (both motors same direction)
- Reverse
- Turn left (right forward, left reverse)
- Turn right (left forward, right reverse)
- Stop

---

## 🧱 Movement Function Structure (Planned)

### Low-Level Controls
- `setLeftMotor(direction, speed)`  
- `setRightMotor(direction, speed)`

### High-Level Behaviors
- `goForward(speed)`  
- `goBackward(speed)`  
- `turnLeft(speed)`  
- `turnRight(speed)`  
- `stopMoving()`  

These functions will be created in Subsection 3.

---

## 📌 Notes for Future Migration (Cytron MDD10A)
- Movement function names remain the same  
- Only low-level driver logic changes  
- Direction pins become DIR_L and DIR_R  
- PWM pins become PWM_L and PWM_R  
- No enable pin required  
- Higher efficiency and lower heat

---

## 📎 Status
Hardware planning complete.  
Wiring and power verification will precede writing the first motor test firmware.
