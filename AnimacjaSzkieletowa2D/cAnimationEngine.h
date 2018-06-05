#pragma once
#include "cSkeletonPositions.h"



class cAnimationEngine
{
private:
	//static RenderWindow *window;
	Event e;
public:
	cAnimationEngine();
	~cAnimationEngine();

	void animate(RenderWindow &window, cSkeletonPositions &positions, cSkeleton &skeleton);
};

