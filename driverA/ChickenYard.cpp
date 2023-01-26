//
// Created by shene on 1/13/2023.
//
#include "ChickenYard.h"

ChickenYard::ChickenYard():boneYard(nullptr), shuffled(false)
{


    generateYard();
	boneCount = INIT_SIZE;
	shuffleBones(boneYard);
	
}


void ChickenYard::generateYard()
{
    int counter = 0;
    generateYard(boneYard, boneYard, counter);
}

void ChickenYard::generateYard(node *& curr, node *& prev, int & counter)
{
    if(counter == INIT_SIZE)
        return;

    if(!curr)
    {
        curr = new node();
        curr->data = new Bone();
        curr->next = nullptr;
        generateYard(curr->next, curr, ++counter);
    }
    else
    {
        return;
    }
}

// always use a temp copy of the list to iterate or it will change the value
// of the head of the list. if we use the actual head pointer then we will
// advance it causing seg faults at some point.
ChickenYard::node* ChickenYard::getEnd()
{
    // make sure all functions that get a return value from here check to be
    // sure that they're not trying to operate on a nullptr;
    // EX: temp = getEnd() If(!temp) *do return* else do operation
    if(!boneYard)
        return nullptr;

    node * temp = boneYard;
    for(auto i = 0; i < boneCount; i++)
    {
        temp = temp->next;
    }

    return temp;
}

ChickenYard::~ChickenYard()
{
    destroy();
}


/**
 * Deallocate dynamic memory allocations
 */
void ChickenYard::destroy()
{
    destroy(boneYard);
    boneYard = nullptr;

}


void ChickenYard::destroy(node *& aBone)
{
    if(!aBone)
        return;
    destroy(aBone->next);
    delete aBone;
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

    boneA = boneB;

}

// can we not create these methods? Lets check and see if
// the random number generation can be used as the shuffle. email professor.
void ChickenYard::shuffleBones()
{
    node * temp = nullptr;
    shuffleBones
}

void ChickenYard::shuffleBones(ChickenYard::node *& yard)
{

}
