//
// Created by shene on 1/13/2023.
//
#include "ChickenYard.h"

ChickenYard::ChickenYard():boneYard(nullptr), boneCount(0), shuffled(false)
{

	for(auto x = 0; x < INIT_SIZE; x++)
		boneYard[x] = nullptr;
    generateYard();
	boneCount = INIT_SIZE;
	shuffleBones(boneYard);
	
}


void ChickenYard::generateYard()
{
    int counter = 0;
    generateYard(boneYard, counter);
}

void ChickenYard::generateYard(Bone ** bones, int & counter)
{
    if(counter == INIT_SIZE)
        return;

}

ChickenYard::~ChickenYard()
{
    destroy();
}


void ChickenYard::destroy()
{
    for(auto i = 0; i < boneCount; i++)
    {
        destroy(boneYard[i]);
    }

    if(boneYard)
        delete []boneYard;

    boneYard = nullptr;
}


void ChickenYard::destroy(Bone * aBone)
{
    if(!aBone)
        return;
    destroy(aBone);
}

ChickenYard::ChickenYard(const ChickenYard &aYard):boneYard(nullptr),boneCount(0),shuffled(false)
{
	*this = aYard;
}

ChickenYard& ChickenYard::operator=(const ChickenYard & aYard)
{
	if(this == &aYard)
		return *this;
	
	if(boneYard)
		destroy();
	boneCount = aYard.boneCount;
	shuffled = aYard.shuffled;

	boneYard = new Bone*[boneCount];

	for(auto i = 0; i < boneCount; i++)
	{
		boneYard[i] = nullptr;

		copyChain(aYard.boneYard[i], boneYard[i]);
	}

	return *this;
}


void ChickenYard::copyChain(Bone *& boneA, Bone * boneB)
{
    if(!boneB)
        return;

    if(boneA)
    {
        delete boneA;
        boneA = nullptr;
    }

    boneA = new Bone();
    boneA = boneB;

}


void ChickenYard::shuffleBones(Bone **)
{

}
