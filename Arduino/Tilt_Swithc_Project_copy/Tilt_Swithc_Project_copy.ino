int SENSOR_PIN = 2;
int LEDGreen = 13;
int LEDRed = 12;


void setup()
{

  pinMode(SENSOR_PIN, INPUT);

  pinMode(13, OUTPUT);

  pinMode(12, OUTPUT);
}

void loop()
{
   
  if (digitalRead(SENSOR_PIN) == HIGH)
  {
  
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
  }
  else
  {
  
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
   delay(500);
  }
}
