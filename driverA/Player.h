#pragma once
#include "Bone.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Player {
private:
    struct node
    {
        Bone * data = nullptr;
        node *prev = nullptr;
        node *next = nullptr;

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
            prev = nullptr;
            next = nullptr;
        }

        node(const Bone &aBone, node * next, node * prev)
        {
            if(data)
                delete data;
            data = new Bone(aBone);
            this->next = next;
            this->prev = prev;
        }

        node(const node &aNode)
        {
            if(data)
                delete data;
            if(!aNode.data)
            {
                data = nullptr;
            }
            else
            {
                data = new Bone(*aNode.data);
                next = aNode.next;
                prev = aNode.prev;
            }
        }
        ~node()
        {
            if(data)
                delete data;
            prev = next = nullptr;
        }
    };

    node * hand;
    node * endOfHand;

    int points, handCount;
    const static int HAND_START = 7;
    bool firstHand;

    void destroy(Player::node *&);
    void addToHand(const Bone &);
    Player::node*& getEnd();
    void tallyScore(Player::node *&, int &);
    void copyChain(node *&, node *);
    void displayHand(node *);

public:
    Player();
    Player(const Player &);
    Player& operator=(const Player &);
    ~Player();
    void destroy();
    void getPoints(int &);
    bool setHand(const Bone &);
    bool isFirstHand() const;
    void setFirstHand(const bool);
    void displayHand();

};
