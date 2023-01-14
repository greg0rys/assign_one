//
// Created by shene on 1/13/2023.
//
#include "ChickenYard.h"

ChickenYard::ChickenYard():boneYard(nullptr), boneCount(0), shuffled(false)
{
	// we need an init size const
	// for each of the init = nullptr;
	// else 
	//
	
	for(auto x = 0; x < INIT_SIZE; x++)
		boneYard[x] = nullptr;
	boneCount = INIT_SIZE;
	shuffleBones(boneYard);
	
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
