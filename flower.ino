/*
  The arduino code for opening and closing a flower
*/


#include "./FlowerDriver.h"

// this is the photo resistor
const int ldrmt_pin = 8; // in testing this is the button
//same motor but diffrent directions
const int motorA_pin  =  6; //in test this is blue led
const int motorB_pin  =  5; //in test this is red led


// driver should control all the logic
// The first value is maximum position to view as open. This should be the time it takes to make one rotation (allow some buffer for the delay in the code) Its 300 for saftey 
// the second value is  value the light sensor needs to overcome (in testing this is one for a button)
FlowerDriver driver = FlowerDriver(300, 1);


// run one time
void setup(){

  // initialize serial communication at 9600 bits per second:
 Serial.begin(9600);

  // initialize the pushbutton pin as an pull-up input
  // I think you need to set these things up like so
  pinMode(motorA_pin, OUTPUT); 
  pinMode(motorB_pin, OUTPUT);
  // you may not need this for an analog version
  // pinMode(ldrmt_pin, INPUT);

}

/// this is run constantly (its a while loop)
void loop() {

  // read of the light sensor
  // int ldrmt_value = digitalRead(ldrmt_pin); // use this for button testing
  int ldrmt_value = analogRead(ldrmt_pin); // use this for light sensor

//  Serial.print("ldrmt value: ");
//  Serial.println(ldrmt_value);
  MotorCommand command = driver.ReactToLight(ldrmt_value);
  switch (driver.ReactToLight(ldrmt_value))
  {
    case MotorCommand::CLOCKWISE:
//      Serial.println("MotorCommand::CLOCKWISE");
      // Pin 6 (blue) off, Pin 5 (red) on
      digitalWrite(motorA_pin, LOW); 
      digitalWrite(motorB_pin, HIGH);  
      break;
    case MotorCommand::COUNTERCLOCKWISE:
//      Serial.println("MotorCommand::COUNTERCLOCKWISE");
      // Pin 6 (blue) On, Pin 5 (red) off
      // blue on, red off
      digitalWrite(motorA_pin, HIGH); 
      digitalWrite(motorB_pin, LOW); 
      break;
    case MotorCommand::OFF:
//      Serial.println("MotorCommand::OFF");
      // Pin 6 (blue) off, Pin 5 (red) off
      digitalWrite(motorA_pin, LOW); 
      digitalWrite(motorB_pin, LOW);
      break;
  }

  // you can comment this out, its just for debuging
  int current_motor_pos = driver.GetCurrentMotorPosition();
  Serial.print("current_motor_pos: ");
  Serial.println(current_motor_pos);
  //TODO: you will want to factor this into the max motor position for the FlowerDriver
  delay(1);
}
