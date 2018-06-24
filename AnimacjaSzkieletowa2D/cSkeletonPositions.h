#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "cSkeleton.h"

using namespace std;

///Class responsible for building vector of positions, saving it to file and reading from file.
class cSkeletonPositions
{
	///C++ vector of structures containing position of a skeleton in a single frame
	vector<sSkeletonPosition> positionsVector;

public:
	///Contructor
	cSkeletonPositions();
	///Destructor
	~cSkeletonPositions();

	///Getter for positionsVector
	/// <returns>Refference to positionsVector field</returns>
	vector<sSkeletonPosition> &getPositionsVector();

	///Adds current position of the provided skeleton to the skeletonPositions vector
	/// <param name="skeleton>Takes cSkeleton class objects</param>
	/// <returns>void</returns>
	void addPosition(cSkeleton &skeleton);
	///Saves positions vector to the binary file in the path provided
	/// <param name="filename">Path to the file</param>
	/// <returns>void</returns>
	void write(const string &filename);
	///Reads positions vector from the binary file in the path provided
	/// <param name="filename">Path to the file</param>
	/// <returns>void</returns>
	void read(const string &filename);
};

