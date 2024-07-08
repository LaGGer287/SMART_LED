#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP32.h>
#include <Arduino.h>
#include <string.h>
//Khai báo các tham số truy cập tới firebase
#define FIREBASE_HOST "https://denthongminh-fff3e-default-rtdb.asia-southeast1.firebasedatabase.app/"

#define FIREBASE_AUTH "2gqvGHWu4uEbmPQr46Mlg4LyCdOZUVP5omHNndhF"
//Khai báo các tham số truy cập mạng Wifi
const char* ssid = "Chien";
const char* password = "12345678";
//Khai báo các biến
FirebaseData firebaseData;
String fireStatus = "";
#define LED 27
String path = "ESP32/Outputs/Digital/"; 
void setup()
{
  Serial.begin(115200);   
  delay(1000);
    pinMode(LED, OUTPUT);
      digitalWrite(LED, HIGH);//tắt led
      Serial.begin(115200);
  
  // Kết nối với Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("Success");

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.setString(firebaseData, path+"LED","OFF");
}

void loop(){
  Firebase.getString(firebaseData, path+"LED");
  fireStatus = firebaseData.stringData();
  if(fireStatus == "ON")
  {
    Serial.println("LED is turn ON");
    digitalWrite(LED, HIGH);
  }
  else if(fireStatus == "OFF")
  {
    Serial.println("LED is turn OFF");
    digitalWrite(LED, LOW);
  }
  else{
    Serial.println("Lệnh hợp lệ! Hãy nhập lại ON hoặc OFF");
  }
}