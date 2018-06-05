#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

#define PI 3.14159265
using namespace sf;
using namespace std;

class cBone
{
	friend class cRootBone;
protected:
	
	unsigned int length;
	RectangleShape shape;
	vector<cBone*> ChildBones;
	cBone* parentBone;
	void move(Vector2f vect);

public:
	cBone();
	~cBone();
	
	RectangleShape& getShape();
	void addChild(cBone &child);
	void rotate(int angle);
	
};

