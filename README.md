VisionRover: VR-Controlled Industrial Surveillance Robot
🚀 Project Overview
VisionRover is a remotely operated, multi-terrain surveillance robot developed as a Final Year Design Project for the Mechatronic Engineering Department at SZABIST University, Karachi Campus (Spring 2024, Project/Thesis ID: BEME-23-05). The project aims to enhance safety and operational efficiency in industrial settings by providing real-time visual data through an immersive Virtual Reality (VR) experience, thereby minimizing direct human exposure to potentially hazardous environments.

Submitted By:

Umair Zafar Taj (ID 2045129)

Syed Nizam Alam Nizami (ID 2045126)

Riznia Ahmed Siddiqui (ID 2045121)

Project Supervisor:

Engr. Atif Saeed (Assistant Professor)

📂 Repository Structure
This repository is organized into the following folders:

/thesis: Contains the complete project thesis document (VisionRover_Thesis.pdf).

/code: Includes all the source code for the project, likely including Arduino sketches for the ESP32 and ESP32-CAM, and any HTML/CSS/JS for the VR web interface.

/video_demonstration: Features video clips showcasing the VisionRover in action, demonstrating its functionalities.

/portfolio: May contain materials suitable for a project portfolio, such as summaries, images, or specific highlights.

/presentation: Includes slideshows or materials used for project presentations.

/design: Contains design files, which might include 3D models (e.g., SolidWorks files for the chassis and remote), circuit diagrams (e.g., TinkerCad files), and flowcharts.

📄 Abstract
Industrial safety and operational efficiency are paramount. Traditional monitoring methods often involve significant time, labor, and potential risks to human personnel. VisionRover addresses these challenges by deploying an ESP-32 controlled rover equipped with an ESP-32 camera module for live video streaming, a DHT-22 sensor for ambient temperature and humidity monitoring, and a robust chassis. The operator views the live feed in VR, with camera movements controllable via the remote or an accelerometer in the VR headset that mimics the user's head movements. This system facilitates detailed inspections, reduces human risk, improves response times, and enhances overall situational awareness in industrial environments.

Keywords: ESP-32, Virtual Reality, Remote-control, Rover, Live streaming, Surveillance, Accelerometer, DHT-22

🎯 Goals and Objectives
Main Goals:
Design and construct an RC multi-terrain rover with live video feed capabilities for VR viewing.

Reduce human intervention in hazardous industrial scenarios.

Extend surveillance reach into confined or difficult-to-access areas.

Key Objectives:
Develop a reliable and effective remote-controlled rover for long-range traversal.

Ensure high-quality video transmission.

Provide a seamless and immersive VR experience for the operator.

Meet the demands for advanced industrial surveillance.

✨ Features
Remote Operation: Controlled via a custom-built ESP32-based remote controller.

Live Video Streaming: ESP32-CAM module streams video to a web server.

Immersive VR Experience: Live feed is displayed in a split-screen format suitable for VR headsets.

Dual Camera Control:

Joystick-based pan-tilt control from the remote.

Accelerometer (MPU6050 in VR headset) based head-tracking for intuitive camera movement.

Environmental Monitoring: DHT-22 sensor provides real-time temperature and humidity data displayed on the video feed.

Multi-Terrain Navigation: Designed with DC metal gear motors for traversing various surfaces.

3D Printed Chassis: Lightweight and durable chassis designed in SolidWorks and printed using PLA.

Wireless Communication: Utilizes Wi-Fi for video/data transmission and NRF24L01 modules for remote control commands.

Operational Range:

Remote Control: ~8 meters

Lag-free Video Streaming: ~5 meters

🛠️ Technologies Used
Hardware Components:
Microcontrollers: ESP32 (for rover & remote), ESP32-CAM

Sensors: DHT-22 (Temperature & Humidity), MPU6050 (6 DoF IMU for head tracking)

Motors & Drivers: DC Metal Gear Motors, SG90 Micro Servos, L298N Motor Driver

Input/Display: KY-023 Joystick Modules, VR Headset

Communication: Integrated Wi-Fi (ESP32/ESP32-CAM), NRF24L01 Transceiver Modules

Power: Rechargeable cells, cell holders, 5V adapter

Chassis: 3D Printed PLA (Polylactic Acid)

Software & Tools:
IDE: Arduino IDE

Design: SolidWorks (3D Modeling), TinkerCad (Circuit Diagrams)

Web Technologies: HTML (for VR video page layout)

Project Management: Microsoft Office, draw.io, Canva

⚙️ System Architecture
Process Flow:
Initialization: System powers on, establishing communication links.

Remote Control: Operator uses joysticks on the remote to control rover movement and camera pan/tilt.

Video & Data Transmission: ESP32-CAM streams video and DHT-22 sensor data over Wi-Fi to a web server.

VR Display: The web page formats the video for VR headset viewing, overlaying sensor data.

Head Tracking (Optional Camera Control): MPU6050 in the VR headset tracks user's head movements, translating them into camera pan/tilt commands.

Block Diagram Overview:
Remote Controller: Sends commands for rover motion and camera motion.

Rover: Receives commands, actuates motors, and hosts the ESP32-CAM.

ESP32-CAM: Captures video, reads sensor data, and streams to the operator's device.

Operator Interface: VR headset displays the processed video feed.

💡 Performance Evaluation
The rover's motion control via the remote was successful and responsive.

Accelerometer-based head tracking for camera control provided an intuitive and accurate experience.

Video streaming quality was good within the optimal range (~5m), with some lag observed beyond this distance. The ESP32-CAM module exhibited overheating after prolonged use (>2 minutes), a known characteristic of the module.

The 3D printed chassis proved to be a robust and lightweight solution.

Real-time transmission of environmental data (temperature, humidity) was successfully integrated into the VR display.

🌍 Sustainable Development Goals (SDGs) Addressed
SDG 9: Industry, Innovation, and Infrastructure: By creating an innovative solution for industrial inspection and promoting safer infrastructure.

SDG 10: Reduced Inequalities: By designing a system that can be operated by a wider range of individuals, potentially opening up roles in a traditionally male-dominated field.

(Refer to page ii of the thesis for a detailed SDG coverage matrix.)

🔮 Future Work
Extended Range: Investigate alternative camera modules or signal boosting techniques to increase video streaming and control range.

Advanced Sensors: Integrate additional sensors (e.g., gas sensors, thermal cameras like the AMG8833 mentioned in costing) for more comprehensive environmental analysis.

Chassis Material: Experiment with different materials for the chassis to suit specific industrial environments (e.g., heat-resistant or chemical-resistant materials).

Improved Mobility: Implement mecanum wheels for omnidirectional movement in constrained spaces.

Power Optimization: Enhance battery life and power management systems.

Heat Dissipation: Address the ESP32-CAM overheating, possibly with a heat sink or a different module.

📜 Thesis Document
For a comprehensive understanding of the project, including detailed design, methodology, results, and analysis, please refer to the full thesis document located in the /thesis folder: VisionRover_Thesis.pdf.

💻 Code
Source code for the project can be found in the /code folder. Partial code snippets are also provided in Appendix A of the thesis document.
