#include "cSkeleton.h"



cSkeleton::cSkeleton()
{
	torso.getShape().move(Vector2f(200, 200));   // TEMP 
	head.getShape().setSize(Vector2f(1, 20));




	torso.addChild(lTibia);
	torso.addChild(rTibia);
	torso.addooChild(lForearm);
	torso.addooChild(rForearm);
	torso.addooChild(head);


	lTibia.addChild(lThigh);
	rTibia.addChild(rThigh);


	lForearm.addChild(lArm);
	rForearm.addChild(rArm);

	head.rotate(180);

	lForearm.rotate(15);
	lArm.rotate(-15);

	rForearm.rotate(-15);
	rArm.rotate(15);

	lTibia.rotate(15);
	lThigh.rotate(-15);

	rTibia.rotate(-15);
	rThigh.rotate(15);
}


cSkeleton::~cSkeleton()
{
}

void cSkeleton::draw(RenderWindow &window)
{
	window.draw(torso.getShape());

	window.draw(lTibia.getShape());
	window.draw(lForearm.getShape());
	window.draw(lArm.getShape());

	window.draw(rTibia.getShape());
	window.draw(rThigh.getShape());
	window.draw(rForearm.getShape());
	window.draw(rArm.getShape());

	window.draw(head.getShape());
	window.draw(lThigh.getShape());

}

void cSkeleton::rotateTorso(int angle)
{
	Vector2f oldPosition = lTibia.getShape().getPosition();
	torso.rotate(angle);
	Vector2f mVector = oldPosition - lTibia.getShape().getPosition();
	torso.move(mVector);
}

void cSkeleton::setPositions(sSkeletonPosition  &position)
{
	Vector2f moveVector =  position.torsoPos - torso.getShape().getPosition();
	torso.move(moveVector);

	int angle = position.torsoRot - torso.getShape().getRotation();
	torso.rotate(angle);

	angle = position.lTibiaRot - lTibia.getShape().getRotation();
	lTibia.rotate(angle);

	angle = position.lThighRot - lThigh.getShape().getRotation();
	lThigh.rotate(angle);

	angle = position.lForearmRot - lForearm.getShape().getRotation();
	lForearm.rotate(angle);

	angle = position.lArmRot - lArm.getShape().getRotation();
	lArm.rotate(angle);

	angle = position.rTibiaRot - rTibia.getShape().getRotation();
	rTibia.rotate(angle);

	angle = position.rTighRot - rThigh.getShape().getRotation();
	rThigh.rotate(angle);

	angle = position.rForearmRot - rForearm.getShape().getRotation();
	rForearm.rotate(angle);

	angle = position.rArmRot - rArm.getShape().getRotation();
	rArm.rotate(angle);

	angle = position.headRot - head.getShape().getRotation();
	head.rotate(angle);
}
