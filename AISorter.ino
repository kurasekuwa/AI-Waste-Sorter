#include <Servo.h>

// Create servo object
Servo sorter;

// Hardware configuration
const int SERVO_PIN = 9;

// Sorting positions
const int RECYCLE_ANGLE = 30;
const int TRASH_ANGLE = 150;
const int REST_ANGLE = 90;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Connect servo to pin 9
  sorter.attach(SERVO_PIN);

  // Set initial position
  sorter.write(REST_ANGLE);

  Serial.println("Arduino Ready!");
}

void loop() {

  // Check for incoming commands
  if (Serial.available() > 0) {

    char command = Serial.read();

    // Recyclable
    if (command == 'R') {
      delay(1000);
      sorter.write(RECYCLE_ANGLE);
      Serial.println("Recyclable selected");
      delay(1000);
      sorter.write(REST_ANGLE);
      Serial.println("Sorter reset");
    }

    // TRASH
    else if (command == 'C') {
      delay(1000);
      sorter.write(TRASH_ANGLE);
      Serial.println("Plastic detected");
      delay(1000);
      sorter.write(REST_ANGLE);
      Serial.println("Sorter reset");
    }

    // Reset
    else if (command == 'N') {
      delay(1000);
      sorter.write(REST_ANGLE);
      Serial.println("Sorter reset");
    }
  }
}