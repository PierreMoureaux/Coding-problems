/*Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
auto f(const std::vector<T>& vec, T index)
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        auto k = index - (*i);
        auto j = i;
        if (std::find(++j, end(vec), k) != end(vec))
        {
            return true;
        }
    }
    return false;
}


int main()
{
    std::vector<double> vec{ 10,15,3,7 };
    auto index{ 17. };
    auto index2{ 19. };
    std::cout << f(vec, index) << std::endl;
    std::cout << f(vec, index2) << std::endl;
}
