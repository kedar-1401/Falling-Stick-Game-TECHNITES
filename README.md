# Falling-Stick-Game-TECHNITES

This Arduino sketch controls a system of 10 servos using two buttons for starting and stopping the operation. The servos operate in a randomized sequence, allowing for flexibility in their movements.

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Pin Configuration](#pin-configuration)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Features

- Controls up to 10 servos.
- Randomized execution order for the servos.
- Start and stop functionality using buttons.
- Resets all servos to a default position.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Mega)
- 10 servos
- 2 push buttons
- Breadboard and jumper wires

## Pin Configuration

| Component        | Pin Number |
|------------------|------------|
| Servo 1          | 2          |
| Servo 2          | 3          |
| Servo 3          | 4          |
| Servo 4          | 5          |
| Servo 5          | 6          |
| Servo 6          | 9          |
| Servo 7          | 10         |
| Servo 8          | 11         |
| Servo 9          | 12         |
| Servo 10         | 13         |
| Start Button     | 7          |
| Stop Button      | 8          |

## How It Works

1. **Initialization**: The program initializes servos and buttons in the `setup()` function. Each servo is attached to its corresponding pin.
2. **Button Input**: It listens for button presses. When the start button is pressed, it triggers the `execute()` function, which operates the servos in a randomized order. The stop button can interrupt this operation at any time.
3. **Servo Execution**: The `execute()` function randomly selects a sequence of servo movements. Each servo is moved to a position with a delay between movements to allow for visible operation.
4. **Resetting Servos**: After the execution or if interrupted, all servos are reset to a defined position.

## Installation

1. Connect the servos to the specified pins on your Arduino.
2. Connect the buttons to the corresponding pins.
3. Upload the code to your Arduino using the Arduino IDE.
4. Open the Serial Monitor to view status messages.

## Usage

- **Start Operation**: Press the start button to initiate the servo movement sequence.
- **Stop Operation**: Press the stop button at any time to stop the servo operations and reset their positions.

## License

This project is open-source. Feel free to modify and use the code as needed.

---

For more information, feel free to check the code and discuss.

Aman Revankar (221IT007) 
Anush Revankar (221AI009)
B Sriram (231CS116) 
R Adithya (231CS146)
Kedar Dhule (221IT023)
Sharayu Ghadge (221ME120)

Happy coding!
