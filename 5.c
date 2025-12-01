const int buttonPin = 2; 
const int ledPin = 8; 
int buttonState = 0; 
void setup()
{
pinMode(ledPin, OUTPUT); 
pinMode(buttonPin, INPUT_PULLUP); 
}
void loop() {
if (digitalRead(buttonPin) == LOW)
{
digitalWrite(ledPin, HIGH); 
} else
{
digitalWrite(ledPin, LOW); 
}
}

//Interfacing of the Active Buzzer
int buzzer = 8; 
void setup() {
pinMode(buzzer, OUTPUT); 
}
void loop() {
digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); 
delay(1000); 
}
