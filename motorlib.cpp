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
	if ((direction != 1) or (direction != -1)){
		std::cout << "invalid direction, direction = -1 or 1" << std::endl;
	}
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
		default:
		  break;
		}
}

void motorDriveSpeedAll(int pwm_speed, int direction){
	motorDriveSpeed( motor1,  pwm_speed,  direction);
	motorDriveSpeed( motor2,  pwm_speed,  direction);
	motorDriveSpeed( motor3,  pwm_speed,  direction);
	motorDriveSpeed( motor4,  pwm_speed,  direction);
	
}


void motorStop(int motor){
	switch(motor){
		case motor1:
		  motorDriveSpeed(motor1, 0, 1);
		case motor2:
		 motorDriveSpeed(motor2, 0, 1);
		case motor3:
		  motorDriveSpeed(motor3, 0, 1);
		case motor4:
		  motorDriveSpeed(motor4, 0, 1);
		default:
		  break;
		}

}

void motorStopAll(){
	motorStrop(motor1);
	motorStrop(motor2);
	motorStrop(motor3);
	motorStrop(motor4);
}

void motorTurn(double time_sec, int pwm_speed, int direction){
    motorDriveSpeed( motor1,  pwm_speed,  direction);
	motorDriveSpeed( motor2,  pwm_speed,  direction);
	motorDriveSpeed( motor3,  pwm_speed,  -direction);
	motorDriveSpeed( motor4,  pwm_speed,  -direction);
	sleep(time_sec)
	motorStopAll();
}

