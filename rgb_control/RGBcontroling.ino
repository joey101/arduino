int Red = 9;
int Blue = 10;
int Green = 11;

int redPot = 0;
int bluePot = 1;
int greenPot = 2;

void setup() {
pinMode(Red,OUTPUT);
pinMode(Green,OUTPUT);
pinMode(Blue,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  int potRed = analogRead(redPot);
  int potBlue = analogRead(bluePot);
  int potGreen = analogRead(greenPot);

  int val = analogRead(0);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(9,val);

  int val1 = analogRead(1);
  val1 = map(val1, 0, 1023, 0, 255);
  analogWrite(10, val1);

  int val2 = analogRead(2);
  val2 = map(val2, 0, 1023, 0, 255);
  analogWrite(11, val2);

Serial.print("Red:");
Serial.print(val);
Serial.print("Green:");
Serial.print(val1);
Serial.print("Blue:");
Serial.println(val2);
  
colorRGB(val,val1,val2);
}

void colorRGB(int Red, int Blue, int Green){
  analogWrite(Red,constrain(Red,0,255));
  analogWrite(Green,constrain(Green,0,255));
  analogWrite(Blue,constrain(Blue,0,255));
}

