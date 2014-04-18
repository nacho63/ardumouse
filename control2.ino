/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/AnalogInput

 */

int sensorX = A0;    // select the input pin for the potentiometer
int sensorY = A1;    // select the input pin for the potentiometer
int sensorZ = A2;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int X=0;
int Y=0;
int Z=0;
int leveledX;
int leveledY;
int leveledZ;
boolean firstTime=true;
int previousX=0;
int previousY=0;
int previousZ=0;
boolean Xflag=false;
boolean Yflag=false;
boolean Zflag=false;
int falsepos=3;
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  
}

void loop() {
  // read the value from the sensor:
  if (firstTime){
  calibrate();
  firstTime=false;
  }
  previousX=X;
  
  X= analogRead(sensorX);
  previousY=Y;
  Y= analogRead(sensorY);
   previousZ=Z;
  Z= analogRead(sensorZ);
  int test=abs(leveledX-X);
  if(test>20){
  //  Serial.print("X ");  
  // Serial.println(leveledX-X);
  Xflag=true;
  
 }
 else{
 Xflag=false;
 }
  test=abs(leveledY-Y);
  if(test>20){ 
   // Serial.print("Y: ");
    //Serial.println(leveledY-Y);
    Yflag=true;
  }
  else{
    Yflag=false;
  }
   test=abs(leveledZ-Z);
  if(test>60){ 
  //  Serial.print("Z ");
    // Serial.println(leveledZ-Z);
    Zflag=true;
  }
  else{
   Zflag=false;
  }
  if (Xflag || Yflag || Zflag){
    Serial.print(leveledX-X);
     Serial.print(" ");
    Serial.print(leveledY-Y);
    Serial.print(" ");
    Serial.println(leveledZ-Z);
  }
  
  // stop the program for <sensorValue> milliseconds:
  delay(30);
  // turn the ledPin off:
 // digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  //delay(sensorValue);
}
void calibrate(){
  delay(100);
  Serial.println("Hello");
    X= analogRead(sensorX);
    previousX=X;
    leveledX=X;
    Y= analogRead(sensorY);
    previousY=Y;
     leveledY=Y;
    Z= analogRead(sensorZ);
    previousZ=Z;
    leveledZ=Z;
  
}
