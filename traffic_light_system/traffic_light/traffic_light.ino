int red = 13;
int yellow = 12;
int green = 11;

int red_ped = 10;
int green_ped = 9;

int button = 8;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT); // RED
  pinMode(yellow,OUTPUT); // YELLOW
  pinMode(green,OUTPUT); // GREEN

  pinMode(red_ped,OUTPUT); // RED pedestrian
  pinMode(green_ped,OUTPUT); // GREEN pedestrian

  pinMode(button,INPUT); // Button
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  
  buttonState = digitalRead(button);
  
  if (buttonState == HIGH) {
    
    digitalWrite(red, HIGH);
    //delay(500);
    digitalWrite(yellow, HIGH);
    //delay(500);
    digitalWrite(green, HIGH);

    digitalWrite(red_ped, HIGH);
    digitalWrite(green_ped, HIGH);
         
  }
  else if (buttonState == LOW) {
    
    digitalWrite(red, LOW);
    
    digitalWrite(yellow, LOW);
    
    digitalWrite(green, LOW);
     digitalWrite(red_ped, LOW);
    digitalWrite(green_ped, LOW);
  }
}
