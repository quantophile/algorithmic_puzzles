
#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList num1{ 9,9,9,9,9,9,9 };
    LinkedList num2{ 9,9,9,9 };
    LinkedList num3 = num1 + num2;

    std::cout << num3;
    return 0;
}

