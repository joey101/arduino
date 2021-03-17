#include <IRremote.h>

int RECV_PIN = 11; //define the pin of RECV_PIN 11
IRrecv irrecv(RECV_PIN); //define RECV_PIN as infrared receiver
decode_results results; //define variable results to save the result of infrared receiver


void setup(){
Serial.begin(9600); // configure the baud rate 9600
irrecv.enableIRIn(); //Boot infrared decoding
}


void loop() { //test if receive decoding data and save it to variable results
if (irrecv.decode(&results)) {  // print data received in a hexadecimal
Serial.println(results.value, HEX);
irrecv.resume(); //wait for the next signal
}
}
