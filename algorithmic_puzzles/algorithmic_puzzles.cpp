
#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList myList{};
    myList.push_front(2);
    myList.push_front(1);

    std::cout << myList;
    return 0;
}

