#include <Servo.h>

// Define the number of servos
#define NUM_SERVOS 10

// Create an array to hold the servo objects
Servo servos[NUM_SERVOS];

// Define the pins for the servos
int servoPins[NUM_SERVOS] = {2,3,4,5,6,9,10,11,12,13};

// Define the pins for the start and stop buttons
const int startButtonPin = 7;
const int stopButtonPin = 8;

// Variables to hold the button states
bool startPressed = false;
bool stopPressed = false;

// Arrays to hold shuffled servo indices
int order1[NUM_SERVOS] = {6, 2, 9, 0, 4, 3, 1, 7, 5, 8};
int order2[NUM_SERVOS] = {7, 1, 9, 0, 6, 4, 8, 3, 5, 2};
int order3[NUM_SERVOS] = {5, 9, 1, 6, 2, 7, 0, 8, 4, 3};
int order4[NUM_SERVOS] = {3, 7, 2, 0, 5, 8, 9, 6, 1, 4};
int order5[NUM_SERVOS] = {2, 5, 8, 1, 9, 0, 6, 4, 7, 3};
int order6[NUM_SERVOS] = {4, 7, 0, 1, 9, 2, 6, 5, 8, 3};
int order7[NUM_SERVOS] = {0, 9, 2, 7, 1, 6, 8, 4, 3, 5};
int order8[NUM_SERVOS] = {3, 8, 0, 5, 4, 7, 6, 9, 2, 1};
int order9[NUM_SERVOS] = {9, 6, 1, 5, 7, 2, 0, 4, 3, 8};
int order10[NUM_SERVOS] = {7, 4, 3, 0, 6, 5, 2, 1, 8, 9};

// Simulate the map using arrays
int* orders[10] = {order1, order2,order3,order4,order5,order6,order7,order8,order9,order10};

// Flag to indicate if the execute function should be running
bool isExecuting = false;

void setup() {
  // Start the Serial Monitor
  Serial.begin(9600);
  
  // Attach the servos to their pins
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
  }

  // Initialize the button pins with internal pull-up resistors
  pinMode(startButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);

  // Seed the random number generator using an unconnected analog pin
  randomSeed(analogRead(A0));

  // Initialize the servos to the initial position
  resetServos();
}

void loop() {
  // Check if the start button is pressed
  if (digitalRead(startButtonPin) == LOW && !startPressed) {
    startPressed = true;
    Serial.println("Start button pressed");
    isExecuting = true;
    delay(1000);
    execute(); 
    delay(200);  // Debounce delay
  } else if (digitalRead(startButtonPin) == HIGH && startPressed) {
    startPressed = false;
  }

  // Check if the stop button is pressed
  if (digitalRead(stopButtonPin) == LOW && !stopPressed) {
    stopPressed = true;
    Serial.println("Stop button pressed");
    isExecuting = false;  // Set the flag to stop execution
    delay(200);  // Debounce delay
  } else if (digitalRead(stopButtonPin) == HIGH && stopPressed) {
    stopPressed = false;
  }
}

void execute() {
  // Get a random order between 0 and 1
  int orderIndex = random(0, 10); 
  Serial.println(orderIndex);
  int* order = orders[orderIndex];

  for (int i = 0; i < NUM_SERVOS; i++) {
    if (!isExecuting) {
      Serial.println("Execution stopped");
      resetServos();
      return;
    }
    Serial.print("Rotating servo ");
    Serial.println(order[i]);
    servos[order[i]].write(90);
    delay(600);
    
    // Break the delay into smaller increments and check the stop button
    for (int j = 0; j < 1000; j += 50) {
      delay(50);
      if (digitalRead(stopButtonPin) == LOW) {
        isExecuting = false;
        Serial.println("Stop button pressed during execution");
        resetServos();
        return;
      }
    }
  }

  resetServos();  // Reset servos after completing the sequence
}

void resetServos() {
  Serial.println("Resetting all servos");
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].write(-30);
  }
}
