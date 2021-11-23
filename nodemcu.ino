#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "hsYG_5da4gdP9jZkL18O5RNcJSrBT-Ou";
char ssid[] = "Alexahome";
char pass[] = "loranthus";
int buzzer = D2; //buzzer
int sensor = A0; //sensor
int led_green = D5; //no leakage indication
int led_red = D6; // leakage indication
// Define threshold value. You might need to change it.
int sensor_limit = 600;
void setup()
{ 
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
   int sensor_value = analogRead(sensor);
   Serial.print("Gas Level: ");
   Serial.println(sensor_value);
   Blynk.virtualWrite(V1, sensor_value);
  // Checks if it has reached the threshold value
  if (sensor_value > sensor_limit)
  {
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  Blynk.notify("Alert: Gas Leakage Detected");
  }
  else
  {
  digitalWrite(buzzer, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, HIGH);
  }
  delay(100);
  Blynk.run(); // Initiates Blynk
}
  


