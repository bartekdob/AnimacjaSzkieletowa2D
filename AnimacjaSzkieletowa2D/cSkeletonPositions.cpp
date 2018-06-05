#include "cSkeletonPositions.h"


cSkeletonPositions::cSkeletonPositions()
{
}


cSkeletonPositions::~cSkeletonPositions()
{
}

vector<sSkeletonPosition>& cSkeletonPositions::getPositionsVector()
{
	return positionsVector;
}

void cSkeletonPositions::addPosition(cSkeleton & skeleton)
{
	sSkeletonPosition currentPos;
	currentPos.torsoPos = skeleton.torso.getShape().getPosition();
	currentPos.torsoRot = skeleton.torso.getShape().getRotation();
	currentPos.headRot = skeleton.head.getShape().getRotation();
	currentPos.lForearmRot = skeleton.lForearm.getShape().getRotation();
	currentPos.rForearmRot = skeleton.rForearm.getShape().getRotation();
	currentPos.lArmRot = skeleton.lArm.getShape().getRotation();
	currentPos.rArmRot = skeleton.rArm.getShape().getRotation();
	currentPos.lTibiaRot = skeleton.lTibia.getShape().getRotation();
	currentPos.rTibiaRot = skeleton.rTibia.getShape().getRotation();
	currentPos.lThighRot = skeleton.lThigh.getShape().getRotation();
	currentPos.rTighRot = skeleton.rThigh.getShape().getRotation();
	positionsVector.push_back(currentPos);
}



void cSkeletonPositions::write(const string & filename)
{
	ofstream out(filename.c_str());
	for (int i = 0; i < positionsVector.size(); i++)
	{
		out.write(reinterpret_cast < char *>(&positionsVector[i]), sizeof(sSkeletonPosition));
	}
}



void cSkeletonPositions::read(const string & filename)
{
	sSkeletonPosition data;
	ifstream in(filename.c_str());

	while (in.good())
	{
		in.read(reinterpret_cast < char *>(&data), sizeof(sSkeletonPosition));
		if (in.eof()) break;
		positionsVector.push_back(data);
	}
}
