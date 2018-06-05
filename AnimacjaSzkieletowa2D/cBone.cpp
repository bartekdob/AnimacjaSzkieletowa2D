#include "cBone.h"



cBone::cBone()
{
	shape.setFillColor(Color::White);
	shape.setSize(Vector2f(1, 50));
	length = 50;

}


cBone::~cBone()
{
}

RectangleShape& cBone::getShape()
{
	return shape;
}

void cBone::addChild(cBone & child)
{
	ChildBones.push_back(&child);
	child.parentBone = this;
	child.getShape().setPosition(getShape().getPosition().x - sin(getShape().getRotation() * PI/180) * length, getShape().getPosition().y + cos(getShape().getRotation() * PI/180) * length);

}

void cBone::rotate(int angle)
{
	getShape().rotate(angle);
	for (int i = 0; i < ChildBones.size(); i++) 
	{
		ChildBones[i]->getShape().setPosition(getShape().getPosition().x - sin(getShape().getRotation() * PI / 180) * length, getShape().getPosition().y + cos(getShape().getRotation() * PI / 180) * length);
		ChildBones[i]->rotate(angle);
	}
}

void cBone::move(Vector2f vect)
{
	for (int i = 0; i < ChildBones.size(); i++)
	{
		ChildBones[i]->getShape().move(vect);
		ChildBones[i]->move(vect);
	}
}



