#include "cAnimationEngine.h"



cAnimationEngine::cAnimationEngine()
{
	//window = new RenderWindow(sf::VideoMode(1600, 900), "Animacja Szkwa2D");
	//window->setFramerateLimit(30);

}


cAnimationEngine::~cAnimationEngine()
{
	//delete window;
}

void cAnimationEngine::animate(RenderWindow &window, cSkeletonPositions &positions, cSkeleton &skeleton)
{
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}

		for (int i = 0; i < positions.getPositionsVector().size(); i++)
		{
			window.clear(Color::Black);
			skeleton.setPositions(positions.getPositionsVector()[i]);
			skeleton.draw(window);
			window.display();
		}

	}

}
