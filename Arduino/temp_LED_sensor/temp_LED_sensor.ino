#include <math.h>
int led = 12;


double Thermistor(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1.11512 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;          
 Temp = (Temp * 9.0)/ 5.0 + 32.0; 
 return Temp;
}

void setup() {
  pinMode(led, OUTPUT);
 Serial.begin(9600);
}

void loop() {             
  int val;                
  double temp;            
  val=analogRead(0);      
  temp=Thermistor(val);   
  Serial.print("Temperature = ");
  Serial.print(temp);   
  Serial.println(" C");
  delay(1000); 

             if(temp >= 25.00){
              digitalWrite(led, HIGH);
              delay(50);
              digitalWrite(led, LOW);
              delay(50);
              }else{
              digitalWrite(led,LOW);
             }
}

