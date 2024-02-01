
#include <iostream>
#include "Arrays.h"
#include <vector>

int main()
{
    std::vector<int> A{ 9,8,7,6,5,4,3,1 };
    //std::vector<std::vector<int>> results{};

    qs(A, 0, A.size() - 1);

    std::cout << A;
    return 0;
}

