#include "ChickenYard.h"
/**
 * ChickenYard.cpp the implementation file for ChickenYard.h
 * @author Greg Shenefelt
 * @version 0.0.4
 */


// default constructor
ChickenYard::ChickenYard()
        : boneYard(nullptr), boneCount(INIT_SIZE), shuffled(false) {

    yardArray = makeArray();
    boneCount = INIT_SIZE;

    printYardArr();
    shuffleBones();
    shuffled = !shuffled;

    generateYard();
    printList();
}

/*
 * Create the bone yard as an array initially of 52 bones
 * Return: an std::array container of 52 bone objects.
 */
std::array<Bone, 52> ChickenYard::makeArray() const {

    // when generating the list we will need to recurse to link the ptrs
    std::array<Bone, 52> bones{};

    for (auto x = 0; x < INIT_SIZE; x++) {
        Bone temp;
        bones[x] = temp;
    }

    return bones;
}

/*
 * Shuffle the array of bones using the std::shuffle method
 * To generate a random index for each object I made use of the
 * std::default_random_engine
 */
void ChickenYard::shuffleBones() {

    auto range = std::default_random_engine{};
    shuffle(yardArray.begin(), yardArray.end(), range);
}

/*
 * Turn the yard from an array of bones to a linked list of bones
 * This method calls the recursive version of itself to complete the task.
 */
void ChickenYard::generateYard() {

    int counter = 0;
    generateYard(boneYard, counter);
}

/*
 * Recurse of the std::array structure to create a linked list of all the
 * bones in the boneYard;
 * Params: node *& a pointer reference to the head of the linked list
 *         std::array & a reference to the array of bones.
 *         int & a reference to an int which is used to both access the object
 *         stored at each index of the array and is also used as the
 *         recursive stopping point, so we don't overflow the bounds of the
 *         yardArray
 */
void ChickenYard::generateYard(node *&curr, int &counter) {
    Bone *temp = nullptr;

    if (counter == INIT_SIZE)
        return;

    temp = new Bone(yardArray[counter]);
    curr = new node();
    curr->data = temp;
    curr->next = nullptr;
    generateYard(curr->next, ++counter);
}

/*
 * Copy constructor to make deep copies of chickenYard objects
 */
ChickenYard::ChickenYard(const ChickenYard &aYard)
        : boneYard(nullptr), boneCount(0), shuffled(false) {
    *this = aYard;
}
/*
 * Overloaded operator= to create deep copies of all chickenYard objects
 * when created via = assignment.
 */
ChickenYard &ChickenYard::operator=(const ChickenYard &aYard) {
    if (this == &aYard)
        return *this;

    if (boneYard)
        destroy();

    boneCount = aYard.boneCount;
    shuffled = aYard.shuffled;

    boneYard = new node();

    copyChain(boneYard, aYard.boneYard);

    return *this;
}

/*
 * Class destructor
 */
ChickenYard::~ChickenYard() { destroy(); }

/*
 * Deallocate dynamic memory allocations
 */
void ChickenYard::destroy() {
    destroy(boneYard);
    boneYard = nullptr;
}

/*
 * Recursively free all pointers being stored in the linked list
 * Param: node *& a pointer reference to the head of the list.
 */
void ChickenYard::destroy(node *&aBone) {
    if (!aBone)
        return;
    destroy(aBone->next);
    delete aBone;
}


void ChickenYard::getHand(Player *& aPlayer)
{
    if(!boneYard || !aPlayer->isFirstHand())
        return;

    node * curr = boneYard;
    for(auto x = 0; x < HAND_SIZE; x++)
    {
        node * temp = curr->next;
        aPlayer->setHand(*curr->data);
        removeFromList(curr);
        curr = temp;
    }

    aPlayer->setFirstHand(false);

    boneYard = curr;
}


bool ChickenYard::draw(Bone &aBone)
{
    if(isEmpty())
        return isEmpty();
    aBone = *boneYard->data;
    removeFromList(boneYard);
    return true;
}

// helper functions

// check if the chickenYards linked list is empty
bool ChickenYard::isEmpty() const { return boneYard == nullptr; }

// get a total count of all bones in the boneYard linked list.
int ChickenYard::getCount() { return getCount(boneYard); }

// print the array of bones to show shuffle.
void ChickenYard::printYardArr() {
    if (!shuffled)
        cout << "Here's the bones before shuffle! " << endl;

    for (auto x = 0; x < INIT_SIZE; x++) {
        cout << x + 1 << " [ " << yardArray[x].getSideA()
             << " | " << yardArray[x].getSideB() << " ]\t";
        if(x % 5 == 0)
            cout << endl << endl;
    }

    cout << endl << endl;
    cout << "    \t\t\t***********************************    " << endl;
    cout << "    \t\t\tHere's the bones after the shuffle:    " << endl;
    cout << "    \t\t\t***********************************    " << endl;
}

void ChickenYard::printList() { printList(boneYard);
    cout << endl;}

// end helper functions

// ****************************************** //

// recursive helper functions

/*
 * Recursively count all nodes in the linked list
 * Param node* a pointer to the head of this linked list.
 */
int ChickenYard::getCount(ChickenYard::node *yard) const {
    if (!yard)
        return 0;

    return 1 + getCount(yard->next);
}

/*
 * Recursively copy all nodes in a linked list to create deep copies.
 */
void ChickenYard::copyChain(node *&head, node *copy) {
    if (!copy)
        return;
    head = new node(*copy->data);

    copyChain(head->next, copy->next);
}

void ChickenYard::printList(node *head) {
    static int pos = 1;
    if (!head)
        return;
    cout << pos++ ; // do pos++ here and will use the value and then
    // increment it for the next iteration.
    head->data->printSides();
    if(pos % 5 == 0)
        cout << endl << endl;

    printList(head->next);
}


void ChickenYard::removeFromList(ChickenYard::node *& target)
{
    node * curr = target->next;
    delete target;
    target = curr;
    boneCount--;
}

// end recursive implementations