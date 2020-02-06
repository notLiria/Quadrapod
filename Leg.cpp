#include "Leg.h"


namespace Quadrapod {
	Leg::Leg():
		hipLateral(defaultServo), hipVertical(defaultServo), knee(defaultServo)
	{
		// AUthor: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To be the default constructor
		// Input: None
		// Output: An initialized leg object. This constructor is needed in order to create arrays

	}
	Leg::Leg(Leg& someLeg) :
		hipLateral(someLeg.hipLateral), hipVertical(someLeg.hipVertical), knee(someLeg.knee), left(someLeg.left), legTime(someLeg.legTime)
	{
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To create a new leg from an old leg
		// Input: An old leg
		// Output: A new leg

	}
	Leg::Leg(Servo& hipX, Servo& hipY, Servo& knee_) :
		hipLateral(hipX), hipVertical(hipY), knee(knee_) 
	{
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To initialize the leg object, will initalize the leg to being "left"
		// Input: The three servos
		// Output: None
		legTime = 0; 
		left = true;
	}
	Leg::~Leg() 
	{
	}
	void Leg::resetLeg() 
	{
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To reset the leg, sets each servo to 90 degrees
		// Input: None
		// Output: None
		hipLateral.write(90);
		hipVertical.write(90);
		knee.write(90);
		delay(120); // Delay 120 because 120ms is the time it takes to move 60 degrees 
	}
	void Leg::stepForwards() 
	{
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To step the leg "Forwards" relative to itself one "percent" of a cycle. 
		// Input: None
		// Output: None

		/*
		We choose the function 60 sin (0.5 pi t) + 90 for the lateral leg
		- 60 is the maximum angle away in either direction, either 30 degrees or 150 degrees away from the centre
		- Horizontal compression by a factor of 2/pi in order to slow it down to a manageale amount
		- This gives you the answer in degrees so that you don't have to convert it to degrees
		- Reflected in the x-axis for the right leg because it's on the other side of the body
		We choose the function 25 sin(1.5 pi t) + 90 for the vertical
		- 25 because that is the maximum amount that the leg can move down before it smacks into the body
		- Horizontal stretch by a factor of 2/3pi in order to keep it in sync with the lateral leg
		- This horizontal stretch allows the minimum position of the vertical leg to be at the maximum position of the lateral

		Essentially, for the vertical leg, we have the function
		25 sin (1.5 pi t) + 90; 0<t<1.5 or 2.3 < t < 1

		*/
		double lateralAngle;
		double verticalAngle;
		// If the leg is on the right side of the body, the sine wave must be flipped, otherwise it will walk in circles
		// We divide it by 25 because that's 1/4 of a cycle
		if (this->left == true) {
			lateralAngle = sin(0.5 * PI * (double) this->legTime / 25);
		}
		else {
			lateralAngle = -sin(0.5 * PI * (double) this->legTime / 25);

		}

		verticalAngle = sin(1.5 * PI * (double) this->legTime / 25);
		// The vertical angles are the same regardless of which leg it is
		int hipLateralAngle = 60 * lateralAngle + 90;
		int hipVerticalAngle = -25 * verticalAngle + 90;

		/*
		We want the leg to take a break and not move at all for 1/4 of a cycle after the cycle completes. This way we ensure that we have 3 legs on the ground at all times, forming a stable pyramid.
		*/

		if (this->legTime < 100) {
			hipLateral.write(hipLateralAngle);
			if (this->legTime < 25) {
				// First quarter cycle, we want the leg to lift here
				hipVertical.write(hipVerticalAngle); 
				knee.write(hipVerticalAngle);
			}
			else if (this->legTime >= 25 && this->legTime < 87) { 
				/*
				Second and third quarter, we DO NOT Want the leg to lift here, but we DO WANT the 
				leg to move in the lateral direction. We force the leg into the minimum position, 
				and we ensure that the leg remains in the minimum position. This does cause some 
				dragging along the floor though. 
                We pick 87% to stop at because for some unknown reason, 87% fails and causes the 
                leg to "jump"
                */
				hipVertical.write(-25 * sin(1.5 * PI) + 90);
				knee.write(-25 * sin(1.5 * PI) + 90);
			}
			else if (this->legTime >= 87 && this->legTime < 100) {
				/*
				Final qaurter, we want the leg to move back up to position for the next cycle. 
				This ensures that it is more natural if we start here. 
				*/

				hipVertical.write(hipVerticalAngle);
				knee.write(hipVerticalAngle);
			}
		}
		else{
// Do nothing so that the leg stays in a nice position for the next quarter cycle
		}
		delay(10); // We need a delay because otherwise, the signal is never sent to the leg.
// Any faster than 10ms delay and it's too fast, longer than 15ms delay and the leg is jerky.
		stepTime();
	}
	void Leg::stepTime() {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: to step the time forwards by 1% 
		// Input: None
		// Output: None
		if (this->legTime < 125) {
			this->legTime = this->legTime + 1;
		}
		else {
			this->legTime = 0;
		}
	}
	void Leg::setTime(int initial) {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: to set the time/% in the cycle 
		// Input: AN integer, the percentage into the cycle we are at
		// Output: None
		this->legTime = initial;
	}
	void Leg::setRight() {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: to set the leg to the right hand side of the body
		// Input: None
		// Output: None
		this->left = false;
	};
	void Leg::setLeft() {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpoese: To set the leg to the left hand side of the body
		// Input: None
		// Output: None
		this->left = true;
	}
	void Leg::dip() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: to "Dip" the leg downwards, and then back up
		// Input: None
		// Output: None

		// Description: During a trot, there are two legs which are essentially stationary. 
		// THese two legs "Dip" up and down in response to the positions of the moving legs.
		double verticalAngle = sin(1.5 * PI * (double) this->legTime / 25);
		int hipVerticalAngle = 25 * verticalAngle + 90;
		hipLateral.write(90); // We don't want lateral movement
// Vertical angle is the opposite of that of the walking legs
		hipVertical.write(hipVerticalAngle);
		knee.write(hipVerticalAngle);
		delay(10);
		stepTime();
	}
	
	
	void Leg::turnRight() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To turn the leg to the right, only using the lateral direction
		// Input: None
		// Output: None
		double lateralAngle = -sin(0.5 * PI * (double) this->legTime / 25);
		int hipLateralAngle = 60 * lateralAngle + 90;
		this->hipLateral.write(hipLateralAngle);
		delay(10);
		this->stepTime();
	}
	void Leg::turnLeft() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To turn the leg to the left, only using the lateral direction
		// Input: None
		// Output: None
		double lateralAngle = sin(0.5 * PI * (double) this->legTime / 25);
		int hipLateralAngle = 60 * lateralAngle + 90;
		this->hipLateral.write(hipLateralAngle);
		delay(10);
		this->stepTime();
	}
}