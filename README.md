# Car Parking System
## Project Overview
This system uses an ultrasonic sensor to measure the distance between the vehicle and an obstacle. The distance is displayed on an LCD screen, and based on the proximity, the system responds using LED lights and a buzzer:
-	Far objects (Distance > 20 cm): All LEDs OFF, no buzzer (safe to proceed 🚘)
-	Moderate distance (16 cm ≤ Distance ≤ 20 cm): Red LED ON (caution ⚠️)
-	Closer objects (11 cm ≤ Distance ≤ 15 cm): Red & Green LEDs ON (approaching🚧)
-	Very close (6 cm ≤ Distance ≤ 10 cm): All LEDs ON (critical distance 🚨)
-	Too close (Distance ≤ 5 cm): All LEDs flash and the buzzer sounds, LCD displays “STOP” (immediate stop required 🛑)


## Project On Proteus
![Screenshot 2024-10-17 153101](https://github.com/user-attachments/assets/dd72b525-8bbf-4051-8b87-ea23c5c132d0)

## Software Layers
- **MCAL**: Drivers for hardware interaction (ADC, GPIO).
- **HAL**: Abstraction for controlling sensors and actuators.
- **Application Layer**: Logic for adjusting lights,alerts.

## Hardware Components
- **Microcontroller**: ATmega32
- **Sensors**: ultrasonic sensor
- **Actuators**: LEDs, Buzzer
- **Display**: 16x2 LCD for system status
