int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

void setup()
{
pinMode(M1, OUTPUT);
pinMode(M2, OUTPUT);
}

void loop()

  { 
  int value=255;
 
   digitalWrite(M1,HIGH);
 digitalWrite(M2, HIGH);

    analogWrite(E1, value);
    analogWrite(E2, value);
     delay(30);
     delay(1000);

      
   digitalWrite(M1,LOW);
 digitalWrite(M2, LOW);

    analogWrite(E1, value);
    analogWrite(E2, value);
   delay(1000);
   
  
  }

