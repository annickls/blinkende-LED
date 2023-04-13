#include <Arduino.h>

// Definition Variablen
const int greenLedPin = 22;
const int potiPin = 36;
const int forcePin = 39;
const int muxSIG = 36;
const int muxS0 = 26;
const int muxS1 = 25;
const int muxS2 = 33;
const int muxS3 = 32;
int val =0;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// int SetMuxChannel(byte channel){
//   digitalWrite(muxS0, bitRead(channel, 3));
//   digitalWrite(muxS1, bitRead(channel, 2));
//   digitalWrite(muxS2, bitRead(channel, 1));
//   digitalWrite(muxS3, bitRead(channel, 0));
// }

int readMux(int channel){
  int controlPin[] = {muxS0, muxS1, muxS2, muxS3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(muxSIG);

  //return the value
  return val;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(muxSIG, INPUT);
  pinMode(muxS0, OUTPUT);
  pinMode(muxS1, OUTPUT);
  pinMode(muxS2, OUTPUT);
  pinMode(muxS3, OUTPUT);

  Serial.begin(9600);

  // Serial.println("\n hello from the setup");
  // pinMode(greenLedPin, OUTPUT);
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


  //Einlesen von Potentiometern ueber einen Multiplexer
    // send a 0001 for output "1"
    for(int j=0;j<16;j=j+1){

    Serial.print("Value at channel ");
    Serial.print(j);
    Serial.print(" is : ");
    Serial.println(readMux(j));
    
    // // 3 Potis Ringfinger
    // Serial.print("Potis Ringfinger \n");
    // // float voltage = floatMap(readMux(0), 0, 4095, 0, 3.3); //Spannung skalieren
    // float angle = map(readMux(0), 0, 4095, 0, 300);
    // Serial.print("Analog: \n");
    // Serial.println(readMux(0));
    // // Serial.print("\nVoltage: ");
    // // Serial.print(voltage);
    // Serial.print("Angle: \n");
    // Serial.print(angle);

    // float angle1 = map(readMux(1), 0, 4095, 0, 300);
    // Serial.print("\nAnalog: \n");
    // Serial.println(readMux(1));
    // Serial.print("Angle: \n");
    // Serial.print(angle1);

    // float angle2 = map(readMux(2), 0, 4095, 0, 300);
    // Serial.print("\nAnalog: \n");
    // Serial.println(readMux(2));
    // Serial.print("Angle: \n");
    // Serial.print(angle2);

    // Serial.print("\n \n");


    // Potis Mittelfinger
    // Serial.print("Potis Mittelfinger \n");
    // digitalWrite(muxS0, 1);
    // digitalWrite(muxS0, 1);
    // digitalWrite(muxS1, 0);
    // digitalWrite(muxS2, 1);
    // digitalWrite(muxS3, 0);
    // int val6 = analogRead(muxSIG);
    // Serial.print(val6);
    // Serial.print("\n \n");

    delay(5000);
    }

  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346
  //   for(int i = 0; i < 16; i ++){
  //   Serial.print("Value at channel ");
  //   Serial.print(i);
  //   Serial.print("is : ");
  //   Serial.println(readMux(i));
  //   delay(1000);
  // }

  // Einlesen eines Kraftsensors
  // for (int k=1;k<10;k=k+1){
  //   int sensor_value = analogRead(forcePin);
  //   Serial.print("\n Analog reading = ");
  //   Serial.print(sensor_value);
  //   delay(5000);
  // }
  
  while(1);
}


