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
    friend operator=(const ChickenYard &);

    void shuffleBones(Bone **);

private:
    Bone ** boneYard;
    int boneCount;

};