#include "Player.h"

Player::Player(): hand(nullptr), endOfHand(nullptr), points(0), handCount(0),
                  firstHand
                          (true)
{

}

Player::Player(const Player &aPlayer): hand(nullptr), endOfHand(nullptr),
                                       points(0)
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

    if(!aPlayer.endOfHand)
        endOfHand = nullptr;
    else
        endOfHand = new node(*aPlayer.endOfHand);

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


bool Player::isFirstHand() const
{
    return firstHand;
}

void Player::setFirstHand(const bool val)
{
    firstHand = val;
}


bool Player::setHand(const Bone &aBone)
{
    if(!isFirstHand())
        return false;
    node * temp = nullptr;

    if(!hand)
    {
        hand = new node(aBone);
        hand->prev = nullptr;
        hand->next = nullptr;
        return true;
    }

    temp = new node(aBone);
    temp->prev = nullptr;
    temp->next = hand;
    endOfHand = hand;
    hand->prev = temp;
    hand = temp;

    return true;

}




void Player::addToHand(const Bone & aBone)
{
    node * end = getEnd();

    end->next = new node(aBone);
    end->next->prev = end;
    end->next->next = nullptr;

    endOfHand = end->next;
}


Player::node*& Player::getEnd()
{
    return endOfHand;
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


// need to update this to manage DLL
void Player::copyChain(Player::node *&head, Player::node *copy)
{

    if (!copy)
        return;
    head = new node(*copy->data);
    copyChain(head->next, copy->next);

}


void Player::displayHand()
{
    cout << "Current Hand: " << endl;
    displayHand(hand);
    cout << endl;
}


void Player::displayHand(Player::node *head)
{
    if(!head)
        return;
    cout << "[ " << head->data->getSideA()
         << "|" << head->data->getSideB() << " ]";
    displayHand(head->next);
}



