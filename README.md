# CoilFormer
## Introduction
This project covers the design and construction of a precision coil winding machine, intended for manufacturing coils for a medium-sized Tesla coil. The project combines mechanical design, electronics, embedded control, and manufacturing considerations and is reproducable with simple components and a 3D printer

IMAGE

The coil winder is designed to:

- Accurately traverse wire along a cylindrical former

- Synchronize former (tube that holds the coil) rotation with linear motion (wire carriage driven on rails by lead screw)

- Produce repeatable, tightly-packed windings suitable for high-voltage resonant coils

The end goal is to use this machine to wind a Tesla coil secondary in the ~40–70 mm diameter and ~100–250 mm length range.

## Subsystems
### Mechanical Subsystem

- Rigid frame with subframe-mounted components to increase precision

- Lead screw–driven wire carriage for linear traverse

- Direct-drive spindle for coil former rotation

- Floating far-end supports to allow for misalignment between subframe and frame

### Electrical Subsystem

- Dual stepper motor control (spindle + traverse)

- Shared DC power supply

- Microcontroller-based (esp32) motion control

### Software Subsystem

Microcontroller responsible for:

- Step/direction generation

- Coordinated motion (turns vs traverse pitch)

- User-defined winding parameters (wire gauge, former diameter)

## Parts List
### Mechanical Components

- Lead screw	T8, 2 mm lead, ~330–350 mm
- Brass nut	Matched to T8 lead screw
- Bearings,	608ZZ (floating far end)
- Stepper motors	2 × NEMA 17 (spindle + traverse)
- Motor-Lead Screw Coupling
- 3D-printed fitting for coil former
- Far-end V-groove support
- Nut carriage	Holds brass nut and wire guide
- Wire guide, printed loop
- 3D printed carriage
- 2 x 8mm Stainless Rod 350mm length
- 3D printed framing
- Fittings (Various nuts and bolts)

### Electrical Components

- 2 × DRV8825 Stepper Drivers
- ESP32 (arduino or other board)
- Power supply	12 V DC, 5 A
- Wiring/connectors/Hook-up wire
- 2 x 100uF electrolytic capacitors

## Design Considerations
### Mechanical

- Subframe-based mounting allows loose tolerances on individual brackets and creates reference plane

- Floating far-end support prevents overconstraint of the coil former

### Electrical

- Shared VMOT and GND across stepper drivers

- Driving steppers via DRV8825 Vref is critical to prevent missed steps, provide current protection, and save the microcontroller from directly interacting with high voltage

- USB power used for programming/debug, external supply for motors

