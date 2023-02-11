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
    struct node
    {
        node *next, *prev;
        Bone *data;



        node()
        {
            next = prev = nullptr;
            data = nullptr;
        }



        explicit node(const Bone &aBone)
        {
            if (data)
                delete data;
            data = new Bone(aBone);
            prev = next = nullptr;
        }



        ~node()
        {
            if (data)
                delete data;
            next = prev = nullptr;
            data = nullptr;
        }



        void setData(const Bone &aBone)
        {
            if (data)
                delete data;
            data = new Bone(aBone);
        }
    };
    node *getHead();

    void setHead(const Bone &); // don't create nodes using the new operator
    // that
    // use this method.
    node *getTail();

    void setTail(node &);

    virtual void displayList(node *);

    void destroyList(node *&);


    void copyChain(node *&, node *);

    void countChain(node *, int &);

private:
    // all derived versions of the DLL container will be the exact same
    // so we don't need a virtual destructor on the node,
    // rather we will just use a virtual destructor in the base class DLL


    node *head;
    node *tail;
    int listSize;

public:
    DLL();

    DLL(const DLL &);

    DLL &operator=(const DLL &);

    virtual ~DLL();

    void
    destroy(); // doesn't need to be virtual because all derived classes will use the destructor in the same way so I won't override it.
    virtual void display() = 0;

    void getCount(int &);
    void getCount(const DLL &,int &);

    bool isEmpty();

};


class playersDLL : public DLL
{

private:
#define HAND_SIZE 7
    int handCount;
    Bone * recentDraw; // store a pointer to the last drawn bone

    DLL::node *findDouble(DLL::node *);

    void getPoints(DLL::node *, int &);

    virtual void displayList(DLL::node *);


public:
    playersDLL();

    playersDLL(const playersDLL &);

    playersDLL & operator=(const playersDLL &);

    virtual ~playersDLL();

    virtual void display();

    void getPoints(int &);


};

class yardsDLL : public DLL
{
private:
#define YARD_SIZE 52
    int boneCount;


public:
};
