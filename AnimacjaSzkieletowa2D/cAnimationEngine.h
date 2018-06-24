#pragma once
#include "cSkeletonPositions.h"


/// Class responsible for animating skeleton with the provided positions
class cAnimationEngine
{
private:
	///SFML Event used to serve the events accured in the window.
	Event e;
public:
	/// Constructor
	cAnimationEngine();
	/// Destructor
	~cAnimationEngine();
	///Displays provided animation of the provided skeleton in the provided SFML window
	/// <param name="window">Refference to the SFML window object which will display the animation</param>
	/// <param name="positions">Refference to the SkeletonPositions object that contains the desired skeleton animation positions</param>
	/// <param name="skeleton">Refference to the Skeleton class object that will get animated</param>
	/// <returns>Void</returns>
	void animate(RenderWindow &window, cSkeletonPositions &positions, cSkeleton &skeleton);
};

