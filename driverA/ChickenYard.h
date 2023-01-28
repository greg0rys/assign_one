#pragma once
#include <iostream>
#include<cstdlib>
#include <array>
#include <algorithm>
#include <random>
#include "Bone.h"

using namespace std;

class ChickenYard
{

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


    const static int INIT_SIZE = 52;

    std::array<Bone,INIT_SIZE> yardArray;
    node * boneYard;
    int boneCount;
	bool shuffled;
	void destroy(node *&);
	void copyChain(node *&, node *);
    void generateYard(node *&, std::array<Bone,INIT_SIZE> &, int &);
    void printYardArr();
    int getCount(node *) const;
    std::array<Bone,INIT_SIZE> makeArray() const;

public:
    ChickenYard();
    ChickenYard(const ChickenYard &);
    ~ChickenYard();
    ChickenYard& operator=(const ChickenYard &);
    ChickenYard& operator=(const std::array<node,52> &);

    bool isEmpty() const;
    void generateYard();
    void destroy();
    void shuffleBones();
    int getCount();
    void draw();

};
