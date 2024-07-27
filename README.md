# MedRADAR3D

MedRADAR3D is an assistant-system for general practitioners, which allows them to recognize/diagnose a skin anomaly and seek help (possibly remotely) from a trained physician

<img src="https://github.com/user-attachments/assets/d8fe5d21-fe1c-42ce-9bfe-9b3c4fe13b02" alt="Description" width="480" height="480">

## How does it work?

The device's axis of rotation (marked by a laser) is placed over the patient's affected skin area. This is made easier by the lockable wheel mounted on the bottom of its frame. After this the physician, making use of the interface, adjusts the Z axis until the abnormality itself finds itself in the middle of the image frame. Having done that, he/she can start the preprogrammed sequence for scanning the skin region.

<img src="https://github.com/user-attachments/assets/fd701316-a162-4e13-a6c8-e971d75cf202" alt="Description" width="600" height="337">

## Explanation of processes



## Technical description

### Device
The device itself is composed of 4 main parts:
- Steel Frame with Lockable Wheels
- XYZ linear axis
- Camera arm assembly
- Arduino Control & Command

The XYZ linear axis are powered by Nema 17 stepper motors (X and Z motors have 5.18 reduction) with leadscrews. 
  
> [!NOTE]
> In the present whe are using a Sony a6000 camera with a 50mm Macro Lens. In the future we plan on using a microscope camera, better suited for this application

## AI
There are currently services that can photograph/capture information related to skin diseases, but what is unique about our project is the integration of an Artificial Intelligence system that can process the information and then provide a diagnosis and express new information, like a doctor looking at the patient and seeing new information.
The program runs without the need for interaction with a specialist, it relies solely on images, motion and other information captured as input by the device. In this way, the program shortens the time it takes to diagnose patients and provides useful information to specialists even if they are at a distance, such as in rural areas. Basically, doctors could easily visualize the analyses through a medical data visualization panel provided by the device. 
Once the data is retrieved from the robot arm, the program uses the set of images and motions to mask the image to delineate the area in question from the rest of the surrounding skin. Next, the program determines a category of condition to which the mole/rash may belong, providing probabilities associated with each category. Following this process realized through Convolutional Neural Networks (CNN) and consultation with another statistical examination method (Random Forest), the Artificial Intelligence model finds that the input information is conclusive to draw a conclusion on the diagnosis. Moreover, this program also performs a three-dimensional mapping of the scanned surface and renders a complete data package to a visualization panel of the processed data in an interpretable and intuitive form.

<img src="https://github.com/user-attachments/assets/1bc5fc0b-1915-44d3-8c1e-df72926cca76" alt="Description" width="520" height="240">

## Interface

<img src="https://github.com/user-attachments/assets/4384ad20-a933-4e65-9f67-23547249fecb" alt="Description" width="320" height="440">
