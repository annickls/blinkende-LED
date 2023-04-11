#include <Arduino.h>

// Definition Variablen
const int greenLedPin = 22;
const int potiPin = 36;
const int forcePin = 39;
const int muxSIG = 36;
const int muxS0 = 32;
const int muxS1 = 33;
const int muxS2 = 25;
const int muxS3 = 26;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// int SetMuxChannel(byte channel){
//   digitalWrite(muxS0, bitRead(channel, 3));
//   digitalWrite(muxS1, bitRead(channel, 2));
//   digitalWrite(muxS2, bitRead(channel, 1));
//   digitalWrite(muxS3, bitRead(channel, 0));
// }

void setup() {
  // put your setup code here, to run once:
  pinMode(muxSIG, INPUT);
  pinMode(muxS0, OUTPUT);
  pinMode(muxS1, OUTPUT);
  pinMode(muxS2, OUTPUT);
  pinMode(muxS3, OUTPUT);

  Serial.begin(115200);
  Serial.println("\n hello from the setup");
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // test blinkende LED:
  //  for (int i=1;i<4;i=i+1){
  // digitalWrite(greenLedPin, HIGH);
  // int spannung1=analogRead(4);
  // int spannung2=analogRead(0);
  // delay(1000);
  // Serial.print(i);
  // Serial.println(": hello from the loop");
  // digitalWrite(greenLedPin, LOW);
  // delay(1000);
  // Serial.print("Spannung1: ");
  // Serial.print(spannung1);
  // Serial.print("\n");
  // Serial.print("Spannung2: ");
  // Serial.print(spannung2);
  // Serial.print("\n\n");
  // }
  // Serial.print("2. Test für Github Versionierung");

  

  //Einlesen eines Potentiometers direkt
  // for (int i=1;i<10;i=i+1){
  // int analogValue = analogRead(potiPin); //input am Pin lesen
  // float voltage = floatMap(analogValue, 0, 4095, 0, 3.3); //Spannung skalieren
  // float angle = map(analogValue, 0, 4095, 0, 300);
  
  // Serial.print("\n Analog: ");
  // Serial.print(analogValue);
  // Serial.print("\n Voltage: ");
  // Serial.print(voltage);
  // Serial.print("\n Angle: ");
  // Serial.print(angle);
  // delay(5000);
  // }

  //Einlesen von Potentiometern ueber einen Multiplexer
    // send a 0001 for output "1"
    for(int j=1;j<10;j=j+1){

    digitalWrite(muxS0, 0);
    digitalWrite(muxS1, 0);
    digitalWrite(muxS2, 0);
    digitalWrite(muxS3, 1);
    int val = analogRead(muxSIG);
    Serial.print(val);
    Serial.print("\n \n");
    delay(5000);
    }

  // Einlesen eines Kraftsensors
  // for (int k=1;k<10;k=k+1){
  //   int sensor_value = analogRead(forcePin);
  //   Serial.print("\n Analog reading = ");
  //   Serial.print(sensor_value);
  //   delay(5000);
  // }
  
  while(1);
}
