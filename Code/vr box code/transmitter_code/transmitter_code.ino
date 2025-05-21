//SENDER CODE

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <esp_now.h>
#include <WiFi.h>

Adafruit_MPU6050 mpu;
int led = 26;
String condition = "";
int v = 0;
String newCondition = "";
int newV = 0;

// MAC address of the receiving ESP32
uint8_t broadcastAddress[] = {0x8C, 0xAA, 0xB5, 0x8B, 0xCD, 0x64};//8C:AA:B5:8B:CD:64



typedef struct struct_message {
  int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
pinMode(led,OUTPUT);
digitalWrite(led,LOW);
  Wire.begin();

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050");
    digitalWrite(led,LOW);
    while (1);
  }
digitalWrite(led,HIGH);
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

// Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  }


void loop() {
  sensors_event_t a, g, temp;

  mpu.getEvent(&a, &g, &temp);

  // Accelerometer values in m/s^2
  float accelX = a.acceleration.x;
  float accelY = a.acceleration.y;

  if (accelX >= -5 && accelX <= 5 && accelY >= -5 && accelY <= 5) {
    newCondition = "straight";
    newV = 1;
  } else if (accelX < -5 && accelX >= -10) {
    newCondition = "right";
    newV = 2;
  } else if (accelX > 5 && accelX <= 10) {
    newCondition = "left";
    newV = 3;
  } else if (accelY > 5 && accelY <= 10) {
    newCondition = "up";
    newV = 4;
  } else if (accelY < -5 && accelY >= -10) {
    newCondition = "down";
    newV = 5;
  }

  // Print only if the value changes
  if (newCondition != condition || newV != v) {
    condition = newCondition;
    v = newV;
    Serial.println(condition);
    Serial.println(v);
  myData.b = v;
    // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    //Serial.println("Sent with success");
  }
  else {
   // Serial.println("Error sending the data");
  }
  }

  delay(100);  // Adjust delay as needed
}