#include "cRootBone.h"



void cRootBone::addooChild(cBone & child)
{
	child.parentBone = this;
	ooChildBones.push_back(&child);
	child.getShape().setPosition(getShape().getPosition());
}

void cRootBone::rotate(int angle)
{
	getShape().rotate(angle);
	for (int i = 0; i < ChildBones.size(); i++)
	{
		ChildBones[i]->getShape().setPosition(getShape().getPosition().x - sin(getShape().getRotation() * PI / 180) * rootLength, getShape().getPosition().y + cos(getShape().getRotation() * PI / 180) * rootLength);
		ChildBones[i]->rotate(angle);
	}
	for (int i = 0; i < ooChildBones.size(); i++)
	{
		ooChildBones[i]->getShape().setPosition(getShape().getPosition());
		ooChildBones[i]->rotate(angle);
	}
}

void cRootBone::move(sf::Vector2f vect)
{
	getShape().move(vect);
	for (int i = 0; i < ChildBones.size(); i++)
	{
		ChildBones[i]->move(vect);
	}
	for (int i = 0; i < ooChildBones.size(); i++)
	{
		ooChildBones[i]->move(vect);
	}
}

cRootBone::cRootBone()
{
	getShape().setSize(Vector2f(2, rootLength));
}


cRootBone::~cRootBone()
{
}
