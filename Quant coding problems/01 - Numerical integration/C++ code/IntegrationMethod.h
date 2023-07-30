#pragma once
#include <functional>

class IntegrationMethod
{
public:
	IntegrationMethod(double _minRange, double _maxRange, int _nbBins);
	virtual double integrand(std::function<double(double)> func) const = 0;

protected:
	double minRange;
	double maxRange;
	int nbBins;
	double discreteStep;
};

