

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
