#include <Arduino.h>

// --- Pin definitions ---
#define DIR_PIN1  0   // Stepper 1 direction
#define STEP_PIN1 1   // Stepper 1 step
#define DIR_PIN2  2   // Stepper 2 direction
#define STEP_PIN2 3   // Stepper 2 step

// --- Stepper parameters ---
#define STEPS_PER_REV 200    // Full steps per revolution
#define STEP_DELAY_US 1000   // Microseconds between steps (adjust for speed)

// --- FreeRTOS Task Handles ---
TaskHandle_t motorTaskHandle;

// --- Function to step both motors in sync ---
void stepMotors() {
  digitalWrite(STEP_PIN1, HIGH);
  digitalWrite(STEP_PIN2, HIGH);
  delayMicroseconds(2);       // minimum pulse width for DRV8825
  digitalWrite(STEP_PIN1, LOW);
  digitalWrite(STEP_PIN2, LOW);
}

// --- FreeRTOS task ---
void MotorTask(void *pvParameters) {
  while (1) {
    stepMotors();
    delayMicroseconds(STEP_DELAY_US); // control speed
  }
}

void setup() {
  // Initialize pins
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(STEP_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);

  // Set directions
  digitalWrite(DIR_PIN1, HIGH); // forward
  digitalWrite(DIR_PIN2, HIGH); // forward

  // Create the FreeRTOS task
  xTaskCreate(
    MotorTask,          // Task function
    "MotorTask",        // Name
    1024,               // Stack size
    NULL,               // Parameters
    1,                  // Priority
    &motorTaskHandle    // Task handle
  );
}

void loop() {
  // Empty loop — everything handled by FreeRTOS
}