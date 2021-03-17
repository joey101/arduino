int redPin = 9; // R – digital 9
int greenPin = 10; // G – digital 10
int bluePin = 11; // B – digital 11

int potRedPin = 0; // potentiometer 1 – analog 0
int potGreenPin = 1; // potentiometer 2 – analog 1
int potBluePin = 2; // potentiometer 3 – analog 2

void setup(){
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
Serial.begin(9600); // Initialize the serial port
}

void loop(){
int potRed = analogRead(potRedPin); 　 // read value from potentiometer of red LED
int potGreen = analogRead(potGreenPin); // read value from potentiometer of green LED
int potBlue = analogRead(potBluePin); 　 // read value from potentiometer of blue LED

int val = analogRead(0);
val = map(val, 0, 1023, 0, 255);
analogWrite(9, val);

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

colorRGB(val,val1,val2); // configure the analog value for RGB LED
}
}
//define the colorRGB function
void colorRGB(int red, int green, int blue){
analogWrite(redPin,constrain(red,0,255));
analogWrite(greenPin,constrain(green,0,255));
analogWrite(bluePin,constrain(blue,0,255));
}
