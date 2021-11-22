
#include<ESP8266WiFi.h>
string i;
WiFiServer server(80);
void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  WiFi.disconnect();
  delay(300);
  WiFi.begin("moazam","moazam123");
  Serial.println("Connected to Wifi");
  while(WiFi.status() != WL_CONNECTED)
    {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
  server.begin();


}
