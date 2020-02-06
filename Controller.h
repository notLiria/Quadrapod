#pragma once

#include <Arduino.h>

namespace Quadrapod {
	class Controller
	{
/*
Author: Fiona Hu
Date: 2015-12-26
Purpose: To define and utilitize the controller.

Data Fields:
xOne_DEFAULT: The default X value for the leftmost controller, a "Zero"
xTwo_DEFAULT: THe default X value for the rightmost controller, a "Zero"
yOne_DEFAULT: The default Y value for the leftmost controller, a "Zero"
yTwo_DEFAULT: The default Y value for the rightmost controller, a "Zero"

pinXOne: The pin for xOne
pinxTwo: The pin for xTwo
pinYOne: The pin for yOne
pinYTwo: The pin for yTwo


Methods:
Controller(): Constructor, takes in four integers for teh pin values
calibrate(): Calibrates the controller
read(): Reads the controller
print(): Printns the controller to the serial
checkDeltaX(): Checks the delta x
*/
	private:
		int xOne_Default;
		int xTwo_Default;
		int yOne_Default;
		int yTwo_Default;

		int pinXOne;
		int pinXTwo;
		int pinYOne;
		int pinYTwo;

	public:
		Controller(int xOne, int yOne, int xTwo, int yTwo);
		~Controller();
		void calibrate();
		int* read();
		void print();
		int checkDeltaX_One();
		int checkDeltaY_One();
		void printDefaults();
	};

}