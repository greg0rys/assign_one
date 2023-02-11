#include "DLL.h"

DLL::DLL():head(nullptr),tail(nullptr),listSize(0)
{}


DLL::DLL(const DLL &aCopy):head(nullptr),tail(nullptr),listSize(0)

{
    *this = aCopy;
}

 DLL& DLL::operator=(const DLL &aCopy)
{
    if(this == &aCopy)
        return *this;

    if(isEmpty())
    {
        head = tail = nullptr;
        listSize = aCopy.listSize;
        return *this;
    }

    if(head)
        destroy();

    copyChain(head, aCopy.head);
    tail = getTail();
    listSize = aCopy.listSize;

    return *this;
}


DLL::~DLL()
{
    if(isEmpty())
    {
        head = tail = nullptr;
        initSize = nullptr;
        return;
    }

    destroy();
    head = tail = nullptr;
    initSize = nullptr;

}


void DLL::destroy()
{
    destroyList(head);
}


void DLL::destroyList(DLL::node *& top)
{
    if(!top || isEmpty())
        return;

    destroyList(top->next);
    delete top;
}


void DLL::getCount(int &counter)
{
    if(isEmpty())
    {
        counter = 0;
        return;
    }

    countChain(head, counter);
}


void DLL::getCount(const DLL &list, int &total)
{
    if(isEmpty())
    {
        total = 0;
        return;
    }

    countChain(list.head, total);
}


void DLL::countChain(DLL::node *top, int &counter)
{
    if(!top || isEmpty())
        return;

    countChain(top->next, ++counter);

}


bool DLL::isEmpty()
{
    return head;
}


void DLL::copyChain(DLL::node *& destList, DLL::node * sourceList)
{


    if(!sourceList)
        return;

    destList = new node(*sourceList->data);
    destList->prev = sourceList->prev;

    copyChain(destList->next, sourceList->next);
}


DLL::node* DLL::getHead()
{
    return head;
}


void DLL::setHead(const Bone &aBone)
{
    if(!head)
    {
        head = new node();
        *(head->data) = aBone;
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }

    node * temp = nullptr;
    temp = new node();
    *(temp->data) = aBone;
    head->prev = temp;
    temp->next = head;
    head = temp;

}


DLL::node* DLL::getTail()
{
    auto * curr = head;

    while(curr && curr->next)
        curr = curr->next;

    // special check to make sure that the tail pointer is actually
    // pointing at the last item - if their totals differ set tail to curr
    // which at this point is the end of the list.
    if(curr->data->getBoneTotal() != tail->data->getBoneTotal())
        tail = curr;

    return tail;

}


void DLL::setTail(DLL::node &newTail)
{
    *tail = newTail;
}


void DLL::displayList(DLL::node * top)
{
    if(!top)
        return;

    static int formatter = 1;

    cout << "[ " << top->data->getSideA()
         << "|" << top->data->getSideB() << " ]";

    // use a formatter counter to keep bones in rows of 5
    if(formatter % 5 == 0)
        cout << endl << endl;
    formatter++;

    displayList(top->next);

}



/**
 * playerList implements
 */

playersDLL::playersDLL(): recentDraw(nullptr),handCount(0),DLL()
{
}

// what will happen is the base class will call its copy constructor
// to copy the dynamic list the playersDll is

// then we can just use the playersDLL copy constructor to handle the
// elements that pretain to the playersDLL
playersDLL::playersDLL(const playersDLL &playersHand): recentDraw(nullptr),
                                                       handCount(0),
                                                       DLL(playersHand)
{
    *this = playersHand;
}


playersDLL& playersDLL::operator=(const playersDLL &aPlayersHand)
{
    if(this == &aPlayersHand)
        return *this;

    int copiesHand = 0;

    if(aPlayersHand.recentDraw)
    {
        if(recentDraw)
            delete recentDraw;
        recentDraw = nullptr;
        recentDraw = new Bone(*aPlayersHand.recentDraw);
    }
    else
    {
        recentDraw = nullptr;
    }

    getCount(aPlayersHand, copiesHand); // count the number in the players
    handCount = copiesHand;

    return *this;

}

playersDLL::~playersDLL()
{
    if(recentDraw)
        delete recentDraw;

    recentDraw = nullptr;
    handCount = 0;

}



void playersDLL::display()
{
    /* have client program check for empty before calling this*/
    displayList(getHead());
}


void playersDLL::displayList(DLL::node * start)
{
    if(!start || isEmpty())
        return;
    cout << start->data << " ";
    // use the ref to the last bone in the hand to display it.
    recentDraw->printSides();
    cout << endl;

}


DLL::node* playersDLL::findDouble(DLL::node * start)
{
    if(!start)
        return nullptr;

    if(start->data->isDouble())
        return start;

    if(start->next->data->isDouble())
        return start->next;

    // skip forward two each iteration, so we can check two nodes at once.
    findDouble(start->next->next);
}


void playersDLL::getPoints(int &pointTotal)
{
    getPoints(getHead(),pointTotal);
}


void playersDLL::getPoints(DLL::node * top, int &points)
{
    if(!top)
        return;
    points += top->data->getBoneTotal();
    getPoints(top->next, points);
}


