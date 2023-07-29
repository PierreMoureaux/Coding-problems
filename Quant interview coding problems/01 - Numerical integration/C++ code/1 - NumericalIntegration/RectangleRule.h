#pragma once
#include <functional>
#include "IntegrationMethod.h"

class RectangleRule : public IntegrationMethod
{
public:
	using IntegrationMethod::IntegrationMethod;
	virtual double integrand(std::function<double(double)> func) const;
};

