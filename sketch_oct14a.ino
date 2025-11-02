/*
  Arduino Nano + PCA9685 - 3 Servo Test
  Simplified version to test 3 servos with PCA9685 board
  
  Connections (Nano to PCA9685):
  GND -> GND
  5V -> VCC
  A4 (SDA) -> SDA
  A5 (SCL) -> SCL
  
  Connect servos to PCA9685 channels 0, 1, 2
  External power (battery) -> V+ on PCA9685 for servo power
*/

#include "HCPCA9685.h"

// I2C address of PCA9685 (default is 0x40)
#define I2CAdd 0x40

// Create PCA9685 instance
HCPCA9685 HCPCA9685(I2CAdd);

// Initial positions for servos (0-180 degrees range)
int servo1_pos = 90;
int servo2_pos = 90;
int servo3_pos = 90;

// Movement increment
const int INCREMENT = 15;

// Min and max positions
const int MIN_POS = 10;
const int MAX_POS = 170;

char state = 0;

void setup() {
  // Initialize PCA9685
  HCPCA9685.Init(SERVO_MODE);
  HCPCA9685.Sleep(false);
  
  // Initialize serial
  Serial.begin(9600);
  
  // Move servos to initial positions
  HCPCA9685.Servo(0, servo1_pos);
  HCPCA9685.Servo(1, servo2_pos);
  HCPCA9685.Servo(2, servo3_pos);
  
  delay(1000);
  
  Serial.println("=== 3 Servo Test with PCA9685 ===");
  Serial.println("Commands:");
  Serial.println("1 - Servo 1 increase");
  Serial.println("2 - Servo 1 decrease");
  Serial.println("3 - Servo 2 increase");
  Serial.println("4 - Servo 2 decrease");
  Serial.println("5 - Servo 3 increase");
  Serial.println("6 - Servo 3 decrease");
  Serial.println("R - Reset all to 90 degrees");
  Serial.println("S - Show positions");
  Serial.println("================================");
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
    
    // Servo 1 controls (Channel 0)
    if (state == '1') {
      moveServo1Up();
    }
    if (state == '2') {
      moveServo1Down();
    }
    
    // Servo 2 controls (Channel 1)
    if (state == '3') {
      moveServo2Up();
    }
    if (state == '4') {
      moveServo2Down();
    }
    
    // Servo 3 controls (Channel 2)
    if (state == '5') {
      moveServo3Up();
    }
    if (state == '6') {
      moveServo3Down();
    }
    
    // Reset command
    if (state == 'R' || state == 'r') {
      resetAllServos();
    }
    
    // Show positions
    if (state == 'S' || state == 's') {
      showPositions();
    }
  }
}

void moveServo1Up() {
  if (servo1_pos < MAX_POS) {
    servo1_pos += INCREMENT;
    HCPCA9685.Servo(0, servo1_pos);
    Serial.print("Servo 1: ");
    Serial.println(servo1_pos);
    delay(20);
  } else {
    Serial.println("Servo 1 at MAX");
  }
}

void moveServo1Down() {
  if (servo1_pos > MIN_POS) {
    servo1_pos -= INCREMENT;
    HCPCA9685.Servo(0, servo1_pos);
    Serial.print("Servo 1: ");
    Serial.println(servo1_pos);
    delay(20);
  } else {
    Serial.println("Servo 1 at MIN");
  }
}

void moveServo2Up() {
  if (servo2_pos < MAX_POS) {
    servo2_pos += INCREMENT;
    HCPCA9685.Servo(1, servo2_pos);
    Serial.print("Servo 2: ");
    Serial.println(servo2_pos);
    delay(20);
  } else {
    Serial.println("Servo 2 at MAX");
  }
}

void moveServo2Down() {
  if (servo2_pos > MIN_POS) {
    servo2_pos -= INCREMENT;
    HCPCA9685.Servo(1, servo2_pos);
    Serial.print("Servo 2: ");
    Serial.println(servo2_pos);
    delay(20);
  } else {
    Serial.println("Servo 2 at MIN");
  }
}

void moveServo3Up() {
  if (servo3_pos < MAX_POS) {
    servo3_pos += INCREMENT;
    HCPCA9685.Servo(2, servo3_pos);
    Serial.print("Servo 3: ");
    Serial.println(servo3_pos);
    delay(20);
  } else {
    Serial.println("Servo 3 at MAX");
  }
}

void moveServo3Down() {
  if (servo3_pos > MIN_POS) {
    servo3_pos -= INCREMENT;
    HCPCA9685.Servo(2, servo3_pos);
    Serial.print("Servo 3: ");
    Serial.println(servo3_pos);
    delay(20);
  } else {
    Serial.println("Servo 3 at MIN");
  }
}

void resetAllServos() {
  servo1_pos = 90;
  servo2_pos = 90;
  servo3_pos = 90;
  
  HCPCA9685.Servo(0, servo1_pos);
  HCPCA9685.Servo(1, servo2_pos);
  HCPCA9685.Servo(2, servo3_pos);
  
  Serial.println("All servos reset to 90 degrees");
  delay(500);
}

void showPositions() {
  Serial.println("--- Current Positions ---");
  Serial.print("Servo 1 (Ch 0): ");
  Serial.println(servo1_pos);
  Serial.print("Servo 2 (Ch 1): ");
  Serial.println(servo2_pos);
  Serial.print("Servo 3 (Ch 2): ");
  Serial.println(servo3_pos);
  Serial.println("------------------------");
}