#include <FlowerDriver.h>

// this is the photo resitor
int ldrmt = A5;
//same motor but diffrent directions
const int motorA =  7;
const int motorB =  8;

// driver should control all the logic
// The 600 is the max number of times to run, 
// 30 is the value your photo sensor reads, you should change these two values when you test
FlowerDriver driver = FlowerDriver(600, 30);


// e1 is enabler port, this will dictate when the motor can start and stop  
// high is zero, low is off 
void setup(){
  // I think you need to set these things up like so
  pinMode(ldrmt,INPUT) ;  	//
  pinMode(motorA,OUTPUT) ; 	//
  pinMode(motorA,OUTPUT) ;
  // This will let you log https://forum.arduino.cc/t/cout-in-arduino/82204
  Serial.begin(9600);

}

/// this loop is continually called as part of the arduino stuff. it is a while loop
void loop() {

  int ldrStatus = analogRead(ldrmt);
  Serial.print("ldrStatus: ", ldrStatus);

  switch (driver.ReactToLight(ldrStatus))
  {
    case MotorCommand::CLOCKWISE:
      digitalWrite(motorA, LOW); 
      digitalWrite(motorB, HIGH);
    case MotorCommand::COUNTERCLOCKWISE:
      digitalWrite(motorA, HIGH); 
      digitalWrite(motorB, LOW); 
    case MotorCommand::OFF:
      digitalWrite(motorA, LOW); 
      digitalWrite(motorB, LOW);
  }

  Serial.print("current motor pos: ", driver.GetCurrentMotorPosition());
  // You always want this delay to run ( i dont know why you want it)
  delay(1);
}
