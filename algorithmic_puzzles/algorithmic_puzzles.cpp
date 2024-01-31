
#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList lst1{ 1,3,5,7 };
    LinkedList lst2{ 2,4,6,8,9 };
    LinkedList lst3 = merge_two_lists(lst1,lst2);

    std::cout << lst3;

    return 0;
}

