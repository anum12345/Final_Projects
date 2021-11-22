#include<ESP8266WiFi.h>
string val;
WiFiServer server(80);
string i;
WiFiServer server(80);
#define RelayPin1 5 //room D1
#define RelayPin2 4  //kitchen D2
#define RelayPin3 14 //controller room D5
#define RelayPin4 12 //garden D6
#define Speed1 21
#define Speed2 19
#define Speed4 18
int buzzer = D3; //buzzer
int sensor = A0; //sensor
int led_green = D4; //no leakage indication
int led_red = D7; // leakage indication
// Define threshold value. You might need to change it.
int sensor_limit = 600;
char auth[] = "hsYG_5da4gdP9jZkL18O5RNcJSrBT-Ou";
char ssid[] = "Alexahome";
char pass[] = "loranthus";


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  val="";
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
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin3, LOW);
  digitalWrite(RelayPin4, LOW);
  // Debug console
  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);
  //Initially the fan will be in OFF state
  digitalWrite(Speed1, LOW);
  digitalWrite(Speed2, LOW);
  digitalWrite(Speed4, LOW);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  digitalWrite(led_green, LOW);
  digitalWrite(led_red, LOW);
  Blynk.begin(auth, ssid, pass);
}


 
  
  

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 1)
  {
    String val = Serial.readString();
    Serial.println(val);
    
    if(val == "room bulb on")
    {
      digitalWrite(5, HIGH);
    }
    if(val == "room bulb off")
    {
      digitalWrite(5, LOW);
    }
    if(val == "kitchen bulb on")
    {
      digitalWrite(4, HIGH);
    }
    if(val == "kitchen bulb off")
    {
      digitalWrite(4, LOW);
    }
    if(val == "controller room bulb on")
    {
      digitalWrite(14, HIGH);
    }
    if(val == "controller room bulb off")
    {
      digitalWrite(14, LOW);
    }
   
    if(val == "garden bulb on")
    {
      digitalWrite(12, HIGH);
    }
    if(val == "garden bulb off")
    {
      digitalWrite(12, LOW);
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


  }
 
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
}


