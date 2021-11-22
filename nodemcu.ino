#define RelayPin1 3 //room
#define RelayPin2 4  //kitchen
#define RelayPin3 5 //controller room
#define RelayPin4 6 //garden
#define Speed1 21
#define Speed2 19
#define Speed4 18
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  // Debug console
  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);
  //Initially the fan will be in OFF state
  digitalWrite(Speed1, LOW);
  digitalWrite(Speed2, LOW);
  digitalWrite(Speed4, LOW);
  
}
BLYNK_WRITE(V0)
{
 
  
  

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 1)
  {
    String val = Serial.readString();
    Serial.println(val);
    
    if(val == "room bulb on")
    {
      digitalWrite(3, HIGH);
    }
    if(val == "room bulb off")
    {
      digitalWrite(3, LOW);
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
      digitalWrite(5, HIGH);
    }
    if(val == "controller room bulb off")
    {
      digitalWrite(5, LOW);
    }
   
    if(val == "garden bulb on")
    {
      digitalWrite(6, HIGH);
    }
    if(val == "garden bulb off")
    {
      digitalWrite(6, LOW);
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
}

