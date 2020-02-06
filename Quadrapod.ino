#include <Servo.h>
#include <Arduino.h>
#include <Leg.h>
#include <Spider.h>
#include <Controller.h>

Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;
Servo servoFive;
Servo servoSix;
Servo servoSeven;
Servo servoEight;
Servo servoNine;
Servo servoTen;
Servo servoEleven;
Servo servoTwelve;



void setup()
{
  /* add setup code here */
	Quadrapod::Leg leftFrontLeg(servoOne, servoTwo, servoThree);
	Quadrapod::Leg rightFrontLeg(servoFour, servoFive, servoSix);
	Quadrapod::Leg leftBackLeg(servoSeven, servoEight, servoNine);
	Quadrapod::Leg rightBackLeg(servoTen, servoEleven, servoTwelve);
	Quadrapod::Spider body(leftFrontLeg, rightFrontLeg, leftBackLeg, rightBackLeg);

	Serial.begin(9600);

	servoOne.attach(13);
	servoTwo.attach(12);
	servoThree.attach(11);
	servoFour.attach(10);
	servoFive.attach(9);
	servoSix.attach(8);
	servoSeven.attach(7);
	servoEight.attach(6);
	servoNine.attach(5);
	servoTen.attach(4);
	servoEleven.attach(3);
	servoTwelve.attach(2);

	body.reset();
	body.demoStep();
	body.demoTrot();
	body.demoTwist();
	body.demoAll();
	body.reset();

}

void loop()
{

  /* add main program code here */

}
