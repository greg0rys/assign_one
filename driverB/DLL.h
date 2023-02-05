#pragma once
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <array>
#include "../Bone.h"

using namespace std;

class DLL
{
protected:
    // all derived versions of the DLL container will be the exact same
    // so we don't need a virtual destructor on the node,
    // rather we will just use a virtual destructor in the base class DLL
    struct node {
        node *next, *prev;
        Bone * data;

        node()
        {
            next = prev = nullptr;
            data = nullptr;
        }

        node(const Bone &aBone)
        {
            if(data)
                delete data;
            data = new Bone(aBone);
            prev = next = nullptr;
        }

        node(const node &aNode)
        {
            if(!aNode.data)
            {
                data = nullptr;
                next = aNode.next;
                prev = aNode.prev;
                return;
            }

            data = new Bone(*aNode.data);
            next = aNode.next;
            prev = aNode.prev;
        }

        ~node()
        {
            if(data)
                delete data;
            next = prev = nullptr;
            data = nullptr;
        }

        void setData(const Bone &aBone)
        {
            if(data)
                delete data;
            data = new Bone(aBone);
        }
    };
    node * head;
    node * tail;
	int * initSize;
	int listSize;

    node * getHead();
    void setHead(node &); // don't create nodes using the new operator that
    // use this method.
    node * getTail();
    void setTail(node &);

    virtual void displayList(node *);
    void destroyList(node *&);

	bool shuffleList(Bone **);

	void copyChain(node *&, node *);
    void countChain(node *, int &);

public:
    DLL();
	DLL(const DLL &);
    DLL& operator=(const DLL &);
	virtual ~DLL();
	void destroy(); // doesn't need to be virtual because all derived classes will use the destructor in the same way so I won't override it.
	virtual void display() = 0;
	void getCount(int &);
	bool isEmpty();

};


class playersDLL: public DLL 
{

	private:
		node * findDouble(node *, node *);
		void getPoints(int &);
        virtual void displayList(node *) = 0;


	public:
    playerDLL();
    playerDLL(const playerDLL &);
    virtual ~playerDLL() = 0;
    virtual display() = 0;


		
};

class yardsDLL: public DLL
{
	private:

	public:
};
