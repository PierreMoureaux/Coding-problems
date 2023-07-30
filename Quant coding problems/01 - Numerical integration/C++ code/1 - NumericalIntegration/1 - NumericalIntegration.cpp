#include <iostream>
#include "RectangleRule.h"
#include "TrapezoidalRule.h"
#include <numeric>
#include <cmath>
#include <sciplot/sciplot.hpp>
#include <valarray>

using namespace sciplot;

double square(double x) { return x * x; }
double spline(double x) { return x * x * x; }

int main()
{
    double minRange{ -50.0 };
    double maxRange{ 40.0 };
    int nbBins{ 100 };
    auto exactSquare{(pow(maxRange,3)- pow(minRange,3))/3.0};
    auto exactCubic{ (pow(maxRange,4) - pow(minRange,4)) / 4.0 };

    //1 - Main program taking into account max nbBins
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

    //2 - Error paths and visualization
    std::vector<int> vecnbBins(nbBins);
    std::iota(std::begin(vecnbBins), std::end(vecnbBins), 0);

    std::vector<double> errorSquareRectangeleRule;
    std::vector<double> errorSquareTrapezoidalRule;
    std::vector<double> errorSplineRectangeleRule;
    std::vector<double> errorSplineTrapezoidalRule;

    for (auto i : vecnbBins)
    {
        RectangleRule integrandRec1(minRange, maxRange, i+1);
        errorSquareRectangeleRule.emplace_back(abs(integrandRec1.integrand(square) - exactSquare));

        TrapezoidalRule integrandRec2(minRange, maxRange, i+1);
        errorSquareTrapezoidalRule.emplace_back(abs(integrandRec2.integrand(square) - exactSquare));

        RectangleRule integrandRec3(minRange, maxRange, i+1);
        errorSplineRectangeleRule.emplace_back(abs(integrandRec3.integrand(spline) - exactCubic));

        TrapezoidalRule integrandRec4(minRange, maxRange, i+1);
        errorSplineTrapezoidalRule.emplace_back(abs(integrandRec4.integrand(spline) - exactCubic));
    }

    Vec x = linspace(0, nbBins, nbBins);
    Plot2D plot;

    plot.xlabel("Bins");
    plot.ylabel("errorSquareRectangeleRule");

    plot.xrange(0.0, nbBins);
    plot.yrange(0.0, 700000);

    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    plot.drawCurve(x, errorSquareRectangeleRule).label("Error = f(nbBins)");

    Figure fig = { {plot} };
    Canvas canvas = { {fig} };
    canvas.show();
}
