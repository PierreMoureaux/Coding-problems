# -*- coding: utf-8 -*-
"""
Created on Mon Jun 19 22:22:30 2023

@author: moure
"""

import numpy as np

def f(vec):
    s = vec.size
    res = np.zeros(s)
    for i in range(s):
        res[i] = np.prod(vec[:i])*np.prod(vec[i+1:])
    return res;

vec = np.array([ 1, 2, 3, 4, 5 ])
vec2 = np.array([3, 2, 1])
res = f(vec)
res2 = f(vec2)
for i in res:
    print(i)
for i in res2:
    print(i)