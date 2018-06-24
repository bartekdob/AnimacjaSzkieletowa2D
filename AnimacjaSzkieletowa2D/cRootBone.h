#pragma once
#include "cBone.h"
#include <vector>

using namespace std;

///Specialized class for the root bone that inherites from cBone class.
class cRootBone :
	public cBone
{
protected:
	/// C++ vector of other cBone objects that are childs to this bone binded to the origin of the RootBone instead of the end of it.
	vector<cBone*> ooChildBones;
	///Holds the value of root bone length
	const unsigned int rootLength = 100;
	///Overrided method for rotating the root bone.
	/// <param name="angle"> Angle in degrees</param>
	/// <returns>Void</returns>
	void rotate(int angle);

public:
	///Adds provided cBone object to the origin oriented child bones vector.
	/// <param name="child">Refference to other cBone object</param>
	/// <returns>Void</returns>
	void addooChild(cBone &child);
	///Overrided equivalent of cBone move method that includes also origin oriented child bones.
	/// <param name="child">SFML Vector2f</param>
	/// <returns>Void</returns>
	void move(sf::Vector2f vect);
	///Contructor
	cRootBone();
	///Destructor
	~cRootBone();
	///Friend class declaration for convinience.
	friend class cSkeleton;
};

