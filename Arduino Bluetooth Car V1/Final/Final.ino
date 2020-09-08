#include <CarMove.h>



CarMove myCar(10,12,11,13);
/*void setup()
{
}
void loop()
{
  myCar.goPWM(255);
  delay(2000);
  myCar.backPWM(255);
  delay(2000);
}*/


char command='S'; 
char precommand;
int speedcar;
void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0)
  { 
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
    case 'L':  
      myCar.rotate_leftPWM(speedcar);
      break;
    case 'R':
      myCar.rotate_rightPWM(speedcar);
      break;
    case 'G':
      myCar.go_leftPWM(speedcar);
      break;
    case 'I':
      myCar.go_rightPWM(speedcar);
      break;
    case 'H':
      myCar.back_leftPWM(speedcar);
      break;
    case 'J':
      myCar.back_rightPWM(speedcar);
      break;
    case 'S':
      myCar.stopPWM(speedcar);
      break;
    }
  } 
}


