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

    void generateYard();
	void destroy();
    void shuffleBones();
	void getRemainingBones(int &);
	void draw();


private:

    struct node
    {
        Bone * data;
        node * next;

        node()
        {
            data = nullptr;
            next = nullptr;
        }

        node(const Bone &aBone)
        {
            if(data)
                delete data;
            data = new Bone(aBone);
            next = nullptr;
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
    static int boneCount;
	bool shuffled;
	const static int INIT_SIZE = 52;
	void destroy(node *&);
	void copyChain(Bone *&, Bone *);
    void generateYard(node *&, node *&, int &);
    void shuffleBones(node *&);

};
