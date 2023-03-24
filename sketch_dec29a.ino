#include <printf.h>

int enA = 6;
int in1 = 2;
int in2 = 3;
int enB = 7;
int in3 = 4;
int in4 = 5;

const int trigUp = 8;
const int echoUp = 9;
const int trigPin = 11;
const int echoPin = 10;

int speed1 = 150, speed2 = 200;

void goFront(){
  analogWrite(enA, speed2);
  analogWrite(enB, speed2);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  //Serial.println("Front");
}

void goBack(){
  analogWrite(enA, speed1);
  analogWrite(enB, speed1);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  //Serial.print("Back");
}

void rotateLeft(){
  analogWrite(enA, 200);
  analogWrite(enB, 0);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  //Serial.print("Left");
}

void rotateRight(){
  analogWrite(enA, 0);
  analogWrite(enB, 200);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  //Serial.print("Left");
}

void Stop(){
  analogWrite(enA, LOW);
  analogWrite(enB, LOW);
}

int getDistance(int trigP, int echoP){
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigP, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoP, HIGH);
  // Calculating the distance
  int distance= duration*0.034/2;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigUp, OUTPUT);
  pinMode(echoUp, INPUT);

  Stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  int dist = getDistance(trigPin, echoPin);
  //int safeDist = getDistance(trigUp, echoUp);

  //goFront();
  //rotateLeft();
  
  if(dist < 35){
    goFront();
    //delay(20);
  }else if(dist < 200){
    rotateLeft();
    //delay(20);
  }else{
    Stop();
  }

  Serial.print("Distance: ");
  Serial.println(dist);
  //Serial.print(" Safe Distance ");
  //Serial.println(safeDist);
  delay(30);
}
