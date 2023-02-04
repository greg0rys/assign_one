#include "DLL.h"

DLL::DLL():head(nullptr),tail(nullptr),initSize(nullptr),listSize(0)
{}


DLL::DLL(const DLL &aCopy):head(nullptr),tail(nullptr),initSize(nullptr),
                          listSize(0)
{
    *this = aCopy;
}

 DLL& DLL::operator=(const DLL &aCopy)
{
    if(this == &aCopy)
        return *this;

    if(head)
        destroy();

    if(isEmpty())
    {
        head = nullptr;
        tail = nullptr;
        initSize = nullptr;
        listSize = aCopy.listSize;
        return *this;
    }

    copyChain(head, aCopy.head);
    tail = getTail();
    initSize = aCopy.getType(); // have each list share its type;
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


void DLL::countChain(DLL::node *top, int &counter)
{
    if(!top || isEmpty())
        return;

    countChain(top->next, ++counter);

}


bool DLL::isEmpty()
{
    return head == nullptr;
}


void DLL::copyChain(DLL::node *& destList, DLL::node * sourceList)
{


    if(!sourceList)
    {
        if(sourceList->prev)
            tail = sourceList->prev;
        else
            tail = nullptr;
        return;

    }

    if(destList)
        delete destList;

    destList = new node(*sourceList->data);
    destList->prev = sourceList->prev;

    copyChain(destList->next, sourceList->next);
}


DLL::node* DLL::getHead()
{
    return head;
}


void DLL::setHead(DLL::node &newHead)
{
    *head = newHead;
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




