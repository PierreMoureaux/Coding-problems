// PiMonteCarlo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

auto distanceToZero(auto x, auto y)
{
    return sqrt(pow(x,2) + pow(y, 2));
}

auto PiMonteCarlo(int NbSimul)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    auto c{ 0.0 };
    for (auto i = 0; i != NbSimul; i++)
    {
        auto x = dis(gen);
        auto y = dis(gen);
        auto d = distanceToZero(x, y);
        if (d <= 1)
        {
            c++;
        }
    }
    return 4*c / NbSimul;
}

int main()
{
    auto NbSimul{ 1000000 };
    std::cout << std::setprecision(4) << PiMonteCarlo(NbSimul) << std::endl;
}
