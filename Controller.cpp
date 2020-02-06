#include "Controller.h"

namespace Quadrapod {

	Controller::Controller(int xOne, int yOne, int xTwo, int yTwo):
		pinXOne(xOne), pinXTwo(xTwo), pinYOne(yOne), pinYTwo(pinYTwo)
	{
		delay(500);
		this->calibrate();
		Serial.println("Calibrated!");
	}


	Controller::~Controller()
	{
	}

	void Controller::calibrate() {
// Author: Fiona Hu
// Date: 2015-12-26
// Purpose: To calibrate the controller
// Input: None
// Output: None
		this->xOne_Default = this->read()[0];
		this->yOne_Default = this->read()[1];
		this->xTwo_Default = this->read()[2];
		this->yTwo_Default = this->read()[3];
	}
	int* Controller::read() {
// Author: Fiona Hu
// Date: 2015-12-26
// Purpose: To read the controller values
// Input: None
// Output: An intehger arary of size 4 containg all the x1, y1, x2, y2 values, in that order.
		int output[4];
		output[0] = analogRead(pinXOne);
		output[1] = analogRead(pinYOne);
		output[2] = analogRead(pinXTwo);
		output[3] = analogRead(pinYTwo);
		return output;
	}
	void Controller::print() {
// Author: Fiona Hu
// Date: 2015-12-26
// Purpose: To print the controller's values to the serial
// Input: None
// Output: None
		for (int i = 0; i < 4; i++) {
			Serial.print(this->read()[i]);
			Serial.print(" ");
		}
		Serial.println(" ");
	}
	int Controller::checkDeltaX_One() {
		// Author: Fiona Hu
// Date: 2015-12-26
// Purpose: To check the delta x
// Input: None
// Output: An integer, either 0, 1, or 2. If it is 0, then that means that the 
// stick has not moved. If it is 1, then that means that the stick has been moved to 
// the right. If it is 2, then that means that the stick has been moved to the left. 
// 
		int x2 = this->read()[0];
		int output;
		if ((x2 - xOne_Default) > 10) {
			output = 2;
		}
		else if ((x2 - xOne_Default) < -10) {
			output = 1;
		}
		else {
			output = 0;
		}

		Serial.print(x2); 
		Serial.print(" ");
		return output;
	}

	int Controller::checkDeltaY_One() {
		int y2 = this->read()[1];
		int output;
		if ((y2 - yOne_Default) > 2) {
			output = 2;
		}
		else if ((y2 - yOne_Default) < -2) {
			output = 1;
		}
		else {
			output = 0;
		}

		Serial.print(y2);
		Serial.print(" ");
		return output;

	}
	void Controller::printDefaults() {
		Serial.print(xOne_Default);
		Serial.println(" ");
		Serial.print(yOne_Default);
	}
}