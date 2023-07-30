
from abc import ABC, abstractmethod
import numpy as np
import matplotlib.pyplot as plt

class IntegrationMethod(ABC):
    def __init__(self, _minRange, _maxRange, _nbBins):
        self.minRange = _minRange
        self.maxRange = _maxRange
        self.nbBins = _nbBins
        self.discreteStep = (self.maxRange - self.minRange) / self.nbBins
    
    @abstractmethod
    def integrand(self, func):
        pass
    
class RectangleRule(IntegrationMethod):
    def integrand(self, func):
        res = 0.0
        i = self.minRange
        while i <= self.maxRange:
            midPoint = i + self.discreteStep/2.0
            res = res + func(midPoint) * self.discreteStep
            i = i + self.discreteStep
        return res

class TrapezoidalRule(IntegrationMethod):
    def integrand(self, func):
        res = 0.0
        i = self.minRange
        while i <= self.maxRange:
            firstPoint = func(i)
            secondPoint = func(i + self.discreteStep)
            if firstPoint <= secondPoint:
                res = res + firstPoint * self.discreteStep + self.discreteStep * (secondPoint - firstPoint) / 2.0
            else:
                res = res + secondPoint * self.discreteStep + self.discreteStep * (firstPoint - secondPoint) / 2.0
            i = i + self.discreteStep
        return res

def square(x):
    return x * x
def spline(x):
    return x * x * x

minRange = -50.0
maxRange = 40.0
nbBins = 100
exactSquare = (maxRange**3- minRange**3)/3.0
exactCubic = (maxRange**4- minRange**4)/4.0

#1 - Main program taking into account max nbBins
integrandRec1 = RectangleRule(minRange, maxRange, nbBins)
print("numerical integration using rectangle rule" + " " + str(integrandRec1.integrand(square)))
print("exact integration" + " " + str(exactSquare))

integrandRec2 = TrapezoidalRule(minRange, maxRange, nbBins)
print("numerical integration using trapezoidal rule" + " " + str(integrandRec2.integrand(square)))
print("exact integration" + " " + str(exactSquare))

integrandRec3 = RectangleRule(minRange, maxRange, nbBins)
print("numerical integration using rectangle rule" + " " + str(integrandRec3.integrand(spline)))
print("exact integration" + " " + str(exactCubic))

integrandRec4 = TrapezoidalRule(minRange, maxRange, nbBins)
print("numerical integration using trapezoidal rule" + " " + str(integrandRec4.integrand(spline)))
print("exact integration" + " " + str(exactCubic))

#2 - Error paths and visualization
errorSquareRectangeleRule = np.zeros(nbBins)
errorSquareTrapezoidalRule = np.zeros(nbBins)
errorSplineRectangeleRule = np.zeros(nbBins)
errorSplineTrapezoidalRule = np.zeros(nbBins)

for  i in range(0,nbBins):
    integrandRec1 = RectangleRule(minRange, maxRange, i+1)
    errorSquareRectangeleRule[i] = np.abs(integrandRec1.integrand(square) - exactSquare)

    integrandRec2 = TrapezoidalRule(minRange, maxRange, i+1)
    errorSquareTrapezoidalRule[i] = np.abs(integrandRec2.integrand(square) - exactSquare)
    
    integrandRec3 = RectangleRule(minRange, maxRange, i+1)
    errorSplineRectangeleRule[i] = np.abs(integrandRec3.integrand(spline) - exactSquare)
    
    integrandRec4 = TrapezoidalRule(minRange, maxRange, i+1)
    errorSplineTrapezoidalRule[i] = np.abs(integrandRec4.integrand(spline) - exactSquare)
 
plt.plot(range(0,nbBins), errorSquareRectangeleRule)
plt.xlabel('Bins')
plt.ylabel('Absolute error')
plt.title('errorSquareRectangeleRule')
plt.show()