#pragma once
#include <Leg.h>

namespace Quadrapod {
	class Spider
	{

/*
Author: Fiona Hu
Date: 2015-12-25
Purpose: To contain the legs for the spider

Data Fields:
leftFrontLeg: The left front leg
rightFrontLeg: The right front leg
leftBackLeg: The left back leg
rightBackLeg: The right back leg


Methods: 

public:
Spider(): The constructor, intakes 4 servos to form the spider
~Spider(): The destructor
reset(): Resets the legs

trotZero(): Trots along the 0-2 axsi, with 0 being "Forwards"
trotOne(): Trots along the 1-3 axis, with 1 being "Forwards"
trotTwo(): Trots along the 0-2 axis, with 2 being "Forwards"
trotThree(): Trots along the 1-3 axis, with 3 being "Forwards"

stepForwards(): Steps the quadrapod one step/cycle forwards
stepBackwards(): Steps the quadrapod one step/cycle forwards
stepRight(): Steps the quadrapod one step/cycle to the right
stepLeft(): Steps the quadrapod one step/cycle to the left

setForwards(): Sets the quadrapod to the "Forwards" position
setBackwards(): Sets the quadrapod to the "Backwards" position
setRight(): Sets the quadrapod to the "right" position
setLeft(): Sets the quadrapod to the "left" position

turnRight(): Turns to the right 90 degrees
turnLeft(): Turns to the left 90 degrees

twistRight(): Twists the spider to the right 45 degrees
twistLeft(): Twists the spider to the left 45 degrees
sweep(): Sweeps the spider left to right

demoStep(): Demonstrates step procedures
demoTrot(): Demonstrates trot procedures
demoTwist(): Demonstrates twists/turns
demoAll(): Combines all methods in an attempt to imitate a natural movement cycle
*/
	private:
		Leg& leftFrontLeg;
		Leg& rightFrontLeg;
		Leg& leftBackLeg;
		Leg& rightBackLeg;
		Leg *legArray[4];

	public:
		Spider(Leg& legOne, Leg& legTwo, Leg& legThree, Leg& legFour);
		~Spider();
		void reset();

		void trotZero();
		void trotOne();
		void trotTwo();
		void trotThree();

		void stepForwards();
		void stepBackwards();
		void stepRight();
		void stepLeft();

		void setForwards();
		void setBackwards();
		void setRight();
		void setLeft();

		void turnRight();
		void turnLeft();

		void twistRight();
		void twistLeft();
		void sweep();

		void demoStep();
		void demoTrot();
		void demoTwist();
		void demoAll();
	};
}
