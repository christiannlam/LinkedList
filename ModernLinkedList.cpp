#include "ModernLinkedList.h"
#include <memory>
#include <iostream>
using namespace std;

void ModernLinkedList::PushBack(int value) {
    auto newNode = make_unique<Node>(value);
    Node* temp = mHead.get();
    while (temp->mNext != nullptr) {
        temp = temp->mNext.get();
    }
    temp->mNext = move(newNode);
    temp->mNext->mNext = move(nullptr);
    mSize++;
}
void ModernLinkedList::PushFront(int value) {
    auto newNode = std::make_unique<Node>(value);
    // Any time we change a link, we must use std::move.
    newNode->mNext = std::move(mHead);

    // Transfer ownership of this new head node to the List object.
    mHead = std::move(newNode);

    // Increase the size by 1.
    mSize++;
}

void ModernLinkedList::Insert(int index, int value) {
    auto newNode = make_unique<Node>(value);
    Node* temp = mHead.get();
    int indexCounter = 0;
    if(mSize == 0)
    {
        mHead = move(newNode);
        mSize++;
    }
    if(index == 0)
    {
        newNode->mNext = move(mHead);
        mHead = move(newNode);
        mSize++;

    }
    else{
        while(indexCounter != index - 1)
        {
            temp = temp->mNext.get();
            indexCounter++;
        }
        newNode->mNext = move(temp->mNext);
        temp->mNext= move(newNode);
        mSize++;
    }



}

void ModernLinkedList::RemoveAt(int index) {
    Node* temp = mHead.get();
    int indexCounter = 0;
    if( index == 0)
    {
        mHead = move(temp->mNext);
        mSize--;
    }
    else
    {
        while(index != 0)
        {
            if(indexCounter == index - 1)
            {
                temp->mNext = move(temp->mNext->mNext);
                break;
            }
            temp = temp->mNext.get();
            indexCounter++;
        }
        mSize--;
    }
}

void ModernLinkedList::Clear(){
    mHead = move(nullptr);
    mSize = 0;
}

void ModernLinkedList::PopFront() {
    Node* temp = mHead.get();
    mHead = move(temp->mNext);
    mSize--;
}

void ModernLinkedList::PrintList() const {
    // To walk this list, we need to create a temp that points to the head node, and then gets moved
    // to the next, to the next, etc. This temp does not want to claim ownership of any of these nodes,
    // so it can't be a unique_ptr. A "raw" Node pointer will let us "use" each Node's values without
    // having to be an owner of that memory.

    cout << "[";
    Node* temp = mHead.get(); // reminder: a unique_ptr's .get() gives us back the raw pointer.
    // As long as the Node that temp points to is not null.
    while (temp != nullptr) {
        if (temp != mHead.get()) {
            // Separate each element with a comma.
            cout << ", ";
        }
        cout << temp->mData;
        temp = temp->mNext.get();
    }
    cout << "]" << endl;
}

void ModernLinkedList::PopBack() {
    if (mSize == 1) {
        // Set head to nullptr, which destroys the only remaining node.
        // Reminder: to change ownership, use std::move.
        mHead = std::move(nullptr);
        mSize = 0;
    }
    else {
        // First walk to the second-to-last node in the list.
        // See PrintList().
        Node* temp = mHead.get();
        while (temp->mNext->mNext != nullptr) {
            temp = temp->mNext.get();
        }

        // If temp's next's next is null, then temp is the second to last node.
        // temp's next must now be set to null, which will destroy what used to be last.
        temp->mNext = std::move(nullptr);
        mSize--;
    }
}

int& ModernLinkedList::operator[](int index) {
    Node* temp = mHead.get();
    for(int i = 0; i < mSize; i++)
    {
        if(i == index)
        {
            return temp->mData;
        }
        temp = temp->mNext.get();
    }
}


