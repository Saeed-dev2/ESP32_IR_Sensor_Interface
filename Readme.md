# ESP-IDF IR Sensor 

This project demonstrates how to interface an Infrared (IR) sensor with an ESP32 using the ESP-IDF framework. The example reads the IR sensor's output and prints its state to the serial monitor.

## Prerequisites

- ESP32 development board
- IR sensor
- ESP-IDF environment set up
- Connection wires

## Hardware Connections

- Connect the VCC of the IR sensor to the 3.3V of the ESP32.
- Connect the GND of the IR sensor to the GND of the ESP32.
- Connect the OUT of the IR sensor to a GPIO pin of the ESP32 (e.g., GPIO 4 ).

## Project Structure

 ```
Actually IR Sensor is the name of the folder.

IR Sensor
├── main
│ ├── CMakeLists.txt
│ └── main.c
├── CMakeLists.txt
└── sdkconfig
```

## Getting Started

1. Create a New ESP-IDF Project Create a new directory for your project and navigate to it:
```
idf.py create-project project-name
```
2. Add the IR_Sensor.c File Replace the content of IR_Sensor.c with the provided code.

3. Build and Flash the Project
Set the target to ESP32, build the project, and flash it to your ESP32 board:
```
idf.py set-target esp32
idf.py build
idf.py flash
```
4. Monitor the Output
Start the serial monitor to see the output:
```
idf.py monitor
```
To exit the serial monitor, press `Ctrl + ]` 

