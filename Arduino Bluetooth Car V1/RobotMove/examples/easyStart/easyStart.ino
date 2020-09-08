#include <CarMove.h>



CarMove myCar(10,12,11,13);
void setup()
{
}
void loop()
{
  myCar.goPWM(255);
  delay(2000);
  myCar.backPWM(255);
  delay(2000);
}

