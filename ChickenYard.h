#pragma once
#include <iostream>
#include "Bone.h"

using namespace std;

class ChickenYard
{
public:
    ChickenYard();
    ChickenYard(const ChickenYard &);
    ~ChickenYard();
	ChickenYard& operator=(const ChickenYard &);

	void destroy();
    void shuffleBones(Bone **);
	void getRemainingBones(int &);
	void draw();

private:
    Bone ** boneYard;
    int boneCount;
	bool shuffled;
	const static int INIT_SIZE = 52;
	void destroy(Bone *);
	void copyChain(Bone *, Bone *);
    void makeArray(node *);

};
