int buttonPin = 2;             　// int buttonPin = 2；
int relayPin = 3; 　            // int relayPin = 3;
int relayState = HIGH;        　// int relayState = HIGH;
int buttonState; 　　           // record the current button state
int lastButtonState = LOW; 　　 // record the last button state
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
pinMode(buttonPin, INPUT);
pinMode(relayPin, OUTPUT);
digitalWrite(relayPin, relayState); // configure the initial state of relay
}

void loop() {
int reading = digitalRead(buttonPin);
    if (reading != lastButtonState) {
      lastDebounceTime = millis();
}

if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
        if (buttonState == HIGH) {
           relayState = !relayState;
    }
  }
}
digitalWrite(relayPin, relayState);
lastButtonState = reading;
}
