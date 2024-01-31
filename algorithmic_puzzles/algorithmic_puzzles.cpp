
#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList myList{1,2,3,4,5};
    myList.insert_at_k(3, 6);

    std::cout << myList;
    return 0;
}

