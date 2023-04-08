#include <Arduino.h>

// Definition Variablen
const int greenLedPin = 22;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\n hello from the setup");
  pinMode(greenLedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   for (int i=1;i<4;i=i+1){
  digitalWrite(greenLedPin, HIGH);
  int spannung1=analogRead(4);
  int spannung2=analogRead(0);

  delay(1000);
  Serial.print(i);
  Serial.println(": hello from the loop");
  digitalWrite(greenLedPin, LOW);
  delay(1000);
  
  Serial.print("Spannung1: ");
  Serial.print(spannung1);
  Serial.print("\n");
  Serial.print("Spannung2: ");
  Serial.print(spannung2);
  Serial.print("\n\n");
  }
  while(1);
  
}
