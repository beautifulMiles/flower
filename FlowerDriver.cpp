#include "./FlowerDriver.h"

// constructor
FlowerDriver::FlowerDriver(int max_position, int open_threshold)
{
  current_motor_position = 0;
  max_motor_position = max_position;
  opening_threshold = open_threshold;
}


// This is the main loop of the flower driver, it will change commands based on the light value and the current motor position
MotorCommand FlowerDriver::ReactToLight(int light_value)
{
  // normally you would not want to 
  if (light_value < opening_threshold && current_motor_position > 0) {
    //close flower
    current_motor_position -=1;
    return MotorCommand::COUNTERCLOCKWISE;

  } else if (light_value >= opening_threshold && current_motor_position < max_motor_position){
    // open flower
    current_motor_position += 1;
    return MotorCommand::CLOCKWISE; 
  }
  // we are fully opened or closed
  return MotorCommand::OFF;

};

int FlowerDriver::GetCurrentMotorPosition()
{
  return current_motor_position;
}
int FlowerDriver::GetMaxMotorPosition()
{

  return max_motor_position;
}
int FlowerDriver::GetOpeningThreshold()
{
  return opening_threshold;
}