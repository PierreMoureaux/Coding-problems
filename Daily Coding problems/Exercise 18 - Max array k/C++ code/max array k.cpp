#include <iostream>
#include <vector>
#include <algorithm>

//version with storing results
auto MaxArrayK(const std::vector<int>& vec, int k)
{
    std::vector<int> res;
    for (auto it = vec.begin(); it != vec.end() - k + 1; it++)
    {
        auto it2{ it };
        res.emplace_back(*(std::max_element(it2, it2 + k)));
    }
    return res;
}

//version with print
auto MaxArrayK2(const std::vector<int>& vec, int k)
{
    for (auto it = vec.begin(); it != vec.end() - k + 1; it++)
    {
        auto it2{ it };
        std::cout << *(std::max_element(it2, it2 + k)) << std::endl;
    }
}

int main()
{
    std::vector<int> vec{ 10, 5, 2, 7, 8, 7 };
    auto res = MaxArrayK(vec, 3);
    for (auto i : res)
    {
        std::cout << i << std::endl;
    }
    MaxArrayK2(vec, 3);
}
