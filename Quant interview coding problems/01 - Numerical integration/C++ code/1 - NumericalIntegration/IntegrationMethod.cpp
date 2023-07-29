#include "IntegrationMethod.h"

IntegrationMethod::IntegrationMethod(double _minRange, double _maxRange, int _nbBins)
{
	minRange = _minRange;
	maxRange = _maxRange;
	nbBins = _nbBins;
	discreteStep = (maxRange - minRange) / nbBins;
}
