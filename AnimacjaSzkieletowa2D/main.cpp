#include <SFML/Graphics.hpp>
#include <iostream>
#include "cBone.h"
#include "cRootBone.h"
#include "cSkeleton.h"
#include "cSkeletonPositions.h"
#include "cAnimationEngine.h"


using namespace std;
using namespace sf;


/// <sumary>
/// Program main function, instantiates necessary objects.
/// </summary>
void main(int argc, char** argv)
{
	cSkeleton szkielet;
	cSkeletonPositions positions;
	cAnimationEngine engine;
	RenderWindow window(sf::VideoMode(1600, 900), "Animacja Szkieletowa 2D");
	window.setFramerateLimit(30);
	szkielet.torso.move(Vector2f(100, 100));

	bool write = 1;

	if (write) 
	{
		for (int i = 0; i < 90; i++)
		{
			positions.addPosition(szkielet);
			szkielet.torso.move(Vector2f(1, 1));
			szkielet.lForearm.rotate(4);
			szkielet.lArm.rotate(-4);
			szkielet.rForearm.rotate(-4);
			szkielet.lArm.rotate(4);
			szkielet.rotateTorso(4);
		}
		positions.write("test.dat");
	}
	else
	{
		positions.read("test.dat");
	}

	engine.animate(window, positions, szkielet);
	

}