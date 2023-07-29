#include <iostream>
#include "RectangleRule.h"
#include "TrapezoidalRule.h"

double square(double x) { return x * x; }
double spline(double x) { return x * x * x; }

int main()
{
    double minRange{ -50.0 };
    double maxRange{ 50.0 };
    int nbBins{ 1000000 };
    auto exactSquare{(pow(maxRange,3)- pow(minRange,3))/3.0};
    auto exactCubic{ (pow(maxRange,4) - pow(minRange,4)) / 4.0 };

    RectangleRule integrandRec(minRange, maxRange, nbBins);
    std::cout << "numerical integration using rectangle rule " << integrandRec.integrand(square) << std::endl;
    std::cout << "exact integration "  << exactSquare <<  std::endl;

    TrapezoidalRule integrandTrap(minRange, maxRange, nbBins);
    std::cout << "numerical integration using trapezoidal rule " << integrandTrap.integrand(square) << std::endl;
    std::cout << "exact integration " << exactSquare << std::endl;

    RectangleRule integrandRec2(minRange, maxRange, nbBins);
    std::cout << "numerical integration using rectangle rule " << integrandRec2.integrand(spline) << std::endl;
    std::cout << "exact integration " << exactCubic << std::endl;

    TrapezoidalRule integrandTrap2(minRange, maxRange, nbBins);
    std::cout << "numerical integration using trapezoidal rule " << integrandTrap2.integrand(spline) << std::endl;
    std::cout << "exact integration " << exactCubic << std::endl;
}
