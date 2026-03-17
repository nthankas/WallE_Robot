# Wall-E Autonomous Trash-Sorting Robot

Autonomous robot that navigates a field using IR line following, identifies colored blocks with a TCS3200 color sensor, and sorts them into designated zones. Built on PIC32 (Uno32) using a hierarchical state machine architecture and an event-driven services framework.

I was the sole software developer on a 3-person team.

## Architecture

The software is structured as a hierarchical state machine (HSM) running on top of an event-driven framework (ES_Framework). The top-level HSM sequences through three field positions (center, left, right), and at each position runs a sub-HSM that handles the full pickup-classify-return cycle.

**Top-level HSM states:** `CenterState` -> `SortState` -> `LeftState` -> `SortState` -> `RightState` -> `SortState` -> `End`

**Sub-HSMs per position:**
- `CenterSubHSM` / `LeftSubHSM` / `RightSubHSM` -- drive to field position using IR alignment, approach block, grab if color detected, return to base line
- `SortSubHSM` -- dispatches to `RedFlowSubHSM` or `BlueFlowSubHSM` based on detected color, which handle turning toward the correct drop zone, releasing the block, and realigning

**Services (polled via timers):**
- `PingService` -- triggers ultrasonic sensor, runs distance event checker with hysteresis and low-pass filtering
- `ColorService` -- cycles through RGB filter channels on the TCS3200, runs color classification with confirmation counting
- `IRService` -- polls left/right IR reflectance sensors for line detection

## Sensors

- **IR line sensors** (RE5, RE7) -- binary reflectance sensors for detecting tape lines on the field. used for alignment at intersections and boundary detection
- **TCS3200 color sensor** (input capture 3) -- frequency-output color sensor. filter channels cycled in software, period measured via IC3 interrupt. classification uses per-channel thresholds with minimum separation requirements
- **HC-SR04 ultrasonic** (input capture 2) -- pulse-width distance measurement via IC2 interrupt. low-pass filtered with hysteresis for CLOSE/OBJDETECT/FAR state transitions

## Hardware

- PIC32MX320F128H (Uno32 board)
- H-bridge motor driver (PWM on EN_A/EN_B, direction via IN1-IN4)
- Dual RC servos for gripper arms
- TCS3200 color sensor (S0-S3 on PORTV, OUT on PORTY)
- Two IR reflectance sensors
- HC-SR04 ultrasonic rangefinder

## Building

MPLAB X project. Open `Wall_E.X/` in MPLAB X IDE, build for PIC32MX320F128H target.

## Supplementary

Full design report with hardware details and field layout: https://docs.google.com/document/d/1fikusQiG630Y7aG3ekzxieo5sgwm_m8mltexGN6xTHc/edit?usp=sharing
