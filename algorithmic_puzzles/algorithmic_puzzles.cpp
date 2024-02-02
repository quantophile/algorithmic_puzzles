
#include <iostream>
#include "Arrays.h"
#include <vector>

int main()
{
    std::vector<int> A{ 2,3,6,7 };
    int target = 7;
    std::vector<std::vector<int>> results{};
    vector<int> ds{};
    findCombinations(0, ds, target, A, results);

    std::cout << A;
    return 0;
}

