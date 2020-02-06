#include "Spider.h"

namespace Quadrapod {

	
	Spider::Spider(Leg& legOne, Leg& legTwo, Leg& legThree, Leg& legFour) :
		leftFrontLeg(legOne), rightFrontLeg(legTwo), leftBackLeg(legThree), rightBackLeg(legFour)
	{
		// Author :Fiona Hu
		// Date: 2015-12-25
		// Purpose: To construct the quadrapod
		// Input: The four legs
		// output: A quadrapod
		this->leftFrontLeg.setLeft();
		this->leftBackLeg.setLeft();
		this->rightFrontLeg.setRight();
		this->rightBackLeg.setRight();

		this->legArray[0] = &(this->leftFrontLeg);
		this->legArray[1] = &(this->rightFrontLeg);
		this->legArray[2] = &(this->rightBackLeg);
		this->legArray[3] = &(this->leftBackLeg);


	}
	Spider::~Spider()
	{
	}
	void Spider::reset() {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To reset the spider's legs; set them all to 90 degrees
		// Input: None
		// Output: None
		this->leftFrontLeg.resetLeg();
		this->leftBackLeg.resetLeg();
		this->rightFrontLeg.resetLeg();
		this->rightBackLeg.resetLeg();
		Serial.println("Reset");
	}
	
	void Spider::trotZero() {
		// Author: Fiona Hu
		// Date: 2016-01-01-
		// Purpose: to trot in the zero direction
		// Input: None
		// Output: None
		this->legArray[1]->setRight();
		this->legArray[3]->setLeft();

		this->legArray[1]->setTime(0);
		this->legArray[3]->setTime(0);

		this->legArray[0]->setTime(25);
		this->legArray[2]->setTime(75);

		for (int i = 0; i < 75; i++) {
			this->legArray[1]->stepForwards();
			this->legArray[3]->stepForwards();
			this->legArray[0]->dip();
			this->legArray[2]->dip();
		}

	}
	void Spider::trotOne() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To trot "forwards" in the one direction
		// Input: None
		// Output: None
		this->legArray[0]->setLeft();
		this->legArray[2]->setRight();

		this->legArray[0]->setTime(0);
		this->legArray[2]->setTime(0);

		this->legArray[1]->setTime(25);
		this->legArray[3]->setTime(75);

		for (int i = 0; i < 75; i++) {
			this->legArray[0]->stepForwards();
			this->legArray[2]->stepForwards();
			this->legArray[1]->dip();
			this->legArray[3]->dip();
		}

	}
	void Spider::trotTwo() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To trot forwards in the two direction, along the 2-0 axis
		// Input: None
		// Output: None

		this->legArray[1]->setLeft();
		this->legArray[3]->setRight();

		this->legArray[3]->setTime(0);
		this->legArray[1]->setTime(0);

		this->legArray[2]->setTime(25);
		this->legArray[0]->setTime(75);
		
		for (int i = 0; i < 75; i++) {
			this->legArray[3]->stepForwards();
			this->legArray[1]->stepForwards();
			this->legArray[2]->dip();
			this->legArray[0]->dip();
		}
	}
	void Spider::trotThree() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To trot in the 3 direction, along the 1-3 axis
		// Input: None
		// Output: Nonen
		this->legArray[2]->setLeft();
		this->legArray[0]->setRight();

		this->legArray[2]->setTime(0);
		this->legArray[0]->setTime(0);

		this->legArray[3]->setTime(25);
		this->legArray[1]->setTime(75);

		for (int i = 0; i < 75; i++) {
			this->legArray[2]->stepForwards();
			this->legArray[0]->stepForwards();
			this->legArray[1]->dip();
			this->legArray[3]->dip();
		}
	}

	void Spider::stepForwards() {
		// Author: Fiona Hu
		// Date: 2015-12-25
		// Purpose: To step the spider forwards
		// Input: None
		// Output: None
		this->setForwards();
		for (int i = 0; i < 124; i++) {
			this->legArray[0]->stepForwards();
			this->legArray[2]->stepForwards();
			this->legArray[1]->stepForwards();
			this->legArray[3]->stepForwards();
		}
	}
	void Spider::stepBackwards() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purpose: To step backwards
		// Input: None
		// Output: None
		this->setBackwards();
		for (int i = 0; i < 124; i++) {
			this->legArray[2]->stepForwards();
			this->legArray[0]->stepForwards();
			this->legArray[3]->stepForwards();
			this->legArray[1]->stepForwards();
		}
	}
	void Spider::stepRight() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purpsoe: to step to the right
		// Input: None
		// Output: None
		this->setRight();
		for (int i = 0; i < 124; i++) {
			this->legArray[1]->stepForwards();
			this->legArray[3]->stepForwards();
			this->legArray[2]->stepForwards();
			this->legArray[0]->stepForwards();
		}
	}
	void Spider::stepLeft() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purpose: To step the spider left
		// Input: None
		// Output: None
		this->setLeft();
		for (int i = 0; i < 124; i++) {
			this->legArray[3]->stepForwards();
			this->legArray[1]->stepForwards();
			this->legArray[0]->stepForwards();
			this->legArray[2]->stepForwards();
		}
	}
	void Spider::setForwards() {
		// Author: Fiona Hu
		// Date: 2012-12-25
		// Purpose: To set the spider into the forward direction
		// Input: None
		// Output: None

		this->legArray[0]->setLeft();
		this->legArray[3]->setLeft();
		this->legArray[1]->setRight();
		this->legArray[2]->setRight();

		this->legArray[0]->setTime(0);
		this->legArray[3]->setTime(25);
		this->legArray[1]->setTime(50);
		this->legArray[2]->setTime(75);

	}
	void Spider::setBackwards() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purpose: To set the leg to be backwards, that is, to flip the "Left" of the original and the "Right" of the original.
		// Input: None
		// Output: None

		this->legArray[2]->setLeft();
		this->legArray[1]->setLeft();
		this->legArray[0]->setRight();
		this->legArray[3]->setRight();

		this->legArray[2]->setTime(0);
		this->legArray[0]->setTime(25);
		this->legArray[3]->setTime(50);
		this->legArray[1]->setTime(75);

	}
	void Spider::setRight() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purpose: to set the legs to walk to the left
		// Input: None
		// Output: None

		this->legArray[1]->setLeft();
		this->legArray[0]->setLeft();
		this->legArray[2]->setRight();
		this->legArray[3]->setRight();

		this->legArray[1]->setTime(0);
		this->legArray[3]->setTime(25);
		this->legArray[2]->setTime(50);
		this->legArray[0]->setTime(75);

	}
	void Spider::setLeft() {
		// Author: Fiona Hu
		// Date: 2015-12-26
		// Purposse: To set the spider to move right
		// Input: None
		// Output: None
		this->legArray[3]->setLeft();
		this->legArray[2]->setLeft();
		this->legArray[0]->setRight();
		this->legArray[1]->setRight();

		this->legArray[3]->setTime(0);
		this->legArray[1]->setTime(25);
		this->legArray[0]->setTime(50);
		this->legArray[2]->setTime(75);
	}

	void Spider::turnRight() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To turn right
		// Input: None
		// Output: None

		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 4; i++) {
				this->legArray[i]->setTime(0);
				this->legArray[i]->setLeft();
			}

			for (int i = 0; i < 50; i++) {
				this->legArray[0]->stepForwards();
				this->legArray[2]->stepForwards();
			}

			this->legArray[0]->resetLeg();
			this->legArray[2]->resetLeg();

			for (int i = 0; i < 50; i++) {
				this->legArray[1]->stepForwards();
				this->legArray[3]->stepForwards();
			}

			this->legArray[1]->resetLeg();
			this->legArray[3]->resetLeg();
		}

	}
	void Spider::turnLeft() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To turn to the left 90 degrees
		// Input: None
		// Output: None
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 4; i++){
				this->legArray[i]->setTime(0);
				this->legArray[i]->setRight();
			}

			for (int i = 0; i < 50; i++) {
				this->legArray[0]->stepForwards();
				this->legArray[2]->stepForwards();
			}

			this->legArray[0]->resetLeg();
			this->legArray[2]->resetLeg();

			for (int i = 0; i < 50; i++) {
				this->legArray[1]->stepForwards();
				this->legArray[3]->stepForwards();
			}

			this->legArray[1]->resetLeg();
			this->legArray[3]->resetLeg();
		}


		

	}

	void Spider::twistRight() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To twist the body to the right 45 degrees
		// Input: None
		// Output: None

		for (int i = 0; i < 4; i++) {
			this->legArray[i]->setTime(0);
		}
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 4; j++) {
				this->legArray[j]->turnRight();
			}
		}
	}
	void Spider::twistLeft() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To twist the body to the right 45 degrees
		// Input: None
		// Output: None

		for (int i = 0; i < 4; i++) {
			this->legArray[i]->setTime(0);
		}
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 4; j++) {
				this->legArray[j]->turnLeft();
			}
		}
	}
	void Spider::sweep() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To make the spider sweep the area in front of it, useful if we have a sensor
		// Input: None
		// Output: None
		this->twistLeft();
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 4; j++) {
				this->legArray[j]->turnLeft();
			}
		}
		this->twistRight();
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < 4; j++) {
				this->legArray[j]->turnRight();
			}
		}

	}

	void Spider::demoStep() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To demonstrate the steps, will circlestep 5 steps 
		// Input: None
		// Output: None
		for (int i = 0; i < 5; i++) {
			this->stepForwards();
		}
		for (int i = 0; i < 5; i++) {
			this->stepLeft();
		}

		for (int i = 0; i < 5; i++) {
			this->stepBackwards();
		}

		for (int i = 0; i < 5; i++) {
			this->stepRight();
		}

	}
	void Spider::demoTrot() {
		// Author: Fiona Hu
		// DAte: 2016-01-01
		// Purpose: To demonstrate the trot, will do a circlestep
		// Input: None
		// Outuput: None
		for (int i = 0; i < 5; i++) {
			this->trotZero();
		}
		for (int i = 0; i < 5; i++) {
			this->trotOne();
		}

		for (int i = 0; i < 5; i++) {
			this->trotTwo();
		}

				for (int i = 0; i < 5; i++) {
			this->trotThree();
		}

	}
	void Spider::demoTwist() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purypose: To demonstrate the twists and turns of the spider
		// Input: 
		// Output: None

		for (int i = 0; i < 5; i++) {
			this->sweep();
		}
		for (int i = 0; i < 5; i++) {
			this->twistRight();
		}
		for (int i = 0; i < 5; i++) {
			this->twistLeft();
		}
		for (int i = 0; i < 3; i++) {
			this->turnLeft();
		}
		for (int i = 0; i < 3; i++) {
			this->turnRight();
		}
	
	}
	void Spider::demoAll() {
		// Author: Fiona Hu
		// Date: 2016-01-01
		// Purpose: To demonstrate all methods fo the quadrapod
		// Input: None
		// Output: None

		/* 
		The quadrapod will take 5 steps forwards, sweep its surroundings, turn to its left, take another 3 steps, sweep again, and then trot 5 steps in the 1 direction, stop, sweep, step backwards 4 steps, turn all the way to the around, then trot 5 steps in the 0 direction, sweep, and stop.
		*/
		for (int i = 0; i < 5; i++) {
			this->stepForwards();
		}
		delay(500);
		this->sweep();
		this->sweep();
		delay(500);
		this->turnLeft();

		for (int i = 0; i < 4; i++) {
			this->stepForwards();
		}
		delay(500);
		this->sweep();
		delay(500);
		for (int i = 0; i < 4; i++) {
			this->trotOne();
		}
		this->sweep();
		for (int i = 0; i < 3; i++) {
			this->stepBackwards();
		}
		this->turnRight();
		this->turnRight();
		for (int i = 0; i < 4; i++) {
			this->trotZero();
		}
		this->sweep();
	}

}