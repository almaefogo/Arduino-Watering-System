#include "Arduino.h"
//Constants
const int relay = 9;    //relay at pin 9 of Arduino
const int sensor = 8;   //power to moisture sensor on pin 8
const int moisture = A0;  //Hygrometer sensor analog pin output at pin A0 of Arduino

//Variables
int value;
void setup()
{
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(sensor, OUTPUT);
  digitalWrite(relay,HIGH);
}

void loop()
{
  // When the plant is watered well the sensor will read a value , I will keep the 400
  // value but if you want you can change it below.
  digitalWrite(sensor, HIGH);   //power on to moisture sensor
  delay(1000);
  value = analogRead(moisture);   //Read analog value
  delay(1000);
  value = constrain(value,0,900);  //Keep the ranges!
  value = map(value,0,900,0,100);  //Map value : 900 will be 100 and 0 will be 0
  Serial.print("moisture level: ");
  Serial.println(moisture)

  //Start the watering if humidity decrease down of 20%
  if (value < 20){
    digitalWrite(relay,LOW);    //relay on to start the pump for 10 sec
    delay(10000);
  }
  digitalWrite(relay,HIGH);//relay off

  delay(500);
 digitalWrite(sensor, LOW);   //power to sensor off
 delay(60000);  //small delay
}
