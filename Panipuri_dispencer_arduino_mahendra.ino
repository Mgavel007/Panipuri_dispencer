#include <Servo.h> //including the library required for using servo
Servo servo1;
const int trigPin1 =3; //giving trig pin no.3 in arduino


const int echoPin1 =2; //giving echo pin no. 2
long duration1;        // declareing variables name duration1 
int distance1;         // variable distance1




void setup() {
servo1.attach(A3);         //Attaching servo to pin no. A3 of Arduino
pinMode (trigPin1,OUTPUT);
pinMode (echoPin1,INPUT);


Serial.begin(9600);
}
void loop() {
servo1.write(1);
digitalWrite(trigPin1,LOW);
delayMicroseconds (2);
digitalWrite(trigPin1,HIGH);
delayMicroseconds (10);
digitalWrite(trigPin1,LOW);
duration1 = pulseIn(echoPin1,HIGH);
digitalWrite(trigPin1,HIGH);
distance1 = duration1*0.034/2;  // measuring distance using math formula
Serial.print("Distance1: ");
Serial.println(distance1);


if (distance1 <=20)    // set the distance as you like in Centimetres (example-20)
{
servo1.write(90);
delay(1000);   //set the time of operation for servo in milliseconds (1000ms=1second)
servo1.write(0);
delay(2000);   //Set the interval time after operation of servo
}
else
{
servo1.write(1);
delay(50);
}
}
