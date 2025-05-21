//RECIEVER CODE


#include <esp_now.h>
#include <ESP32Servo.h>
#include <WiFi.h>

Servo lrservo;
Servo udservo;
// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

  Serial.print("Int: ");
  Serial.println(myData.b);

  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  lrservo.setPeriodHertz(50);    // standard 50 hz servo
   udservo.setPeriodHertz(50); 
  lrservo.attach(26, 500, 2400);
    udservo.attach(25, 500, 2400);
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
if(myData.b == 1)
{
  Serial.println("STOP");
lrservo.write(90);
udservo.write(90);
  }
  if(myData.b == 2)
{
  Serial.println("LEFT");
lrservo.write(180);
  }
  if(myData.b == 3)
{
  Serial.println("RIGHT");

lrservo.write(0);
  }
  if(myData.b == 4)
{
  Serial.println("UP");
udservo.write(180);
  }
  if(myData.b == 5)
{
  Serial.println("DOWN");
  udservo.write(0);
  }
  
}