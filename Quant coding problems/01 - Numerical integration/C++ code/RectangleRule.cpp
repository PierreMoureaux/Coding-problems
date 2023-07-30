#include "RectangleRule.h"

double RectangleRule::integrand(std::function<double(double)> func) const
{
	auto res{ 0.0 };
	auto i{ minRange };
	while (i <= maxRange)
	{
		auto midPoint{ i + discreteStep/2.0 };
		res += func(midPoint) * discreteStep;
		i += discreteStep;
	}
	return res;
}