#ifndef CarMove_h
#define CarMove_h


#include "Arduino.h"
class CarMove
{
  public:
  CarMove(int A1, int D1, int A2, int D2);

  void goPWM(int speed);
  void backPWM(int speed);
  void rotate_leftPWM(int speed);
  void rotate_rightPWM(int speed);
  void go_leftPWM(int speed);
  void go_rightPWM(int speed);
  void back_leftPWM(int speed);
  void back_rightPWM(int speed);
  void stopPWM(int speed);
  private:
  int _A1;
  int _A2;
  int _D1;
  int _D2;

  int _speed;
};
#endif

