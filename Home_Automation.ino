/*************************************************************************************
*   Home Automation with Android App and NodeMCU
*
*  Smart Devices
*   ==> Relay1
*   ==> Relay2
*   ==> Relay3
*   ==> Relay4
*   
*  Groups of devices
*   ==> All Devices ON/OFF
*   
*  Voice activation and response
*
*   Developed by Marcelo Rovai on 27March17
*   Visit my blog: https://MJRoBot.org 
*   
*   WARNING: When uploading a code ==> Power-off Relays
************************************************************************************/
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
const char* ssid = "YOUR SSID";
const char* password = "YOUR PASSWORD";
String  val =""; // Command received from Android device

// Set Relay Pins
int relay1 = 14;
int relay2 = 15;
int relay3 = 3;
int relay4 = 1;

void setup()
{
  Serial.begin(115200);

  pinMode(relay1, OUTPUT); 
  pinMode(relay2, OUTPUT);  
  pinMode(relay3, OUTPUT);  
  pinMode(relay4, OUTPUT);  

  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);
      
  connectWiFi();
  server.begin();
}

void loop()
{
    client = server.available();
    if (!client) return; 
    val = checkClient ();

         if(val == "room bulb on")
    {
      digitalWrite(2, HIGH);
    }
    if(val == "room bulb off")
    {
      digitalWrite(2, LOW);
    }
    if(val == "kitchen bulb on")
    {
      digitalWrite(3, HIGH);
    }
    if(val == "kitchen bulb off")
    {
      digitalWrite(3, LOW);
    }
    if(val == "controller room bulb on")
    {
      digitalWrite(4, HIGH);
    }
    if(val == "controller room bulb off")
    {
      digitalWrite(4, LOW);
    }
   
    
    if (val== "fan off")
  {
    //All realys Off - Fan Off
    
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
  }

  if (val=="fan on at low speed")
  {
    //Speed1 Relay On - Fan at speed 1
    
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
    delay(500);
    digitalWrite(Speed1, HIGH);
  }

  if (val == "fan on at medium speed")
  {
    //Speed2 Relay On - Fan at speed 2
    
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
    delay(500);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
  }

  if (val == "fan on at high speed")
  {
    //Speed1 & Speed2 Relays On - Fan at speed 3
    
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
    delay(500);
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, HIGH);
    
  } 
  
    sendBackEcho(command); // send command echo back to android device
    command = "";
}

/* connecting WiFi */
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}

/* check command received from Android Device */
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

/* send command echo back to android device */
void sendBackEcho(String echo)
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(echo);
  client.println("</html>");
  client.stop();
  delay(1);
}
