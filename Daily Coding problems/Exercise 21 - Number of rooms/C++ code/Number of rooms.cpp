
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef std::vector<std::tuple<int, int>> timeRange;

auto NumberOfRooms(const timeRange& t)
{
    if (!t.empty())
    {
        auto tCopy{ t };
        auto c{ 1 };
        auto minRange = std::min_element(tCopy.begin(), tCopy.end(),
            [](const std::tuple<int, int>& x,
                const std::tuple<int, int>& y) {
                    return std::get<0>(x) < std::get<0>(y);
            });
        auto UpperTime = std::get<1>(*minRange);
        tCopy.erase(minRange);
        while (!tCopy.empty())
        {
            auto minRange = std::min_element(tCopy.begin(), tCopy.end(),
                [](const std::tuple<int, int>& x,
                    const std::tuple<int, int>& y) {
                        return std::get<0>(x) < std::get<0>(y);
                });
            auto lowerTimeLoop = std::get<0>(*minRange);
            auto UpperTimeLoop = std::get<0>(*minRange);
            if (lowerTimeLoop <= UpperTime)
            {
                c++;
            }
            if (UpperTimeLoop >= UpperTime)
            {
                UpperTime = UpperTimeLoop;
            }
            tCopy.erase(minRange);
        }
        return c;
    }
    else
    {
        return -1;
    }
}

int main()
{
    auto a1 = std::make_tuple(0, 50);
    auto a2 = std::make_tuple(30, 42);
    auto a3 = std::make_tuple(45, 160);
    timeRange t{ a1,a2,a3 };
    std::cout << NumberOfRooms(t) << std::endl;

    auto a4 = std::make_tuple(0, 50);
    auto a5 = std::make_tuple(30, 42);
    auto a6 = std::make_tuple(60, 160);
    timeRange t2{ a4,a5,a6 };
    std::cout << NumberOfRooms(t2) << std::endl;
}



