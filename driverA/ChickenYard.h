#pragma once
#include "Bone.h"
#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

class ChickenYard {

private:
    struct node {
        Bone *data;
        node *next, *prev;

        node() {
            data = nullptr;
            next = prev = nullptr;
        }

        node(const Bone &aBone) {
            if (data)
                delete data;
            data = new Bone(aBone);
            next = prev = nullptr;
        }

        ~node() {
            if (data)
                delete data;
            data = nullptr;
            next = nullptr;
        }
    };

    const static int INIT_SIZE = 52;

    std::array<Bone, INIT_SIZE> yardArray;
    node *boneYard;
    int boneCount;
    bool shuffled;
    void destroy(node *&);
    void copyChain(node *&, node *);
    void generateYard(node *&, int &);
    void printYardArr();
    int getCount(node *) const;
    std::array<Bone, INIT_SIZE> makeArray() const;
    void printList(node *);
    void removeFromList(node *&);

public:
    ChickenYard();
    ChickenYard(const ChickenYard &);
    ~ChickenYard();
    ChickenYard &operator=(const ChickenYard &);


    bool isEmpty() const;
    void generateYard();
    void destroy();
    void shuffleBones();
    int getCount();
    bool draw(Bone &);
    Bone** getHand();
    void printList();
};
