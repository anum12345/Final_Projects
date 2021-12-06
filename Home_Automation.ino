
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

String  val =""; // Command received from Android device

// Set Relay Pins
int relay1 = 14;
int relay2 = 15;
int relay3 = 3;
int Speed1 = 1;
int Speed2 = 0;
int Speed4 = 4;

void setup()
{
 
  Serial.begin(9600);
  WiFi.begin("Anum", "Jamil123");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
  
  pinMode(relay1, OUTPUT); 
  pinMode(relay2, OUTPUT);  
  pinMode(relay3, OUTPUT);  


  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,LOW);

 
  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);
  //Initially the fan will be in OFF state
  digitalWrite(Speed1, LOW);
  digitalWrite(Speed2, LOW);
  digitalWrite(Speed4, LOW);    

  server.begin();
}

void loop()
{
    client = server.available();
    if (!client) return; 
    val = checkClient ();

         if(val == "room bulb on")
    {
      digitalWrite(14, HIGH);
    }
    if(val == "room bulb off")
    {
      digitalWrite(14, LOW);
    }
    if(val == "kitchen bulb on")
    {
      digitalWrite(15, HIGH);
    }
    if(val == "kitchen bulb off")
    {
      digitalWrite(15, LOW);
    }
    if(val == "controller room bulb on")
    {
      digitalWrite(3, HIGH);
    }
    if(val == "controller room bulb off")
    {
      digitalWrite(3, LOW);
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
  
    sendBackEcho(val); // send command echo back to android device
    val = "";
}

/* connecting WiFi */


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




   
