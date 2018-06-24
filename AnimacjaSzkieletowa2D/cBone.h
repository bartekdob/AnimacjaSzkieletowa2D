#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

#define PI 3.14159265
using namespace sf;
using namespace std;

///Basic class representing a single bone and mesh model around it
class cBone
{
	///Friend class declaration for convinience
	friend class cRootBone;
protected:
	///Holds the value of bone length
	const unsigned int length=50;
	///Holds the value of mesh thickness
	const int meshThickness = 5;
	///Was supposed to be used in Smooth Skinning algoryth implementation, didn't workout tho.
	int angleBetweenParent;
	///SFML RectangleShape object that visualy represents the bone, containts position, rotation and color of the bone.
	RectangleShape shape;
	///SFML ConvexShape object that visualy represents the mesh model, containts position of each convex point and the fill collor.
	ConvexShape mesh;
	/// C++ vector of other cBone objects that are childs to this bone.
	vector<cBone*> ChildBones;
	/// Pointer to the parent bone.
	cBone* parentBone;

public:
	///Constructor - sets the shape and mesh attributes
	cBone();
	///Destructor
	~cBone();
	///Moves the bone and it's child bones by the provided vector
	/// <param name="vect"> SFML Vector2f</param>
	void move(Vector2f vect);
	///Shape getter
	/// <returns>Refference to shape field</returns>
	RectangleShape& getShape();
	///Mesh getter
	/// <returns>Refference to mesh field</returns>
	ConvexShape& getMesh();
	///Adds provided cBone object to the child bones vector.
	/// <param name="child"> Refference to other cBone object</param>
	/// <returns>Void</returns>
	void addChild(cBone &child);
	///Rotates the bone and it's child bones by the provided angle.
	/// <param name="angle"> Angle in degrees</param>
	/// <returns>Void</returns>
	void rotate(int angle);
	
};

