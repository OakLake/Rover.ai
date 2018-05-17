/*

*/
#ifndef MOTORLIB
#define MOTORLIB

#define motor1 1
#define motor2 2
#define motor3 3
#define motor4 4


#define motor1A_pin 17
#define motor1B_pin 27
#define motor2A_pin 22 
#define motor2B_pin 23
#define motor3A_pin 5
#define motor3B_pin 6
#define motor4A_pin 16
#define motor4B_pin 26

int initialize_motorlib(); // initialises wiripingPi and GPIO pins.
void motorDriveSpeed(int motor, int pwm_speed, int direction);
void motorDriveSpeedAll(int pwm_speed, int direction);
void motorStop(int motor);
void motorStopAll();
void motorTurn(int angle_radian, int direction); 

#endif
