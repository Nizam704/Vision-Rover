#include <esp_now.h>
#include <WiFi.h>
// #include <ESP32Servo.h>

// Servo myServoSWR;
// Servo myServoSW;



// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int leftJoyXvalue;
  int leftJoyYvalue;
  //int rightJoyXvalue;
 // int rightJoyYvalue;
  //int SWRBvalue;

} struct_message;

int m1;
int m2;
//int s1;
//int s2;
//int SWRvalue;

// Variables to keep track of the servos' rotational direction and speed
//int servoXDirection = 0; // 0 for CCW, 1 for CW
//int servoYDirection = 0; // 0 for CCW, 1 for CW
//int servoSpeed = 10; // Adjust speed as needed, lower values make it slower

// Create a struct_message called myData
struct_message readingData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&readingData, incomingData, sizeof(readingData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  
m1 = readingData.leftJoyYvalue;
Serial.print("Right Joystick Y Value: ");
Serial.println(readingData.leftJoyYvalue);
Serial.println();
m2 = readingData.leftJoyXvalue;
Serial.print("Right Joystick X Value: ");
Serial.println(readingData.leftJoyXvalue);
Serial.println();
// s1 = readingData.leftJoyYvalue;
// Serial.print("Left Joystick Y Value: ");
// Serial.println(readingData.leftJoyYvalue);
// Serial.println();
// s2 = readingData.leftJoyXvalue;
// Serial.print("Left Joystick X Value: ");
// Serial.println(readingData.leftJoyXvalue);
// Serial.println();
// SWRvalue= readingData.SWRBvalue;  
// Serial.print("Button condition : ");
// Serial.println(SWRvalue);
// Serial.println(); 
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  // myServoSWR.attach(2);
  // myServoSW.attach(4);
  // myServoSWR.write(0);
  // myServoSW.write(90);


  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

  // if(SWRvalue==HIGH)
  // {
  //   myServoSW.write(90);
  //   myServoSWR.write(0);
  // }
  // else
  // {

  // }

if (m1 < 100)
{
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(27, LOW);
}
else if (m1 > 3500)
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(27, HIGH);
  digitalWrite(14, LOW);
}

else if (m2 < 100)
{
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(27, HIGH);
  digitalWrite(14, LOW);
}

else if (m2> 3500)
{
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(14, HIGH);
}

else
{
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(27, LOW);
  digitalWrite(14, LOW);
}
  
  //   // Rotate servoX based on joystick X position
  // if (s1 < 150) {
  //   // Joystick X at minimum, gradually rotate CCW
  //   if (myServoSWR.read() > 0) {
  //     myServoSWR.write(myServoSWR.read() - servoSpeed);
  //     delay(50);
  //     return;

  //   }
  //   servoXDirection = 0; // Set direction to CCW
  //   return;
  // }
  //  else if (s1 > 3500) {
  //   // Joystick X at maximum, gradually rotate CW
  //   if (myServoSWR.read() < 180) {
  //     myServoSWR.write(myServoSWR.read() + servoSpeed);
  //     delay(50);
  //     return;

  //   }
  //   servoXDirection = 1; // Set direction to CW
  //   return;
  // } else {
  //   // Joystick X at any other position, stop servoX
  //   servoXDirection = -1; // Set direction to stop
  // }

  // // Rotate servoY based on joystick Y position
  // if (s2 < 150) {
  //   // Joystick Y at minimum, gradually rotate CCW
  //   if (myServoSW.read() > 0) {
  //     myServoSW.write(myServoSW.read() - servoSpeed);
  //     delay(50);
  //     return;
  //   }
  //   servoYDirection = 0; // Set direction to CCW
  //   return;
  // } else if (s2 > 3500) {
  //   // Joystick Y at maximum, gradually rotate CW
  //   if (myServoSW.read() < 180) {
  //     myServoSW.write(myServoSW.read() + servoSpeed);
  //     delay(50);
  //     return;
  //   }
  //   servoYDirection = 1; // Set direction to CW
  //   return;
  // } else {
  //   // Joystick Y at any other position, stop servoY
  //   servoYDirection = -1; // Set direction to stop
  //   return;
  // }

}
