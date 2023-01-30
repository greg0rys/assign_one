#include "Player.h"

/*
 * Default constructor
 */
Player::Player(): hand(nullptr), endOfHand(nullptr), points(0), handCount(0)
,playerNo(0),firstHand(true)

{

}

/*
 * Copy Constructor
 * TODO: edit copy chain method to copy a double linked list rather than single
 */
Player::Player(const Player &aPlayer): hand(nullptr), endOfHand(nullptr),
                                       points(0)
{
    *this = aPlayer;
}


/*
 * Overloaded operator= create deep copies of player objects
 */
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


/*
 * Class Destructor
 */
Player::~Player()
{
    destroy();
}


/*
 * Called at class destruction, this method will pass the head of the list
 * into the recursive version of itself to deallocate all dynamic pointers
 */
void Player::destroy()
{
    destroy(hand);
    hand = nullptr;
}

/*
 * Recursively destroy the DLL
 */
void Player::destroy(Player:: node *& head)
{
    if(!head)
        return;
    destroy(head->next);
    delete head;
}


/*
 * Check to see if this is the first time the players hand has been dealt.
 */
bool Player::isFirstHand() const
{
    return firstHand;
}


/*
 * Set true if player has not had a hand dealt yet false if else.
 */
void Player::setFirstHand(const bool val)
{
    firstHand = val;
}


/*
 * Create a double linked list by getting bone objects passed to the player's
 * hand from the ChickenYard. The yard manages this by first giving a copy
 * of the bone obj stored in the list and then removing it from the yard
 */
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
        handCount++;
        return true;
    }

    temp = new node(aBone);
    temp->prev = nullptr;
    temp->next = hand;
    endOfHand = hand;
    hand->prev = temp;
    hand = temp;
    handCount++;

    return true;

}



/*
 * Add a bone to the players hand, this will automatically place the new
 * bone at the front of the double linked lst.
 */
void Player::addToHand(const Bone & aBone)
{
    node * temp = new node(aBone);
    addToHand(temp);
}

void Player::addToHand(Player::node *& newBone)
{
    node * curr = hand;
    while(curr && curr->next)
        curr = curr->next;

    newBone->prev = curr;
    curr->next = newBone;
    endOfHand = newBone;
    handCount++;
}

/*
 * Get the last bone in the players hand.
 */
Player::node*& Player::getEnd()
{
    return endOfHand;
}

/*
 * Calculate the total number of points the player currently has.
 */
void Player::getPoints(int &score)
{
    tallyScore(hand, score);
}

/*
 * Recurse the players hand, add up the total of each of the players bones
 * to determine their score.
 */
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

/*
 * Recurse the players hand to display it.
 */
void Player::displayHand()
{
    cout << "Current Hand:" << endl;
    displayHand(hand);
    cout << endl;
}

/*
 * Recurse the players hand to display it
 */
void Player::displayHand(Player::node *head)
{
	static int formatter = 1;
    if(!head)
        return;
    cout << "[ " << head->data->getSideA()
         << "|" << head->data->getSideB() << " ]";
	if(formatter % 5 == 0)
		cout << endl << endl;
	formatter++;
    displayHand(head->next);
}



ostream &operator<<(ostream &out,  Player &aPlayer)
{
    int score = 0;
    int playerNo;
    aPlayer.getPlayerNo(playerNo);
    aPlayer.getPoints(score);
    out << "Player " << playerNo << "\n\t  ";
    aPlayer.displayHand();
    out << "\t Most recently added bone: \n\t ";
    aPlayer.getEnd()->data->printSides();
    out << endl;
	out << "\t Bones in hand: " << aPlayer.handCount
		<< endl;


    return out;
}


void Player::setPlayerNo(const int playerNo)
{
    this->playerNo = playerNo;
}

void Player::getPlayerNo(int & playerNum) const
{
    playerNum = playerNo;
}
