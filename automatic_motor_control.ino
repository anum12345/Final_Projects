float d;
void setup() {
 Serial.begin(9600);
 pinMode(7,INPUT);//echo pin of ultraSonic
 pinMode(6,OUTPUT);//trig pin of ultraSonic
 pinMode(10,OUTPUT);// relay
 pinMode(9,OUTPUT);// buzzer pin
}
int low=23;
int high=5;

void vol() //distance calculation...
{
 digitalWrite(6,HIGH);
 delayMicroseconds(8);
 digitalWrite(6,LOW);
 delayMicroseconds(2);
 d=pulseIn(7,HIGH);
 d=d/69;
}
 
void loop() {
  vol();
 while(1)
  {
   b:
   digitalWrite(10,HIGH);// Pump On...
   delay(2000);
   vol();
   if(d<high) //check high...
    {
     digitalWrite(9,HIGH);// buzzer on.....
     delay(1000);
     digitalWrite(9,LOW);
     goto a;
    }
  }
 while(1)
  {
   a:
   digitalWrite(10,LOW);// pump off...
   delay(100);
   vol();
   if(d>low) //check low
    {
     digitalWrite(9,HIGH);//Buzzer beeping......
     delay(1000);
     digitalWrite(9,LOW);
     delay(1000);
     digitalWrite(9,HIGH);
     delay(1000);
     digitalWrite(9,LOW);
     delay(1000);
     
     goto b;
    }
  }

}




 
