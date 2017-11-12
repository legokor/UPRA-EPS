# UPRA-EPS
UPRA Electric Power(distributor) Subsystem
----
This subsystem provides the designated voltage levels for other subsystems and payloads, monitors power consumption, battery charge, battery temperature and switch off malfunctioned modules.

UPRA-EPS is connected to the system via UPRA-BUS, provides house-keeping and full power control over the subsystems and supports RBF start pin and DSW Switch for future cubesat applications.

## Hardware
In the Hardware folder the schematic and PCB design can be found. The hardware is AVR 8-bit (Arduino) based, later versions might upgraded to ARM based solutions.

## Firmware
The Firmware folder contains the embedded software for the UPRA-EPS for power distribution control, monitoring and internal communication.

## Battery Tester
The Battery_tester folder contains the hardware and software design of the test equipment to determine characteristics of different battery configurations. Results can be found at the Wiki section.
