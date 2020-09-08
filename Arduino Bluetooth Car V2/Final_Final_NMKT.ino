#include <CarMove.h>
#include <Servo.h>
#define Servo_PIN 9
#define Buzz 4
#define fLED 2
#define bLED 3
#define lLED 5
#define rLED 6
#define cLED 7

Servo MYservo;
CarMove myCar(10, 12, 11, 13);
char command = 'S';
char precommand;
int speedcar;
int angle = 90;
unsigned long timeLED = 0;
byte LEDstate = 0;

void led(int LED, byte LEDstate)
{
    if ((unsigned long)(millis() - timeLED) > 300)
    {
        if (digitalRead(LED) == LOW)
            digitalWrite(LED, HIGH);
        else
            digitalWrite(LED, LOW);
        timeLED = millis();
    }
}

void setup()
{
    MYservo.attach(Servo_PIN);
    Serial.begin(9600); //Set the band rate to your Bluetooth module.
    pinMode(Buzz, OUTPUT);
    pinMode(fLED, OUTPUT);
    pinMode(bLED, OUTPUT);
    pinMode(lLED, OUTPUT);
    pinMode(rLED, OUTPUT);
    pinMode(cLED, OUTPUT);
    digitalWrite(Buzz, HIGH);
    digitalWrite(fLED, HIGH);
    digitalWrite(bLED, HIGH);
    digitalWrite(lLED, HIGH);
    digitalWrite(rLED, HIGH);
    digitalWrite(cLED, HIGH);
    delay(200);
    digitalWrite(Buzz, LOW);
    digitalWrite(fLED, LOW);
    digitalWrite(bLED, LOW);
    digitalWrite(lLED, LOW);
    digitalWrite(rLED, LOW);
    digitalWrite(cLED, LOW);
}

void loop()
{
    if (Serial.available() > 0)
    {
        if (angle != 90)
        {
            angle = 90;
            MYservo.write(angle); //initialize servo position
        }
        if (command != 'R' && command != 'L' && command != 'I' && command != 'J' && command != 'G' && command != 'H')
        {
            if (LEDstate == 1)
            {
                digitalWrite(lLED, HIGH);
                digitalWrite(rLED, HIGH);
            }
            else
            {
                digitalWrite(lLED, LOW);
                digitalWrite(rLED, LOW);
            }
        }
        command = Serial.read();
        switch (command)
        {
        case '0':
            speedcar = 0;
            break;
        case '1':
            speedcar = 25;
            break;
        case '2':
            speedcar = 51;
            break;
        case '3':
            speedcar = 76;
            break;
        case '4':
            speedcar = 102;
            break;
        case '5':
            speedcar = 127;
            break;
        case '6':
            speedcar = 153;
            break;
        case '7':
            speedcar = 178;
            break;
        case '8':
            speedcar = 204;
            break;
        case '9':
            speedcar = 230;
            break;
        case 'q':
            speedcar = 255;
            break;
        }

        myCar.stopPWM(speedcar); //initialize with motors stoped
        //Serial.println(command);
        switch (command)
        {
        case 'F':
            myCar.goPWM(speedcar);
            break;

        case 'B':
            myCar.backPWM(speedcar);
            break;

        case 'R': //right
            led(rLED, LEDstate);
            for (angle = 90; angle <= 160; angle += 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'L': //left
            led(lLED, LEDstate);
            for (angle = 90; angle >= 20; angle -= 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'I': //go right
            myCar.goPWM(speedcar);
            led(rLED, LEDstate);
            for (angle = 90; angle <= 180; angle += 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'G': //go left
            myCar.goPWM(speedcar);
            led(lLED, LEDstate);
            for (angle = 90; angle >= 0; angle -= 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'J': //back right
            myCar.backPWM(speedcar);
            led(rLED, LEDstate);
            for (angle = 90; angle <= 180; angle += 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'H': // back left
            myCar.backPWM(speedcar);
            led(lLED, LEDstate);
            for (angle = 90; angle >= 0; angle -= 1)
            {
                MYservo.write(angle);
            }
            break;

        case 'S': //stop
            myCar.stopPWM(speedcar);
            if (angle != 90)
            {
                angle = 90;
                MYservo.write(angle); //initialize servo position
            }
            break;

        case 'V':
            digitalWrite(Buzz, HIGH);
            break;
        case 'v':
            digitalWrite(Buzz, LOW);
            break;

        case 'X':
            digitalWrite(cLED, HIGH);
            digitalWrite(lLED, HIGH);
            digitalWrite(rLED, HIGH);
            LEDstate = 1;
            break;
        case 'x':
            digitalWrite(cLED, LOW);
            digitalWrite(lLED, LOW);
            digitalWrite(rLED, LOW);
            LEDstate = 0;
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
