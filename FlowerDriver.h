/// This is the main logic of the circit. I broke this out to allow to test this independantly from the arduino bs
/// The flower diver, this will return the the logic to the audrnio loop on how to turn the two motors
#pragma once

// used to tell what command needs to be run
enum MotorCommand { 
    CLOCKWISE = 1, 
    COUNTERCLOCKWISE = 2, 
    OFF = 3 
};


class FlowerDriver
{
    private:
    // This is the current motor position value, it starts at zero
    int current_motor_position; 
    // This is the counter value we view as fully open, you things it 600 
    int max_motor_position;  
    // This is the value the light reistor has to overcome to start opening the flower
    int opening_threshold;

    public:
        // constructor
        FlowerDriver( int max_motor_position, int opening_threshold); 
        // Im leaving this as a int, because i dont know if this resitor can give you a negative value
        MotorCommand ReactToLight(int light_value);
        //getters
        int GetCurrentMotorPosition();
        int GetMaxMotorPosition();
        int GetOpeningThreshold();

};


