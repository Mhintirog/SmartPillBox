#include <Servo.h>

Servo myservo;  
#define servoPin 9 //~
#define pushButton1Pin 2 
#define pushButton2Pin 3

int angle =90;    // initial angle  for servo
int angleStep =5;
const int min = 0;
const int max = 180;

void setup() {
  
  Serial.begin(9600);          
  myservo.attach(servoPin);  
  pinMode(pushButton1Pin,INPUT_PULLUP);
  pinMode(pushButton2Pin,INPUT_PULLUP);
   
}

void loop() {
  while(digitalRead(pushButton1Pin) == LOW){
  
  angle = angle + angleStep;

    
    if (angle <= min || angle >= max) {
      angleStep = -angleStep;
    }
    myservo.write(angle); 
  delay(100); 
  }

  
}
