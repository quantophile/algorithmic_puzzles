
#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList myList{1,2};
    myList.delete_at_k(1);


    std::cout << myList;
    return 0;
}

