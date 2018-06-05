#pragma once
#include "cBone.h"
#include <vector>

using namespace std;

class cRootBone :
	public cBone
{
protected:
	vector<cBone*> ooChildBones;

	void rotate(int angle);

public:
	void calcooChilds();
	void calcChilds();
	void addooChild(cBone &child);
	void move(sf::Vector2f vect);
	cRootBone();
	~cRootBone();

	friend class cSkeleton;
};

