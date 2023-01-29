#include "Bone.h"

Bone::Bone(): sideA(nullptr), sideB(nullptr)
{
    // generate random number 1-9
    generateNumbers(sideA);
    generateNumbers(sideB);
}

Bone::Bone(const Bone & aBone):sideA(nullptr),sideB(nullptr)
{
    *this = aBone;
}



Bone &Bone::operator=(const Bone & aBone)
{
    if(this == &aBone)
        return *this;

    if(sideA)
    {
        delete sideA;
        sideA = nullptr;
    }

    if(sideB)
    {
        delete sideB;
        sideB = nullptr;
    }

    sideA = aBone.sideA ? new int(*aBone.sideA) : nullptr;
    sideB = aBone.sideB ? new int(*aBone.sideB) : nullptr;

    return *this;
}

Bone::~Bone()
{
    if(sideA)
    {
        delete sideA;
    }

    if(sideB)
    {
        delete sideB;
    }

    sideA = sideB = nullptr;
}


/*
 * Generate random numbers for each side of the bone
 *
 * by taking the return value of rand() % 9 + 1 we will always get a number 1-9
 */
void Bone::generateNumbers(int *& side)
{
    if(side)
        delete side;
    side = nullptr;

    side = new int(rand() % 9 + 1);
}