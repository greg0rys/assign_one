#pragma once
#include <iostream>
#include<cstdlib>
#include <array>
#include <algorithm>
#include "Bone.h"

using namespace std;

class ChickenYard
{
public:
    ChickenYard();
    ChickenYard(const ChickenYard &);
    ~ChickenYard();
	ChickenYard& operator=(const ChickenYard &);

    bool isEmpty() const;
    void generateYard();
	void destroy();
    void shuffleBones();
	void getRemainingBones(int &);
	void draw();


private:

    struct node
    {
        Bone * data;
        node * next, *prev;

        node()
        {
            data = nullptr;
            next = prev = nullptr;
        }

        node(const Bone &aBone)
        {
            if(data)
                delete data;
            data = new Bone(aBone);
            next = prev = nullptr;
        }

        ~node()
        {
            if(data)
                delete data;
            data = nullptr;
            next = nullptr;
        }
    };


    node * boneYard;
    int boneCount; /* don't let this stay static remove it */
	bool shuffled;
	const static int INIT_SIZE = 52;
	void destroy(node *&);
	void copyChain(node *&, node *);
    void generateYard(node *&, node *&, int &);
    void shuffleBones(node *&);
    node * getEnd();
    std::array<node,INIT_SIZE> makeArray(node *);

};
