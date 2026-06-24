int led1 = 5;
int led2 = 6;
int LDR = 10;
int IR1 = 11;
int IR2 = 12;

void setup()
{
  Serial.begin(9600);
  delay(500);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(LDR, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() 
{
  int val1 = digitalRead(IR1); // If Any Object front of IR Sensor 1 then val1 = 0
  int val2 = digitalRead(IR2); // If Any Object front of IR Sensor 2 then val2 = 0
  int val3 = digitalRead(LDR); // At Night, LDR val3 = 0

  Serial.print("IR1= ");
  Serial.println(val1);
  Serial.print("IR2= ");
  Serial.println(val2);
  Serial.print("LDR= ");
  Serial.println(val3);

  if (val3 == 1)  // Morning: LED OFF
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  else  // Night: LED logic based on IR
  {
    analogWrite(5, 10);
    analogWrite(6, 10);

    if (val1 == 0 && val2 == 1)
    {
      analogWrite(5, 255);  // changed from 500 → max PWM is 255
      analogWrite(6, 20);
    }
    else if (val1 == 1 && val2 == 0)
    {
      analogWrite(5, 20);
      analogWrite(6, 255);
    }
    else if (val1 == 0 && val2 == 0)
    {
      analogWrite(5, 20);
      analogWrite(6, 20);
    }
    else
    {
      analogWrite(5, 255);
      analogWrite(6, 255);
    }
  }

delay(500);
}