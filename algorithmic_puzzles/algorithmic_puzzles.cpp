
#include <iostream>
#include "Arrays.h"
#include <vector>

int main()
{
    std::vector<int> vect{ 1,2,3,4,5,6,7 };

    int x = find(vect, 4);

    return 0;
}

