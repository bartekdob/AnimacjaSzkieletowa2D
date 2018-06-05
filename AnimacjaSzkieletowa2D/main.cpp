#include <SFML/Graphics.hpp>
#include <iostream>
#include "cBone.h"
#include "cRootBone.h"
#include "cSkeleton.h"
#include "cSkeletonPositions.h"
#include "cAnimationEngine.h"


using namespace std;
using namespace sf;

void main(int argc, char** argv)
{
	cSkeleton szkielet;
	cSkeletonPositions positions;
	cAnimationEngine engine;
	RenderWindow window(sf::VideoMode(1600, 900), "Animacja Szkieletowa 2D");
	window.setFramerateLimit(30);


	bool write = 0;

	if (write) 
	{
		for (int i = 0; i < 90; i++)
		{
			positions.addPosition(szkielet);
		//	szkielet.torso.move(Vector2f(1, 1));
			szkielet.lForearm.rotate(4);
			szkielet.lArm.rotate(-4);
			szkielet.rForearm.rotate(-4);
			szkielet.lArm.rotate(4);
		//	szkielet.rotateTorso(4);
		}
		positions.write("test.dat");
	}
	else
	{
		positions.read("test.dat");
	}

	engine.animate(window, positions, szkielet);
	

}