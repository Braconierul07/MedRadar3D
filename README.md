# MedRADAR3D

MedRADAR3D is an assistant-system for general practitioners, which allows them to recognize/diagnose a skin anomaly and seek help (possibly remotely) from a trained physician.

<img src="https://github.com/user-attachments/assets/d8fe5d21-fe1c-42ce-9bfe-9b3c4fe13b02" alt="Description" width="480" height="480">

## How does it work?

The process begins with the patient being positioned on a specially designed medical bed. This bed is tailored to ensure optimal access for the robotic arm and camera system, facilitating an accurate and thorough examination.

Once the patient is in place, the robotic arm must be manually positioned over the specific area of concern on the patient's skin. This is achieved through an interface controlled by medical personnel, ensuring that the arm is correctly aligned with the zone requiring examination. Precise positioning is crucial, as it sets the stage for the subsequent automated scanning process.

With the robotic arm in position, the next step involves manually controlling the robotic arm to ensure the laser is precisely aimed at the mole or skin problem. This step requires careful attention from the operator to guarantee the laser is accurately placed, which is essential for obtaining high-quality images during the scan.

<img src="https://github.com/user-attachments/assets/fd701316-a162-4e13-a6c8-e971d75cf202" alt="Description" width="600" height="337">

## Explanation of processes



## Technical description

### Device
The device itself is composed of 4 main parts:
- Steel Frame with Lockable Wheels
- XYZ linear axis
- Camera arm assembly
- Arduino Control & Command

The XYZ linear axis are powered by Nema 17 stepper motors (X and Z motors have 5.18 reduction) with leadscrews and anti-backlash nuts. The linear travel is made possible by 2080 Gantry plates rolling on 2040 V-Slot Profile Beams.
The camera arm is rotated also by a Nema 17 stepper motor with 5.18 reduction for more precision. It consists of a 2040 beam on which the camera is mounted using a 45<sup>o</sup> mount. This allows the operator to increase or decrease the distance between the camera and the axis of rotation, which in turn creates a possiblity for zooming.


<img src="https://github.com/user-attachments/assets/24b6891b-3e5e-4ab2-bcbd-cba24c1bc1cf" alt="Description" width="480" height="320">
<img src="https://github.com/user-attachments/assets/a915f63b-3aa2-411a-838e-79872a6809ef" alt="Description" width="480" height="480">
<img src="https://github.com/user-attachments/assets/bb791b76-dc9f-47c2-86ea-0c1e750c3d03" alt="Description" width="964" height="480">


> [!NOTE]
> In the present whe are using a Sony a6000 camera with a 50mm Macro Lens. In the future we plan on using a microscope camera, better suited for this application.

> [!NOTE]
> Many parts where printed using PETG filament, ensuring greater mechanical strength in the system.

## AI
There are currently services that can photograph/capture information related to skin diseases, but what is unique about our project is the integration of an Artificial Intelligence system that can process the information and then provide a diagnosis and express new information, like a doctor looking at the patient and seeing new information.

The program runs without the need for interaction with a specialist, it relies solely on images, motion and other information captured as input by the device. In this way, the program shortens the time it takes to diagnose patients and provides useful information to specialists even if they are at a distance, such as in rural areas. Basically, doctors could easily visualize the analyses through a medical data visualization panel provided by the device. 

Once the data is retrieved from the robot arm, the program uses the set of images and motions to mask the image to delineate the area in question from the rest of the surrounding skin. Next, the program determines a category of condition to which the mole/rash may belong, providing probabilities associated with each category. Following this process realized through Convolutional Neural Networks (CNN) and consultation with another statistical examination method (Random Forest), the Artificial Intelligence model finds that the input information is conclusive to draw a conclusion on the diagnosis. Moreover, this program also performs a three-dimensional mapping of the scanned surface and renders a complete data package to a visualization panel of the processed data in an interpretable and intuitive form.

<img src="https://github.com/user-attachments/assets/1bc5fc0b-1915-44d3-8c1e-df72926cca76" alt="Description" width="520" height="240">

## Interface

The MedRADAR3D interface is a crucial component of the skin scanning robot system, providing seamless control over the robotic arm and facilitating precise diagnostic procedures. Developed using the PyQt5 library and connected to the robotic arm via an Arduino Nano, this interface is designed to enhance the accuracy and efficiency of skin problem diagnostics.

The interface is divided into two main sections: Manual Control and Auto. The Manual Control section allows the operator to move the robotic arm along all its axes (XYZ) with dedicated buttons for directional movements. This granular control ensures that the camera can be positioned accurately over the specific area of concern on the patient's skin.

Once the camera and laser are accurately positioned, the operator can initiate the scanning process by pressing the "SCANARE" button in the Auto section. This automated process takes approximately 30 seconds, during which the camera captures 12 high-quality photographs from different angles, ensuring comprehensive coverage of the targeted area.

<img src="https://github.com/user-attachments/assets/4384ad20-a933-4e65-9f67-23547249fecb" alt="Description" width="320" height="440">
