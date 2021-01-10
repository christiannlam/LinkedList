#include <iostream>
#include "ModernLinkedList.h"
using namespace std;
int main() {
    ModernLinkedList list;
    list.PushFront(5);
    list.PushFront(4);
    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(1);
    cout << "Making LinkedList: " << endl;
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nRemoving Last Two Elements: " << endl;
    list.PopBack();
    list.PopBack();
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nAdding Back Last Two Elements Removed: " << endl;
    list.PushBack(4);
    list.PushBack(5);
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nClearing List: " << endl;
    list.Clear();
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(1);
    cout << "\nMaking LinkedList: " << endl;
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nPop Front: " << endl;
    list.PopFront();
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nClearing List: " << endl;
    list.Clear();
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    list.PushFront(5);
    list.PushFront(4);
    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(1);
    cout << "\nMaking LinkedList: " << endl;
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nInsert at Index 3: " << endl;
    list.Insert(3,6);
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nInsert at Index 0: " << endl;
    list.Insert(0,7);
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nInsert at Index 6: " << endl;
    list.Insert(6,8);
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nClearing List: " << endl;
    list.Clear();
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    list.PushFront(5);
    list.PushFront(4);
    list.PushFront(3);
    list.PushFront(2);
    list.PushFront(1);
    cout << "\nMaking LinkedList: " << endl;
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nRemoving at Index 0: " << endl;
    list.RemoveAt(0);
    list.PrintList();
    cout << "Size: " << list.Size() << endl;

    cout << "\nRemoving at Index 2: " << endl;
    list.RemoveAt(2);
    list.PrintList();
    cout << "Value you index 1: " << list[1] << endl;
    cout << "Size: " << list.Size() << endl;

}