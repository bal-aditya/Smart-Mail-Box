#include <Servo.h>
#define trigPin 12
#define echoPin 13
int IRSensor = 7;
int sound=100;
int distance;
int buzzer =11;
Servo servo_test;
Servo servo_test1;
int angle = 180;

void setup() 
{
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer, OUTPUT);
 servo_test.attach(9);
 servo_test1.attach(8);  
 pinMode(IRSensor, INPUT);
}
void loop()
{
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration*0.034)/2;
 Serial.print(distance);
 irs();
 if (distance <10){
  tone(buzzer, sound);
  //lcd
 }
 if (distance >30)
 {
  //tone(buzzer, sound);
  Serial.print(distance);
  Serial.println(" cm");
  //lcd display
//  if (distance >30)
 // {
  // serv();
  //}
 }
//else
//{
 // noTone(buzzer);
//}
 delay(500);
}
void serv()
{
 for(angle = 0; angle < 90; angle += 1)  
  {                                  
    servo_test.write(angle);   
    servo_test1.write(angle);  
    delay(15);                       
  } 
 delay(1000);
 for(angle = 90; angle>=1; angle-=15) 
  {                                
    servo_test.write(angle);  
    servo_test1.write(angle);    
    delay(5);                       
  } 

}
void irs()
{
  int sensorStatus = digitalRead(IRSensor);
  if (sensorStatus == 1)
  {
   noTone(buzzer);
  }
  else
  {
   tone(buzzer, sound);
  }
}
