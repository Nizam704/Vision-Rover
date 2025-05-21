#include <esp_now.h>
#include <WiFi.h>

//#define rightJoyX     34
//#define rightJoyY     35

#define leftJoyX      34
#define leftJoyY      35

//#define SWRB 25



//int rightJoyXstate;
//int rightJoyYstate;
int leftJoyXstate;
int leftJoyYstate;
//int SWRBstate;

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t broadcastAddress[] = {0x24, 0xDC, 0xC3, 0x9C, 0x13, 0xE8};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  int leftJoyXvalue;
  int leftJoyYvalue;
  int rightJoyXvalue;
  int rightJoyYvalue;
 // int SWRBvalue;

} struct_message;

// Create a struct_message called myData
struct_message handControllerData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  if (status != ESP_NOW_SEND_SUCCESS) {
    Serial.println("Error details:");
    Serial.println(esp_err_to_name(status));
  }
}


void setup() {
  // Init Serial Monitor
  Serial.begin(115200);
  //pinMode(rightJoyX, INPUT);
  //pinMode(rightJoyY, INPUT);
  pinMode(leftJoyX, INPUT);
  pinMode(leftJoyY, INPUT);
  //pinMode(SWRB,INPUT_PULLUP);


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
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Set values to send
  
  leftJoyXstate = analogRead(leftJoyX);
  handControllerData.leftJoyXvalue = leftJoyXstate;
  leftJoyYstate = analogRead(leftJoyY);
  handControllerData.leftJoyYvalue = leftJoyYstate;
  //rightJoyXstate = analogRead(rightJoyX);
  //handControllerData.rightJoyXvalue = rightJoyXstate;
  //rightJoyYstate = analogRead(rightJoyY);
  //handControllerData.rightJoyYvalue = rightJoyYstate;
  //SWRBstate=digitalRead(SWRB);
  //handControllerData.SWRBvalue=SWRBstate;



  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &handControllerData, sizeof(handControllerData));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.print("Error sending the data. Error code: ");
    Serial.println(result);
  }
  delay(50);
}
