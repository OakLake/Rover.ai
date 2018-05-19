#include "motorlib.h"
#include <iostream>
#include <unistd.h>


using namespace std;

int main(int argc, char** argv){
	
	if (initialize_motorlib() == 0){
		cout << "Motorlib initialised" << endl;
		}else{
		cout << "Motorlib Failled to initialise!!" << endl;
			}
	cout << "Turning motor" << endl;
	motorDriveSpeedAll(25, 1);
	sleep(3);
	motorStopAll();
	sleep(3);
	cout << "Diff Drive" << endl;
	motorDriveSpeedDiff( 20,  45,  1);
	sleep(3);
	motorStopAll();
	sleep(3);
	cout << "Stopped and exiting!" << endl;
	
	return 0;
}
