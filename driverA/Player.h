#pragma once
#include "Bone.h"
#include "ChickenYard.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Player
{
private:
    struct node
    {
        Bone * data;
        node *prev;
        node *next;
        node()
        {
            data = nullptr;
            prev = nullptr;
            next = nullptr;
        }

        node(const Bone &bone)
        {
            if(data)
                delete data;
            data = new Bone(bone);
            prev = next = nullptr;
        }

        ~node()
        {
            if(data)
                delete data;
            prev = next = nullptr;
        }
    };

    node * hand;
    int points, handCount;
    const static int HAND_SIZE = 7;

    void generateHand(node *&, node *&, Bone **);
    void destroyHandArray(Bone **);
    void destroy(Player::node *&);
    void addToHand(Player::node *&, Bone &);
    void tallyScore(Player::node *&, int &);
    void copyChain(node *&, node *);

public:
    Player();
    Player(const Player &);
    Player& operator=(const Player &);
    ~Player();
    void generateHand(ChickenYard *&);
    void destroy();
    void drawBone(ChickenYard *);
    void getPoints(int &);

};
