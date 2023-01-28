//
// Created by shene on 1/13/2023.
//
#include <algorithm>
#include <array>
#include <random>
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

	boneYard = new node();

    copyChain(boneYard, aYard.boneYard);


	return *this;
}


void ChickenYard::copyChain(node *& head, node * copy)
{
    if(!copy)
        return;
    head = new node(*copy->data);

    copyChain(head->next, copy->next);

}

// can we not create these methods? Lets check and see if
// the random number generation can be used as the shuffle. email professor.
void ChickenYard::shuffleBones()
{
    shuffleBones(boneYard);
}

void ChickenYard::shuffleBones(ChickenYard::node *& yard)
{
  if(isEmpty())
      return;

    auto range = std::default_random_engine {};
    array<node, INIT_SIZE> listCopy = makeArray(boneYard);
    shuffle(listCopy.begin(), listCopy.end(),range);

    destroy();
    boneYard = nullptr;

    for(auto i = 0; i < INIT_SIZE; i++)
        boneYard
}



std::array<ChickenYard::node,52>ChickenYard::makeArray(ChickenYard::node *head)
{

    array<node, 52> bones;
    int counter = 0;

    for(auto curr = head; curr; curr = curr->next)
        bones[counter++] = *curr;

    return bones;
}



bool ChickenYard::isEmpty() const
{
    return boneYard == nullptr;
}
