/*Create By Huynh Duc Nham
   *Date: 18-7-2016
   *Thanks For Using
*/
#include "Arduino.h"
#include "CarMove.h"
CarMove::CarMove(int A1, int D1, int A2, int D2)
{
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  _A1=A1;
  _A2=A2;
  _D1=D1;
  _D2=D2;

}

void CarMove::goPWM(int speed)
{
    digitalWrite(_D1,HIGH);
    digitalWrite(_D2,HIGH);


    analogWrite(_A1,speed);

    analogWrite(_A2,speed);
}
void CarMove::backPWM(int speed)
{
     digitalWrite(_D1,LOW);
    digitalWrite(_D2,LOW);


    analogWrite(_A1,speed);

    analogWrite(_A2,speed);
}
void CarMove::rotate_leftPWM(int speed)
{
    digitalWrite(_D1,LOW);
    digitalWrite(_D2,HIGH);


    analogWrite(_A1,speed);

    analogWrite(_A2,speed);
}
void CarMove::rotate_rightPWM(int speed)
{
   digitalWrite(_D1,HIGH);
    digitalWrite(_D2,LOW);


    analogWrite(_A1,speed);

    analogWrite(_A2,speed);
}
void CarMove::go_leftPWM(int speed)
{
    digitalWrite(_D1,HIGH);
    digitalWrite(_D2,HIGH);



    analogWrite(_A1,speed-100);
    analogWrite(_A2,speed);
}
void CarMove::go_rightPWM(int speed)
{
    digitalWrite(_D1,HIGH);
    digitalWrite(_D2,HIGH);



    analogWrite(_A1,speed);
    analogWrite(_A2,speed-100);
}
void CarMove::back_leftPWM(int speed)
{
    digitalWrite(_D1,LOW);
    digitalWrite(_D2,LOW);



    analogWrite(_A1,speed-100);
    analogWrite(_A2,speed);


}
void CarMove::back_rightPWM(int speed)
{

    digitalWrite(_D1,LOW);
    digitalWrite(_D2,LOW);



    analogWrite(_A1,speed);
    analogWrite(_A2,speed-100);
}
void CarMove::stopPWM(int speed)
{
    digitalWrite(_D1,HIGH);
    digitalWrite(_D2,HIGH);
    analogWrite(_A1,0*speed);
    analogWrite(_A2,0*speed);
}
