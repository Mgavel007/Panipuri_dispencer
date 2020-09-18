const int trigPin1 =3; //trig pin to arduino pin 3


const int echoPin1 =2; //echo pin to arduino pin 2

long duration1;

int distance1;



void setup() {

pinMode (A3,OUTPUT);

pinMode (trigPin1,OUTPUT);

pinMode (echoPin1,INPUT);


Serial.begin(9600);

}

void loop() {

digitalWrite(trigPin1,LOW);

delayMicroseconds (2);

digitalWrite(trigPin1,HIGH);

delayMicroseconds (10);

digitalWrite(trigPin1,LOW);

duration1 = pulseIn(echoPin1,HIGH);

digitalWrite(trigPin1,HIGH);

distance1 = duration1*0.034/2;

Serial.print("Distance1: ");

Serial.println(distance1);


if (distance1 <=20) //set distance in centimeter 

{

digitalWrite(A3,HIGH);

delay(1000);  // set time for pani filling 

digitalWrite(A3,LOW);

delay(2000); // set time to remove hand after filling pani

}

else

{

digitalWrite(A3,LOW);

delay(50);

}

}
