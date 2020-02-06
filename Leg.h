#pragma once

#include <Arduino.h>
#include <Servo.h>


namespace Quadrapod {
	class Leg {

/*
Author: Fiona Hu
Date: 2015-12-25
Purpose: To contain the leg for the quadrapod, holding all the functions and variables related to leg movement

Data Fields:
hipLateral: The lateral servo, movement in the X-Y plane only
hipVertical: The vertical hip servo, movement in the Z plane
knee: The knee servo, farthest away from the hip
left: A boolean, this detetrmines whether the leg is on the "left" side of the body. The quadrapod will walk in the direction parallel to the side with two "Lefts"
legTime: The percentage ofthe cycle that we are done. An integer between 0 and 125. Any value after 100% is a "rest" to allow for the other legs to "catch up"

Methods:
Leg(): constructor, intakes 3 Servo references and sets them to hipLateral, hipVertical, and knee
~Leg(): Destructor
resetLeg(): Resets the leg, sets all servos to 90 degrees
stepForwards(): Steps the leg "forwards" relative to its own axis <-- MAKE SURE THAT YOU HAVE TWO PARALLEL LEGS SET TO LEFT AND TWO PARALLEL LEGS SET TO RIGHT, OTHERWISE IT WILL WALK IN CIRCLES
stepTime(): Steps/increments the percentage of the cycle that we are in, resets it if needed
setTime(): sets the time to the specifiecd perecntage
setRight(): Sets the leg to be on the right side
setLeft(): Sets the leg to be on the left side
dip(): "dips" the leg depending on the percentage in the cycle
turnRight(): Turns the leg to the right one step in the cycle
turnLeft(): Turns the leg to the left one step in the cycle
*/
	private:
		Servo& hipLateral;
		Servo& hipVertical;
		Servo& knee;
		boolean left;
		int legTime;
		static Servo defaultServo;

	public: 
		Leg();
		Leg(Leg& someLeg);
		Leg(Servo& hipX, Servo& hipY, Servo& knee_);
		virtual ~Leg();
		void resetLeg();
		void stepForwards();
		void stepTime();
		void setTime(int initial);
		void setRight();
		void setLeft();
		void dip();
		void turnRight();
		void turnLeft();

	};



}