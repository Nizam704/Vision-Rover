# VisionRover: VR-Controlled Industrial Surveillance Robot 🚀

## Project Overview

**VisionRover** is a remotely operated, multi-terrain surveillance robot developed as a Final Year Design Project for the Mechatronic Engineering Department at **SZABIST University, Karachi Campus** (Spring 2024, Project/Thesis ID: BEME-23-05).

The project aims to enhance safety and operational efficiency in industrial settings by providing real-time visual data through an immersive **Virtual Reality (VR)** experience, thereby minimizing direct human exposure to potentially hazardous environments.

**Submitted By:**

- Umair Zafar Taj (ID: 2045129)  
- Syed Nizam Alam Nizami (ID: 2045126)  
- Riznia Ahmed Siddiqui (ID: 2045121)

**Project Supervisor:**  
Engr. Atif Saeed (Assistant Professor)

---

## 📂 Repository Structure

- `/thesis`: Complete project thesis document (`VisionRover_Thesis.pdf`)
- `/code`: Source code (Arduino sketches, ESP32/ESP32-CAM, VR web interface)
- `/video_demonstration`: Demonstration videos of VisionRover
- `/portfolio`: Summaries, images, and project highlights
- `/presentation`: Presentation slides and materials
- `/design`: Design files (SolidWorks 3D models, TinkerCad diagrams, flowcharts)

---

## 📄 Abstract

Industrial safety and operational efficiency are paramount. Traditional monitoring methods often involve significant time, labor, and risk to human personnel. VisionRover addresses these challenges by deploying an **ESP32-controlled rover** equipped with:

- **ESP32-CAM** for live video streaming  
- **DHT-22** sensor for temperature and humidity  
- A robust, lightweight chassis  

The operator views the live feed in VR, with camera control enabled through a joystick or an accelerometer-based head-tracking system in the VR headset.

This system facilitates detailed inspections, reduces human risk, and enhances situational awareness in industrial environments.

**Keywords:** ESP32, Virtual Reality, Remote-Control, Rover, Live Streaming, Surveillance, Accelerometer, DHT-22

---

## 🎯 Goals and Objectives

### Main Goals:
- Design and construct an RC multi-terrain rover with live video feed for VR viewing
- Reduce human intervention in hazardous industrial scenarios
- Extend surveillance into confined or hard-to-access areas

### Key Objectives:
- Develop a reliable remote-controlled rover
- Ensure high-quality video transmission
- Provide a seamless and immersive VR experience
- Support advanced industrial surveillance needs

---

## ✨ Features

- **Remote Operation**: ESP32-based remote controller
- **Live Video Streaming**: ESP32-CAM streams video to a web server
- **Immersive VR Experience**: Split-screen video display for VR headsets
- **Dual Camera Control**:
  - Joystick-based pan/tilt
  - MPU6050-based head-tracking
- **Environmental Monitoring**: Real-time temperature & humidity overlay
- **Multi-Terrain Navigation**: DC gear motors for varied surfaces
- **3D Printed Chassis**: Lightweight PLA design (SolidWorks)
- **Wireless Communication**: Wi-Fi (video/data), NRF24L01 (control)
- **Operational Range**:
  - Remote Control: ~8 meters
  - Video Streaming: ~5 meters (lag-free)

---

## 🛠️ Technologies Used

### Hardware Components:
- **Microcontrollers**: ESP32, ESP32-CAM
- **Sensors**: DHT-22, MPU6050
- **Motors & Drivers**: DC Gear Motors, SG90 Servos, L298N
- **Input/Display**: KY-023 Joysticks, VR Headset
- **Communication**: Wi-Fi, NRF24L01
- **Power**: Rechargeable cells, 5V adapter
- **Chassis**: 3D Printed PLA

### Software & Tools:
- **IDE**: Arduino IDE
- **Design**: SolidWorks, TinkerCad
- **Web**: HTML
- **Project Management**: Microsoft Office, draw.io, Canva

---

## ⚙️ System Architecture

### Process Flow:
1. **Initialization**: System powers on, links established
2. **Remote Control**: Joysticks control rover movement and camera
3. **Video & Data Transmission**: ESP32-CAM streams to web server
4. **VR Display**: VR headset shows split-screen video + sensor data
5. **Head Tracking**: Optional, with MPU6050 for intuitive camera control

### Block Diagram:
- **Remote Controller**: Sends movement and camera commands
- **Rover**: Actuates motors and hosts ESP32-CAM
- **ESP32-CAM**: Captures video, streams data
- **Operator Interface**: Displays video in VR headset

---

## 💡 Performance Evaluation

- **Motion Control**: Responsive and accurate
- **Head Tracking**: Intuitive and precise
- **Video Quality**: Good within 5m; minor lag beyond
- **ESP32-CAM**: Overheats after 2+ minutes (known issue)
- **Chassis**: Lightweight and durable
- **Sensor Integration**: Real-time data overlay worked successfully

---

## 🌍 Sustainable Development Goals (SDGs) Addressed

- **SDG 9: Industry, Innovation, and Infrastructure**  
  Promotes safer and more efficient industrial inspection solutions.

- **SDG 10: Reduced Inequalities**  
  Enhances accessibility to industrial monitoring roles.

*Refer to page ii of the thesis for the SDG coverage matrix.*

---

## 🔮 Future Work

- **Extended Range**: Use advanced camera modules or boosters
- **Advanced Sensors**: Add gas sensors, thermal cameras (e.g., AMG8833)
- **Chassis Material**: Test heat/chemical-resistant materials
- **Improved Mobility**: Add mecanum wheels for omnidirectional movement
- **Power Optimization**: Extend battery life, efficient power management
- **Heat Dissipation**: Address ESP32-CAM overheating with heat sinks or alternatives

---

## 📜 Thesis Document

Access the full thesis, including design, methodology, and results, in the `/thesis` folder:  
**`VisionRover_Thesis.pdf`**

---

## 💻 Code

Complete source code available in the `/code` folder.  
Refer to **Appendix A** in the thesis for partial code snippets.

---

> _This README was generated based on the "VisionRover" thesis document (BEME-23-05, Spring 2024, SZABIST University)._
