#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <unistd.h>

#include "motorlib.h"

int initialize_motorlib(){
	int failure = 0;
	// initialises wiripingPi and GPIO pins.
	if (wiringPiSetupGpio() <0 ) return 1;
	pinMode(motor1A_pin, OUTPUT);
	pinMode(motor1B_pin, OUTPUT);
	pinMode(motor2A_pin, OUTPUT);
	pinMode(motor2B_pin, OUTPUT);
	pinMode(motor3A_pin, OUTPUT);
	pinMode(motor3B_pin, OUTPUT);
	pinMode(motor4A_pin, OUTPUT);
	pinMode(motor4B_pin, OUTPUT);
	
	if (softPwmCreate (motor1A_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
    
    if (softPwmCreate (motor1B_pin, 0,  100) == 0){ cout << "PWM motor1B initialisation successful!" << endl;
	}else{ cout << "PWM motor1B initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor2A_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor2B_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor3A_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor3B_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor4A_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	if (softPwmCreate (motor4B_pin, 0,  100) == 0){cout << "PWM motor1A initialisation successful!" << endl;}
	else{cout << "PWM motor1A initialisation Failed!" << endl;
		failure = -1;}
	
	return failure;
	} 

void motorDriveSpeed(int motor, int pwm_speed, int direction){
	switch motor{
		case 1:
		if (direction == 1){
			softPwmWrite(motor1A_pin, 0);
			softPwmWrite(motor1B_pin, pwm_speed);
			}else{
			softPwmWrite(motor1B_pin, 0);
			softPwmWrite(motor1A_pin, pwm_speed);
			}
		
		case 2:
		if (direction == 1){
			softPwmWrite(motor2A_pin, 0);
			softPwmWrite(motor2B_pin, pwm_speed);
			}else{
			softPwmWrite(motor2B_pin, 0);
			softPwmWrite(motor2A_pin, pwm_speed);
			}
		case 3:
		if (direction == 1){
			softPwmWrite(motor3A_pin, 0);
			softPwmWrite(motor3B_pin, pwm_speed);
			}else{
			softPwmWrite(motor3B_pin, 0);
			softPwmWrite(motor3A_pin, pwm_speed);
			}	
		case 4:
		if (direction == 1){
			softPwmWrite(motor4A_pin, 0);
			softPwmWrite(motor4B_pin, pwm_speed);
			}else{
			softPwmWrite(motor4B_pin, 0);
			softPwmWrite(motor4A_pin, pwm_speed);
			}
		}
}

void motorDriveSpeedAll(int pwm_speed, int direction){
}


void motorStop(int motor){

}

void motorStopAll(){

}

void motorTurn(double time_sec, int turn_speed, int direction){
    	
}

