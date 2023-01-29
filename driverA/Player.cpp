#include "Player.h"

Player::Player():hand(nullptr),points(0),handCount(0)
{

}

Player::Player(const Player &aPlayer):hand(nullptr),points(0)
{
    *this = aPlayer;
}

Player& Player::operator=(const Player &aPlayer)
{
    if(this == &aPlayer)
        return *this;

    if(hand)
        destroy();
    hand = nullptr;

    if(!aPlayer.hand)
        hand = nullptr;
    else
        copyChain(hand, aPlayer.hand);
    this->points = aPlayer.points;

    return *this;
}


Player::~Player()
{
    destroy();
}

void Player::destroy()
{
    destroy(hand);
    hand = nullptr;
}


void Player::destroy(Player:: node *& head)
{
    if(!head)
        return;
    destroy(head->next);
    delete head;
}


void Player::generateHand(ChickenYard *& boneYard)
{
    Bone ** bones = boneYard->getHand();
    generateHand(hand, hand, bones);
    destroyHandArray(bones);


}

void Player::generateHand(Player::node *&prev, Player::node *&curr, Bone **
bones)
{
    static int counter = 0;
    if(counter == HAND_SIZE)
        return;

    if(!prev)
    {
        curr = new node(*bones[counter]);
        curr->prev = curr->next = nullptr;
        counter++;
        handCount++;
        generateHand(curr, curr->next, bones);
        return;
    }

    curr = new node(*bones[counter]);
    curr->prev = prev;
    curr->next = nullptr;
    counter++;
    handCount++;
    generateHand(curr, curr->next, bones);
}





void Player::destroyHandArray(Bone ** bones)
{
    for(auto x = 0; x < HAND_SIZE; x++)
    {
        if(bones[x])
            delete bones[x];
    }

    if(bones)
        delete []bones;

}



void Player::drawBone(ChickenYard *boneYard)
{
    if(boneYard->isEmpty())
        return;
    Bone temp;
    boneYard->draw(temp);
    addToHand(hand,temp);
}


void Player::addToHand(Player::node *&playersHand, Bone &aBone)
{
    node * temp = playersHand;
    node * newNode = nullptr;

    while(temp && temp->next)
        temp = temp->next;

    newNode = new node(aBone);
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = nullptr;
    handCount++;
}



void Player::getPoints(int &score)
{
    tallyScore(hand, score);
}


void Player::tallyScore(Player::node *& playersHand, int &score)
{
    if(!playersHand)
        return;
    score += (playersHand->data->getBoneTotal());
    tallyScore(playersHand->next, score);

}



void Player::copyChain(Player::node *&head, Player::node *copy)
{

    if (!copy)
        return;
    head = new node(*copy->data);
    copyChain(head->next, copy->next);

}