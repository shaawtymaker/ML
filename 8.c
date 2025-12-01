int Relay_pin = 8; 
void setup()
{
pinMode(Relay_pin, OUTPUT); 
Serial.begin(9600); 
digitalWrite(Relay_pin,HIGH); 
}
void loop() {
digitalWrite(Relay_pin, LOW); 
delay(10000); 
digitalWrite(Relay_pin, HIGH); 
delay(10000); 
}