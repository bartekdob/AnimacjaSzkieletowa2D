#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "cSkeleton.h"

using namespace std;


class cSkeletonPositions
{
	vector<sSkeletonPosition> positionsVector;

public:
	cSkeletonPositions();
	~cSkeletonPositions();

	vector<sSkeletonPosition> &getPositionsVector();

	void addPosition(cSkeleton &skeleton);
	void write(const string &filename);
	void read(const string &filename);
};

