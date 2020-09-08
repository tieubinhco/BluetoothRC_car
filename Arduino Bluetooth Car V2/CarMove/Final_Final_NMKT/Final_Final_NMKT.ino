#include <CarMove.h>
//#include <AFMotor.h>
#include<Servo.h>

#define Servo_PIN 9
#define Buzz 4
#define fLED 2
#define bLED 3
#define sLED 5

Servo MYservo;
CarMove myCar(10,12,11,13);
//int servo_position = 0;
char command='S'; 
char precommand;
int speedcar;
int angle=90;

void setup()
{
  MYservo.attach (Servo_PIN);
   Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  pinMode(Buzz, OUTPUT);
  pinMode(fLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(sLED, OUTPUT);
}

void loop(){
  if(Serial.available() > 0)
  { 
    
    if(angle != 90) 
    {
      angle=90;
      MYservo.write(angle); //initialize servo position 
    }
    command = Serial.read();
    switch(command)
    {
      case '0': speedcar=0; break; 
      case '1': speedcar=25; break; 
      case '2': speedcar=51; break; 
      case '3': speedcar=76; break; 
      case '4': speedcar=102; break; 
      case '5': speedcar=127; break; 
      case '6': speedcar=153; break; 
      case '7': speedcar=178; break; 
      case '8': speedcar=204; break; 
      case '9': speedcar=230; break;
      case 'q': speedcar=255; break;  
      
    }
  myCar.stopPWM(speedcar); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command)
    {
    case 'F':  
      myCar.goPWM(speedcar);
      break;
      
    case 'B':  
      myCar.backPWM(speedcar);
      break;
      
    case 'R'://right
      //myCar.rotate_leftPWM(speedcar);
      for (angle=90; angle<=180; angle +=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'L'://left
      for (angle=90; angle>=0; angle -=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'I'://go right
      myCar.goPWM(speedcar);
      for (angle=90; angle<=180; angle +=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'G': //go left
      myCar.goPWM(speedcar);
      for (angle=90; angle>=0; angle -=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'J'://back right
      myCar.backPWM(speedcar);
      for (angle=90; angle<=180; angle +=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'H':// back left 
      myCar.backPWM(speedcar);
      for (angle=90; angle>=0; angle -=1)
      {
      MYservo.write(angle);
      }
      break;
      
    case 'S'://stop
      myCar.stopPWM(speedcar);
      break;
      
    case 'V':
      digitalWrite(Buzz, HIGH);
      break;
    case 'v':
      digitalWrite(Buzz, LOW);
      break;

    case 'X':
      digitalWrite(sLED, HIGH);
      break;
    case 'x':
      digitalWrite(sLED, LOW);
      break;

    case 'W':
      digitalWrite(fLED, HIGH);
      break;
    case 'w':
      digitalWrite(fLED, LOW);
      break;
      
    case 'U':
      digitalWrite(bLED, HIGH);
      break;
    case 'u':
      digitalWrite(bLED, LOW);
      break;
    }
 
  } 
   
}
