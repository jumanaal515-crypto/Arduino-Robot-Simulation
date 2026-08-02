#include <Servo.h>


const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;


const int signalPin = 7;


Servo myServo;
const int servoPin = 11;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(90); 
}

void loop() {
 
  checkObstacle();

 
  for (int i = 0; i < 300; i++) {
    if (checkObstacle()) break;
    moveForward();
    delay(100);
  }

  
  for (int i = 0; i < 600; i++) {
    if (checkObstacle()) break;
    moveBackward();
    delay(100);
  }


  for (int i = 0; i < 10; i++) {
  
    for (int j = 0; j < 30; j++) {
      if (checkObstacle()) break;
      turnRight();
      delay(100);
    }
  
    for (int j = 0; j < 30; j++) {
      if (checkObstacle()) break;
      turnLeft();
      delay(100);
    }
  }

  stopMotors();
  delay(1000);
}


bool checkObstacle() {
  long distance = getDistance();


  if (distance <= 10 && distance > 0) {
    stopMotors();
    delay(300);

   
    myServo.write(180);
    delay(500);

 
    moveBackward();
    delay(1000);
    turnRight();
    delay(800);

  
    myServo.write(90);
    delay(300);
    return true;
  }
  return false;
}


long getDistance() {
  
  pinMode(signalPin, OUTPUT);
  digitalWrite(signalPin, LOW);
  delayMicroseconds(2);
  digitalWrite(signalPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(signalPin, LOW);

  
  pinMode(signalPin, INPUT);
  long duration = pulseIn(signalPin, HIGH);
  
 
  long distance = duration / 29 / 2;
  return distance;
}


void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}