#define RelayPin1 2 //room 
#define RelayPin2 3  //kitchen 
// #define RelayPin3 4 //controller room 
#define Speed1 5
// #define Speed2 6
// #define Speed4 7


void setup()
{
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
//   pinMode(RelayPin3, OUTPUT);
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
//   digitalWrite(RelayPin3, HIGH);
  // Debug console
  pinMode(Speed1, OUTPUT);
//   pinMode(Speed2, OUTPUT);
//   pinMode(Speed4, OUTPUT);
  //Initially the fan will be in OFF state
  digitalWrite(Speed1, HIGH);
//   digitalWrite(Speed2, HIGH);
//   digitalWrite(Speed4, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == 1)
  {
    String val = Serial.readString();
    Serial.println(val);
    
    if(val == "room bulb on")
    {
      digitalWrite(2, LOW);
    }
    if(val == "room bulb off")
    {
      digitalWrite(2, HIGH);
    }
    if(val == "kitchen bulb on")
    {
      digitalWrite(3, LOW);
    }
    if(val == "kitchen bulb off")
    {
      digitalWrite(3, HIGH);
    }
//     if(val == "controller room bulb on")
//     {
//       digitalWrite(4, LOW);
//     }
//     if(val == "controller room bulb off")
//     {
//       digitalWrite(4, HIGH);
//     }
   if(val="all bulb on")
   {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }
       if(val="all bulb off")
   {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    }
    
    if (val== "fan off")
  {
    //All realys Off - Fan Off
    
    digitalWrite(Speed1, HIGH);
//     digitalWrite(Speed2, LOW);
//     digitalWrite(Speed4, LOW);
   }
     if (val== "fan on")
  {
    //All realys Off - Fan Off
    
    digitalWrite(Speed1, LOW);
//     digitalWrite(Speed2, LOW);
//     digitalWrite(Speed4, LOW);
    }

//   if (val == "fan speed one ")
//   {
//     //Speed1 Relay On - Fan at speed 1
    
//     digitalWrite(Speed1, HIGH);
//     digitalWrite(Speed2, HIGH);
//     digitalWrite(Speed4, HIGH);
//     delay(500);
//     digitalWrite(Speed1, LOW);
//   }

//   if (val="fan speed two ")
//   {
//     //Speed2 Relay On - Fan at speed 2
    
//     digitalWrite(Speed1, HIGH);
//     digitalWrite(Speed2, HIGH);
//     digitalWrite(Speed4, HIGH);
//     delay(500);
//     digitalWrite(Speed2, LOW);
//   }

//   if (val="fan speed three")
//   {
//     //Speed1 & Speed2 Relays On - Fan at speed 3
    
//     digitalWrite(Speed1, HIGH);
//     digitalWrite(Speed2, HIGH);
//     digitalWrite(Speed4, HIGH);
//     delay(500);
//     digitalWrite(Speed1, LOW);
//     digitalWrite(Speed2, LOW);
//   }

//   if (val="fan speed four")
//   {
//     //Speed4 Relay On - Fan at speed 4
    
//     digitalWrite(Speed1, HIGH);
//     digitalWrite(Speed2, HIGH);
//     digitalWrite(Speed4, HIGH);
//     delay(500);
//     digitalWrite(Speed4, LOW);
//   }
  
}
}


