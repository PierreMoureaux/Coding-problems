#include "TrapezoidalRule.h"

double TrapezoidalRule::integrand(std::function<double(double)> func) const
{
	auto res{ 0.0 };
	auto i{ minRange };
	while (i <= maxRange)
	{
		auto firstPoint{ func(i) };
		auto secondPoint{ func(i+ discreteStep) };
		if (firstPoint <= secondPoint)
		{
			res += firstPoint * discreteStep + discreteStep * (secondPoint - firstPoint) / 2.0;
		}
		else
		{
			res += secondPoint * discreteStep + discreteStep * (firstPoint - secondPoint) / 2.0;
		}
		i += discreteStep;
	}
	return res;
}
