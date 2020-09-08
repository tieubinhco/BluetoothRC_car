/*Create By Huynh Duc Nham
   *Date: 18-7-2016
   *Thanks For Using
*/
//http://arduino.vn/bai-viet/1022-gioi-thieu-thu-vien-robotmove-thu-vien-dieu-khien-xe-robot-di-chuyen-su-dung-module
#ifndef RobotMove_h
#define RobotMove_h
#include "Arduino.h"
class RobotMove
{
  public:
  RobotMove(int in1, int in2, int in3, int in4, int enA, int enB);
  void dung();
  void tien();
  void lui();
  void xoayTrai();
  void xoayPhai();
  void reTrai();
  void rePhai();
  void luiTrai();
  void luiPhai();
  void tienPWM(int speed);
  void luiPWM(int speed);
  void xoayTraiPWM(int speed);
  void xoayPhaiPWM(int speed);
  void reTraiPWM(int speed);
  void rePhaiPWM(int speed);
  void luiTraiPWM(int speed);
  void luiPhaiPWM(int speed);
  private:
  int _in1;
  int _in2;
  int _in3;
  int _in4;
  int _enA;
  int _enB;
  int _speed;
};
#endif