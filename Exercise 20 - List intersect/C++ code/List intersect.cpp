#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

//version with multiple intersect and storage
template <class T>
auto listIntersectMultiple(const std::list<T>& l1, const std::list<T>& l2)
{
    std::vector<T> res;
    for (auto it : l1)
    {
        if (std::find(l2.begin(), l2.end(), it) != l2.end())
        {
            res.emplace_back(it);
        }
    }
    return res;
}

//version with first touch intersect
template <class T>
auto listIntersect(const std::list<T>& l1, const std::list<T>& l2)
{
    for (auto it : l1)
    {
        if (std::find(l2.begin(), l2.end(), it) != l2.end())
        {
            return it;
        }
    }
    return -1;
}

int main()
{
    std::list<int> l1{ 3, 7 , 8 , 99 };
    std::list<int> l2{ 99, 1 , 8 , 10 };
    auto res = listIntersectMultiple(l1, l2);
    for (auto i : res)
    {
        std::cout << i << std::endl;
    }
    std::cout << listIntersect(l1, l2) << std::endl;
}
