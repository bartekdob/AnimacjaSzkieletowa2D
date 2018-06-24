#pragma once
#include <SFML\Graphics.hpp>
#include "cBone.h"
#include "cRootBone.h"

///Structure containing bones rotations and rootbone position that clearly indicates the skeleton position
struct sSkeletonPosition
{
	Vector2f torsoPos;
	int headRot, torsoRot, lForearmRot, rForearmRot, lArmRot, rArmRot, lTibiaRot, rTibiaRot, lThighRot, rTighRot;
};

///Class representing skeleton model. Contains all the bones and provides methods to alter their positions and rotations aswell as display them in the SFML window.
class cSkeleton
{
public:
	///Field containing cRootBone torso bone. 
	cRootBone torso;
	cBone lThigh, rThigh, lTibia, rTibia, lForearm, rForearm, lArm, rArm, head;
	
public:


	///Constructor - creates the hierarchy of bones and gives them initial position and rotation
	cSkeleton();
	///Destructor
	~cSkeleton();

	///Draws the skeleton in the provided SFML window
	/// <param name="window"> SFML RenderWindow object refference </param>
	/// <returns> void </returns>
	void draw(RenderWindow &window);
	///Rotates the torso  by the provided angle
	/// <param name="angle"> Angle in degrees</param>
	/// <returns>Void </returns>
	void rotateTorso(int angle);
	///Sets all the bones rotations and positions the rootBone accordingly to positions provided in the method argument.
	/// <param name="position"> Refference to sSkeletonPosition structure</param>
	/// <returns>Void </returns>
	void setPositions(sSkeletonPosition &position);
};

