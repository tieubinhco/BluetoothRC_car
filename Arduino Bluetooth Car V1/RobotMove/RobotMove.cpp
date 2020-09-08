/*Create By Huynh Duc Nham
   *Date: 18-7-2016
   *Thanks For Using
*/
#include "Arduino.h"
#include "RobotMove.h"
RobotMove::RobotMove(int in1, int in2, int in3, int in4, int enA, int enB)
{
  if(enA!=0) pinMode(enA,OUTPUT);
  if(enB!=0) pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  _in1=in1;
  _in2=in2;
  _in3=in3;
  _in4=in4;
  _enA=enA;
  _enB=enB;
}
void RobotMove::dung()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,0);
}
void RobotMove::tien()
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,255);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::lui()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enA!=0)
    analogWrite(_enA,255);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::xoayTrai()
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enA!=0)
    analogWrite(_enA,255);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::xoayPhai()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,255);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::reTrai()
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,255);
}
void RobotMove::rePhai()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,0);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::luiTrai()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enB!=0)
    analogWrite(_enB,255);
}
void RobotMove::luiPhai()
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,0);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,255);
}
void RobotMove::tienPWM(int speed)
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,speed);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::luiPWM(int speed)
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enA!=0)
    analogWrite(_enA,speed);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::xoayTraiPWM(int speed)
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enA!=0)
    analogWrite(_enA,speed);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::xoayPhaiPWM(int speed)
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,speed);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::reTraiPWM(int speed)
{
    digitalWrite(_in1,1);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,speed);
}
void RobotMove::rePhaiPWM(int speed)
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,0);
    digitalWrite(_in3,1);
    digitalWrite(_in4,0);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::luiTraiPWM(int speed)
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,0);
    digitalWrite(_in3,0);
    digitalWrite(_in4,1);
    if(_enB!=0)
    analogWrite(_enB,speed);
}
void RobotMove::luiPhaiPWM(int speed)
{
    digitalWrite(_in1,0);
    digitalWrite(_in2,1);
    digitalWrite(_in3,0);
    digitalWrite(_in4,0);
    if(_enA!=0)
    analogWrite(_enA,speed);
}