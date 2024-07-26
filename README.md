# MedRADAR3D

MedRADAR3D is an assistant-system for general practitioners, which allows them to recognize/diagnose a skin anomaly and seek help (possibly remotely) from a trained physician

<img src="https://github.com/user-attachments/assets/d8fe5d21-fe1c-42ce-9bfe-9b3c4fe13b02" alt="Description" width="480" height="480">

## How does it work?

The device's axis of rotation (marked by a laser) is placed over the patient's affected skin area. This is made easier by the lockable wheel mounted on the bottom of its frame. After this the physician, making use of the interface, adjusts the Z axis until the abnormality itself finds itself in the middle of the image frame. Having done that, he/she can start the preprogrammed sequence for scanning the skin region.

<img src="https://github.com/user-attachments/assets/fd701316-a162-4e13-a6c8-e971d75cf202" alt="Description" width="600" height="337">

## Technical description

### Device
The device itself is composed of 4 main parts:
- Steel Frame with Lockable Wheels
- XYZ linear axis powered by Nema17 Stepper Motors
- Camera arm assembly
- Arduino Control & Command
Note: In the present whe are using a Sony a6000 camera with a 50mm Macro Lens. In the future we plan on using a microscope camera, better suited for this application
