#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>

/*Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].*/

template <class T>
int getIndex(const std::vector<T>& v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    else
    {
        return 1;
    }
}

template <class T >
auto f(const std::vector<T>& vec)
{
    int s = vec.size();
    std::vector<T> res;
    typename std::vector<T>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        if (it == vec.begin())
        {
            typename std::vector<T>::const_iterator it_forward = it;
            ++it_forward;
            auto temp = std::accumulate(it_forward, it_forward + (s - 1),1, std::multiplies<T>{});
            res.emplace_back(temp);
        }
        else if (it == vec.end() - 1)
        {
            typename std::vector<T>::const_iterator it_backward = it;
            auto temp = std::accumulate(--it_backward - (s-2), it_backward,1, std::multiplies<T>{});
            res.emplace_back(temp);
        }
        else
        {
            typename std::vector<T>::const_iterator it_forward = it;
            typename std::vector<T>::const_iterator it_backward = it;
            ++it_forward;
            auto index = getIndex(vec, *it);
            auto temp1 = std::accumulate(it_forward, it_forward + (s - index - 1),1, std::multiplies<T>{});
            auto temp2 = std::accumulate(--it_backward - (index-1), it_backward,1, std::multiplies<T>{});
            auto temp3 = temp1 * temp2;
            res.emplace_back(temp3);
        }
    }
    return res;
}

int main()
{
    std::vector<double> vec{ 1, 2, 3, 4, 5 };
    std::vector<double> vec2{ 3, 2, 1};
    auto res = f(vec);
    auto res2 = f(vec2);
    for (auto i : res)
    {
        std::cout << i << std::endl;
    }
    for (auto i : res2)
    {
        std::cout << i << std::endl;
    }
}
