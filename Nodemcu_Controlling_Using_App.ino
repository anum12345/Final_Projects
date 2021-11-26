/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
pinMode(4, OUTPUT);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("my-net","");
  Serial.println("Connecting to wifi");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("....");

  }
  Serial.println("I am connected");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "on") {
      digitalWrite(4,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED is on");
      client.println("</html>");

      delay(1);

    }
    if (i == "off") {
      digitalWrite(4,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED is off");
      client.println("</html>");

      delay(1);

    }

}
