int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  red = pinmode(13,OUTPUT); // RED
  yellow = pinmode(12,OUTPUT); // YELLOW
  green = pinmode(11,OUTPUT); // GREEN

  red_ped = pinmode(10,OUTPUT); // RED pedestrian
  green_ped = pinmode(9,OUTPUT); // GREEN pedestrian

  button = pinmode(8,INPUT); // Button
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  digitalWrite(red, HIGH)
  //buttonState = digitalREAD(button);

  // if (buttonSTATE == HIGH) {
  //    delay(3000);
         
  //}
}
