int SensorLED = 13;//define LED digital pin 13
int LedGreen = 12;
int SensorINPUT = 2; // connect tilt sensor to interrupt 1 in digital pin 2
unsigned char state = 0;



void setup() {
 pinMode(SensorLED, OUTPUT); //configure LED as output mode
 pinMode(LedGreen, OUTPUT);
 
 pinMode(SensorINPUT, INPUT); //configure tilt sensor as input mode when low voltage changes to high voltage, it triggers interrupt 1 and runs the blink function

 attachInterrupt(1, blink, RISING);
 }

 
void loop(){
 if(state!=0){ // if state is not 0
 state = 0; // assign state value 0
 digitalWrite(SensorLED,HIGH); // turn on LED
  // delay for 10ms
 }
 else{
 digitalWrite(SensorLED,LOW);// if not, turn off LED
 digitalWrite(LedGreen,HIGH);
 
 }
}


void blink(){ // interrupt function blink()
state++; //once trigger the interrupt, the state 
}
