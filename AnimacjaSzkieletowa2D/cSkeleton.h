#pragma once
#include <SFML\Graphics.hpp>
#include "cBone.h"
#include "cRootBone.h"

struct sSkeletonPosition
{
	Vector2f torsoPos;
	int headRot, torsoRot, lForearmRot, rForearmRot, lArmRot, rArmRot, lTibiaRot, rTibiaRot, lThighRot, rTighRot;
};


class cSkeleton
{
public:
	cRootBone torso;
	cBone lThigh, rThigh, lTibia, rTibia, lForearm, rForearm, lArm, rArm, head;
	
public:



	cSkeleton();
	~cSkeleton();

	void draw(RenderWindow &window);
	void rotateTorso(int angle);
	void setPositions(sSkeletonPosition &position);
};

