"""Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17."""

import numpy as np

def f(vec, index):
    for idx,i in enumerate(vec):
        k = index - i;
        j = idx+1;
        if (k in vec[j:]):
            return True
    return False

vec = np.array([10,15,3,7])
index = 17.
index2 = 19.
print(f(vec, index))
print(f(vec, index2))

