int ldrPin = A0; 
int ledPin = 13; 
int ldrValue = 0; 
int threshold = 500; 
void setup() {
Serial.begin(9600); 
pinMode(ledPin, OUTPUT); 
}
void loop() {
ldrValue = analogRead(ldrPin); 
Serial.print("Light Level: ");
Serial.print(ldrValue);
if (ldrValue > threshold) {
Serial.println(" --> Good Light Intensity 🌞");
digitalWrite(ledPin, LOW); 
} else {
Serial.println(" --> Bad Light Intensity 🌑");
digitalWrite(ledPin, HIGH); 
}
delay(500); 
}

//Interfacing of temperature sensor LM35
const int sensorPin = A0;
void setup() {
Serial.begin(9600);
}
void loop() {
int sensorValue = analogRead(sensorPin); 
float voltage = sensorValue * (5.0 / 1023.0);
float temperatureC = voltage * 100.0;
Serial.print("Temperature: ");
Serial.print(temperatureC);
Serial.println(" °C");
delay(1000); 
}