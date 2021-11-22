#define RelayPin1 3 //room
#define RelayPin2 4  //kitchen
#define RelayPin3 5 //controller room
#define RelayPin4 6 //garden
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 1)
  {
    String val = Serial.readString();
    Serial.println(val);
    if(val == "fan on")
    {
      digitalWrite(fan, HIGH);
    }
    if(val == "fan off")
    {
      digitalWrite(fan, LOW);
    }
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

  }
}

