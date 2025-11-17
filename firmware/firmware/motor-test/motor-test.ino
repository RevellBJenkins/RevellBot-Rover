// RevellBot Rover - Motor Test Firmware
// Milestone 1: Motor Subsystem (L298N + Arduino Uno)

// Pin mapping for L298N

// Left motor
const int ENA = 5;   // PWM
const int IN1 = 7;   // direction A
const int IN2 = 8;   // direction B

// Right motor
const int ENB = 6;   // PWM
const int IN3 = 9;   // direction A
const int IN4 = 10;  // direction B

// Direction type
enum Direction {
  DIR_STOP,
  DIR_FORWARD,
  DIR_BACKWARD
};

// Set one motor
void setLeftMotor(Direction dir, int speed);
void setRightMotor(Direction dir, int speed);

// High level movement functions
void goForward(int speed);
void goBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMoving();

// Simple test sequence
void runTestPattern();

void setup() {
  // Set pin modes
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMoving();
}

void loop() {
  runTestPattern();
}

// Implementations

void setLeftMotor(Direction dir, int speed) {
  speed = constrain(speed, 0, 255);

  if (dir == DIR_STOP) {
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  } else if (dir == DIR_FORWARD) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
  } else if (dir == DIR_BACKWARD) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, speed);
  }
}

void setRightMotor(Direction dir, int speed) {
  speed = constrain(speed, 0, 255);

  if (dir == DIR_STOP) {
    analogWrite(ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else if (dir == DIR_FORWARD) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  } else if (dir == DIR_BACKWARD) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, speed);
  }
}

// High level movement helpers

void goForward(int speed) {
  setLeftMotor(DIR_FORWARD, speed);
  setRightMotor(DIR_FORWARD, speed);
}

void goBackward(int speed) {
  setLeftMotor(DIR_BACKWARD, speed);
  setRightMotor(DIR_BACKWARD, speed);
}

void turnLeft(int speed) {
  setLeftMotor(DIR_BACKWARD, speed);
  setRightMotor(DIR_FORWARD, speed);
}

void turnRight(int speed) {
  setLeftMotor(DIR_FORWARD, speed);
  setRightMotor(DIR_BACKWARD, speed);
}

void stopMoving() {
  setLeftMotor(DIR_STOP, 0);
  setRightMotor(DIR_STOP, 0);
}

// Simple pattern to verify everything
void runTestPattern() {
  goForward(180);
  delay(2000);

  stopMoving();
  delay(500);

  goBackward(180);
  delay(2000);

  stopMoving();
  delay(500);

  turnLeft(180);
  delay(1500);

  stopMoving();
  delay(500);

  turnRight(180);
  delay(1500);

  stopMoving();
  delay(2000);
}
